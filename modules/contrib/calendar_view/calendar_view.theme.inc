<?php

/**
 * @file
 * Contains templates-related functions for calendar_view.module.
 */

use Drupal\calendar_view\Plugin\views\style\CalendarViewInterface;
use Drupal\Core\Render\Element;
use Drupal\Core\Url;

/**
 * Prepares variables for Calendar views rows templates.
 *
 * Default template: views-view-calendar.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - view: The view object.
 *   - rows: An array of row items. Each row is an array of content.
 *
 * @see template_preprocess_views_view_unformatted()
 */
function template_preprocess_views_view_calendar(array &$variables) {
  // Default implementation to add default attributes on rows.
  template_preprocess_views_view_unformatted($variables);

  $view = $variables['view'];
  if (($style = $view->getStyle()) instanceof CalendarViewInterface) {
    foreach ($style->options as $key => $value) {
      if (strpos($key, 'calendar_') === 0) {
        $variables['options'][str_replace('calendar_', '', $key)] = $value;
      }
    }
  }

  // Exposed calendar render arrays to Twig.
  $variables['calendars'] = $view->calendars;
}

/**
 * Prepares variables for a Calendar day template.
 *
 * Default template: calendar-view-day.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - children: The view results for this day.
 *   - timestamp: The day timestamp.
 *   - date_format
 *   - date_pattern.
 */
function template_preprocess_calendar_view_day(array &$variables) {
  $elements = $variables['elements'];
  $view = $elements['#view'];

  // Expose this day's timestamp for easier theming in Twig.
  $variables['timestamp'] = $elements['#timestamp'] ?? NULL;

  // Automatically cast variables from the Calendar plugin to content.
  // Empty by default but might be helpful later if a Calendar style arbitrary
  // passes something into ['#theme' => 'calendar_view_day'].
  foreach (Element::children($elements) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

  $list = [];
  foreach ($elements['#children'] ?? [] as $timestamp => $results) {
    foreach ($results as $result) {
      $values = $result['#values'] ?? [];
      unset($result['#values']);

      // Fake preprocessing of result rows to mimic Views.
      // See issue: https://www.drupal.org/project/calendar_view/issues/3295385.
      $renderable = [];
      $renderable['view'] = $view;
      // Get original index so Views generate tokens correctly.
      // See issue: https://www.drupal.org/project/calendar_view/issues/3356693.
      $index = $result['#row']->index ?? 0;
      $renderable['rows'] = [];
      $renderable['rows'][$index] = $result;
      template_preprocess_views_view_unformatted($renderable);
      $row = reset($renderable['rows']);

      $row['#values'] = $values;

      // Helpful information on hover.
      $row['attributes']->setAttribute('title', $values['title'] ?? NULL);

      // Unique identifier for each event.
      $row['attributes']->setAttribute('data-calendar-view-hash', $values['hash'] ?? NULL);

      $list[] = $row;
    }
  }

  // Sort events in each cells to keep order of multiday events.
  if (count($list) > 1) {
    usort($list, function ($row1, $row2) {
      $instance1 = $row1['#values']['first_instance'] ?? NULL;
      $instance2 = $row2['#values']['first_instance'] ?? NULL;
      return $instance1 <=> $instance2;
    });
  }

  // Expose ordered results to Twig now.
  // Use this in your own template_preprocess_calendar_view_day().
  // @see calendar_view_multiday_preprocess_calendar_view_day().
  $variables['rows'] = $list;
}

/**
 * Prepares variables for calendar navigation templates.
 *
 * Default template: calendar-view-pager.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - parameters: An associative array containing:
 *     - timestamp: the moment selected by user.
 *     - calendars: A list of year/month.
 *     - month_before: month before timestamp.
 *     - month_current: month of the timestamp.
 *     - month_after: month after the timestamp.
 *
 * @todo Add options to set limits in past/future navigation.
 */
function template_preprocess_calendar_view_pager(array &$variables) {
  $parameters = $variables['parameters'] ?? [];
  $previous = $parameters['previous'] ?? NULL;
  $current = $parameters['current'] ?? NULL;
  $next = $parameters['next'] ?? NULL;

  /** @var \Drupal\views\ViewExecutable|null */
  $view = $variables['view'] ?? NULL;
  $route_name = !$view || !empty($view->live_preview) ? '<current>' : '<none>';

  $date_formatter = \Drupal::service('date.formatter');
  $date_format = $parameters['date_format'] ?? 'custom';
  $date_pattern = $parameters['date_pattern'] ?? 'F';

  $use_previous_next = $parameters['use_previous_next'] ?? FALSE;
  $previous_label = $use_previous_next ? t('Previous') : $date_formatter->format($previous, $date_format, $date_pattern);
  $next_label = $use_previous_next ? t('Next') : $date_formatter->format($next, $date_format, $date_pattern);
  $current_label = $date_formatter->format($current, $date_format, $date_pattern);

  // Build navigation.
  $variables['items'] = [];

  $variables['items']['previous'] = [
    '#type' => 'link',
    '#title' => $previous_label,
    '#url' => Url::fromRoute($route_name, [], [
      'query' => ['calendar_timestamp' => $previous] + $parameters,
    ]),
    '#attributes' => [
      'aria-label' => t('Previous month, @date', [
        '@date' => $date_formatter->format(
          $parameters['previous'],
          'custom',
          'F Y'
        ),
      ]),
    ],
    // @todo limit in past?
    '#access' => TRUE,
  ];

  $variables['items']['current'] = [
    '#type' => 'item',
    '#markup' => $current_label,
    '#attributes' => [
      'aria-label' => t('Current @date', [
        '@date' => $date_formatter->format($current, 'custom', 'F Y'),
      ]),
    ],
  ];

  // Reset button.
  if ($parameters['display_reset'] ?? NULL) {
    $date_time_now = new \DateTime();
    $date_time_now->setTimestamp(time());
    $now = strtotime($date_time_now->format('Y-m-01'));
    if ($now !== (int) $current) {
      $reset_title = t('Go back to @date', [
        '@date' => $date_formatter->format($now, $date_format, $date_pattern),
      ]);

      $variables['items']['reset'] = [
        '#type' => 'link',
        '#title' => t('Reset'),
        '#url' => Url::fromRoute($route_name, [], [
          'query' => ['calendar_timestamp' => 'today'] + $parameters,
        ]),
        '#attributes' => [
          'title' => $reset_title,
          'aria-label' => $reset_title,
          'class' => ['pager__reset'],
        ],
      ];
    }
  }

  $variables['items']['next'] = [
    '#type' => 'link',
    '#title' => $next_label,
    '#url' => Url::fromRoute($route_name, [], [
      'query' => ['calendar_timestamp' => $next] + $parameters,
    ]),
    '#attributes' => [
      'aria-label' => t('Next month, @date', [
        '@date' => $date_formatter->format(
          $parameters['next'],
          'custom',
          'F Y'
        ),
      ]),
    ],
    // @todo limit in future?
    '#access' => TRUE,
  ];

  /** @var \Drupal\Core\Render\RendererInterface $renderer */
  $renderer = \Drupal::service('renderer');
  $renderer->addCacheableDependency($variables, $view->storage);

  // Month navigation varies depending on the user selection.
  $variables['#cache']['contexts'][] = 'url.query_args:calendar_timestamp';
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function calendar_view_theme_suggestions_views_view_alter(&$suggestions, array $variables) {
  $view = $variables['view'];
  if (($style = $view->getStyle()) instanceof CalendarViewInterface) {
    // Custom template for Views using Calendar style for easier theming.
    // Useful when you want to place the pager somewhere else for instance.
    $suggestions[] = $variables['theme_hook_original'] . '__' . 'style' . '__' . 'calendar';
    $suggestions[] = $variables['theme_hook_original'] . '__' . 'style' . '__' . $style->getPluginId();
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function calendar_view_theme_suggestions_calendar_view_day_alter(&$suggestions, array $variables) {
  $elements = $variables['elements'] ?? [];
  if ($empty = empty($elements['#children'] ?? [])) {
    $suggestions[] = 'calendar_view_day__empty';
  }
  if ($view = $elements['#view'] ?? NULL) {
    $suggestions[] = 'calendar_view_day__' . $view->id();
    $suggestions[] = 'calendar_view_day__' . $view->id() . '__' . $view->current_display;
    if ($empty) {
      $suggestions[] = 'calendar_view_day__empty__' . $view->id();
      $suggestions[] = 'calendar_view_day__empty__' . $view->id() . '__' . $view->current_display;
    }
  }

  return $suggestions;
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function calendar_view_theme_suggestions_calendar_view_pager_alter(&$suggestions, array $variables) {
  if ($view = $variables['view'] ?? NULL) {
    $suggestions[] = 'calendar_view_pager__' . $view->id();
    $suggestions[] = 'calendar_view_pager__' . $view->id() . '__' . $view->current_display;
  }
  return $suggestions;
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function calendar_view_theme_suggestions_table_alter(array &$suggestions, array $variables, $hook) {
  $calendar_view = $variables['attributes']['data-calendar-view'] ?? NULL;
  if (empty($calendar_view)) {
    return;
  }

  // Suggest table templates by Calendar View and display.
  $view_id = $variables['attributes']['data-calendar-view-view-id'] ?? NULL;
  $view_display = $variables['attributes']['data-calendar-view-view-display'] ?? NULL;

  if (!empty($view_id)) {
    $suggestions[] = $hook . '__' . $view_id;
  }

  if (!empty($view_display)) {
    $suggestions[] = $hook . '__' . $view_id . '__' . $view_display;
  }
}
