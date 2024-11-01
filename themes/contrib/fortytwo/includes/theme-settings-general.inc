<?php
/**
 * @file
 * General theme settings elements.
 */

use Drupal\Core\Form\FormState;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Alter the theme settings form to add our own settings.
 *
 * @param array $form
 *   The form array passed by reference.
 * @param FormState $form_state
 *   The form state array.
 */
function fortytwo_form_system_theme_settings_alter(array &$form, FormState $form_state) {
  $form['fortytwo_settings'] = [
    '#type' => 'vertical_tabs',
    '#weight' => -10,
    '#prefix' => '<h3>' . t('Configuration') . '</h3>',
  ];

  fortytwo_theme_settings_general($form, $form_state);
}

/**
 * Setup the theme settings form.
 */
function fortytwo_theme_settings_general(&$form, &$form_state) {
  _fortytwo_theme_get_javascript($form);
  _fortytwo_theme_get_metatags($form);
  _fortytwo_theme_get_debuggers($form);
  _fortytwo_theme_get_breadcrumb($form);
}

/**
 * Javascript form fields.
 */
function _fortytwo_theme_get_javascript(&$form) {
  $linkOptions = [
    'attributes' => ['target' => '_blank'],
  ];

  $form['ft_js'] = [
    '#type' => 'details',
    '#title' => t('Javascript settings'),
    '#group' => 'fortytwo_settings',
  ];
  $form['ft_js']['polyfills'] = [
    '#type' => 'fieldset',
    '#title' => t('Polyfills'),
    '#prefix' => _fortytwo_theme_create_prefix(t('Polyfills')),
  ];
  $form['ft_js']['polyfills']['ft_placeholder_js'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable placeholder.js'),
    '#description' => t('Enable the placeholder.js javascript plugin'),
    '#default_value' => theme_get_setting('ft_placeholder_js'),
  ];
  $form['ft_js']['libraries'] = [
    '#type' => 'fieldset',
    '#title' => t('Libraries'),
    '#prefix' => _fortytwo_theme_create_prefix(t('Libraries')),
  ];
  $url = Url::fromUri('http://wicky.nillia.ms/enquire.js', $linkOptions);
  $link = Link::fromTextAndUrl(t('enquire.js'), $url)->toString();
  $form['ft_js']['libraries']['ft_enquire_js'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable enquire.js'),
    '#description' => t('Enable the @link javascript plugin. This includes the matchMedia.js library', ['@link' => $link]),
    '#default_value' => theme_get_setting('ft_enquire_js'),
  ];
  $url = Url::fromUri('http://ricostacruz.com/jquery.transit', $linkOptions);
  $link = Link::fromTextAndUrl(t('transit.js'), $url)->toString();
  $form['ft_js']['libraries']['ft_transit_js'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable transit.js'),
    '#description' => t('Enable the @link javascript plugin', ['@link' => $link]),
    '#default_value' => theme_get_setting('ft_transit_js'),
  ];
  $form['ft_js']['libraries']['ft_prettify_js'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable form field prettyfier'),
    '#description' => t('Prettifies fileinputs and selectboxes.'),
    '#default_value' => theme_get_setting('ft_prettify_js'),
  ];
  $form['ft_js']['libraries']['ft_prettify_js_hide_upload'] = [
    '#type' => 'checkbox',
    '#title' => t('Hide upload button on file fields'),
    '#description' => t('Since the files are uploaded when submitting a form, it is possible to hide the upload button.'),
    '#default_value' => theme_get_setting('ft_prettify_js_hide_upload'),
    '#states' => [
      'visible' => [
        ':input[name="ft_prettify_js"]' => ['checked' => TRUE],
      ],
    ],
  ];
  $form['ft_js']['libraries']['ft_prettify_js_add_remove'] = [
    '#type' => 'checkbox',
    '#title' => t('Show clear button on file fields'),
    '#description' => t('After selecting a file a user needs to browser and cancel to deselect. The clear button will provide an easy way to clear the upload field.'),
    '#default_value' => theme_get_setting('ft_prettify_js_add_remove'),
    '#states' => [
      'visible' => [
        ':input[name="ft_prettify_js"]' => ['checked' => TRUE],
      ],
    ],
  ];
}

/**
 * Meta tags form fields.
 */
function _fortytwo_theme_get_metatags(&$form) {
  $form['ft_metatags'] = [
    '#type' => 'details',
    '#title' => t('Metatags and HTTP headers'),
    '#group' => 'fortytwo_settings',
  ];

  $form['ft_metatags']['ft_cleartype'] = [
    '#type' => 'checkbox',
    '#title' => t('Cleartype support for Windows'),
    '#description' => t('Mobile Internet Explorer allows us to activate ClearType technology for smoothing fonts for easy reading.'),
    '#default_value' => theme_get_setting('ft_cleartype'),
  ];

  $form['ft_metatags']['ft_viewport'] = [
    '#type' => 'checkbox',
    '#title' => t('Viewport'),
    '#description' => t('This is more widely supported by modern smartphones, including but not limited to: iOS, Android, Palm Pre, Blackberry, Windows Phone 7.'),
    '#default_value' => theme_get_setting('ft_viewport'),
  ];

  $form['ft_metatags']['viewport_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Viewport settings'),
    '#states' => [
      'visible' => [
        ':input[name="ft_viewport"]' => ['checked' => TRUE],
      ],
    ],
  ];

  $options = ['_none' => t('Default')];
  foreach (range(0.1, 10, 0.1) as $value) {
    // Format the value to display with one decimal.
    $value = number_format($value, 1);
    $options[(string) $value] = $value;
  }

  $form['ft_metatags']['viewport_settings']['ft_viewport_initial_scale'] = [
    '#type' => 'select',
    '#title' => t('Initial scale'),
    '#default_value' => theme_get_setting('ft_viewport_initial_scale'),
    '#options' => $options,
    '#description' => t('The initial scaling of the page. Has to be in the range of the minimum- and maximum scale options.'),
  ];

  $form['ft_metatags']['viewport_settings']['ft_viewport_user_scaleable'] = [
    '#type' => 'checkbox',
    '#title' => t('User scalable'),
    '#default_value' => theme_get_setting('ft_viewport_user_scaleable'),
    '#description' => t("Whether users are allowed to zoom in and out. Defaults to 'yes'. This is usually accomplished via multi-touch gestures on iOS and Android devices. You should only disallow zooming (uncheck this checkbox) if your mobile theme is very customized and presented with good typography and graphics for a reduced mobile size."),
  ];

  $form['ft_metatags']['viewport_settings']['scaling_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Scaling settings'),
    '#states' => [
      'visible' => [
        ':input[name="ft_viewport_user_scaleable"]' => ['checked' => TRUE],
      ],
    ],
  ];

  $form['ft_metatags']['viewport_settings']['scaling_settings']['ft_viewport_minimum_scale'] = [
    '#type' => 'select',
    '#title' => t('Minimum scale'),
    '#default_value' => theme_get_setting('ft_viewport_minimum_scale'),
    '#options' => $options,
    '#description' => t('The minimum allowed scaling of the site.'),
  ];

  $form['ft_metatags']['viewport_settings']['scaling_settings']['ft_viewport_maximum_scale'] = [
    '#type' => 'select',
    '#title' => t('Maximum scale'),
    '#default_value' => theme_get_setting('ft_viewport_maximum_scale'),
    '#options' => $options,
    '#description' => t('The maximum allowed scaling of the site.'),
  ];
}

/**
 * Debugger form fields.
 */
function _fortytwo_theme_get_debuggers(&$form) {
  $form['ft_debug'] = [
    '#type' => 'details',
    '#title' => t('Debuggers'),
    '#group' => 'fortytwo_settings',
  ];
  $form['ft_debug']['ft_show_window_size'] = [
    '#type' => 'checkbox',
    '#title' => t('Show window size'),
    '#descrption' => t('Appears in the bottom right corner'),
    '#default_value' => theme_get_setting('ft_show_window_size'),
  ];

  $form['ft_debug']['ft_show_responsive_identifier'] = [
    '#type' => 'checkbox',
    '#title' => t('Show responsive identifier'),
    '#description' => t('Appears as a border on the top of the toolbar'),
    '#default_value' => theme_get_setting('ft_show_responsive_identifier'),
  ];

  $form['ft_debug']['ft_show_grid'] = [
    '#type' => 'checkbox',
    '#title' => t('Show column grid(s)'),
    '#description' => t('matchMedia and SVG capable browser needed (Chrome, Safari or Firefox) to view the debug grid.'),
    '#default_value' => theme_get_setting('ft_show_grid'),
  ];
}

/**
 * Breadcrumb form fields.
 */
function _fortytwo_theme_get_breadcrumb(&$form) {
  $form['ft_breadcrumb'] = [
    '#type' => 'details',
    '#title' => t('Breadcrumb settings'),
    '#group' => 'fortytwo_settings',
  ];
  $form['ft_breadcrumb']['breadcrumb_options'] = [
    '#type' => 'container',
    '#states' => [
      'invisible' => [
        ':input[name="ft_breadcrumb"]' => ['value' => 'no'],
      ],
    ],
  ];
  $form['ft_breadcrumb']['breadcrumb_options']['ft_breadcrumb_separator'] = [
    '#type' => 'textfield',
    '#title' => t('Breadcrumb separator'),
    '#description' => t('Text only. Don’t forget to include spaces.'),
    '#default_value' => theme_get_setting('ft_breadcrumb_separator'),
    '#size' => 5,
    '#maxlength' => 10,
  ];
  $form['ft_breadcrumb']['breadcrumb_options']['ft_breadcrumb_home'] = [
    '#type' => 'checkbox',
    '#title' => t('Show home page link in breadcrumb'),
    '#default_value' => theme_get_setting('ft_breadcrumb_home'),
  ];
  $form['ft_breadcrumb']['breadcrumb_options']['ft_breadcrumb_trailing'] = [
    '#type' => 'checkbox',
    '#title' => t('Append a separator to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('ft_breadcrumb_trailing'),
    '#description' => t('Useful when the breadcrumb is placed just before the title.'),
    '#states' => [
      'disabled' => [
        ':input[name="ft_breadcrumb_title"]' => ['checked' => TRUE],
      ],
    ],
  ];
  $form['ft_breadcrumb']['breadcrumb_options']['ft_breadcrumb_title'] = [
    '#type' => 'checkbox',
    '#title' => t('Append the content title to the end of the breadcrumb'),
    '#default_value' => theme_get_setting('ft_breadcrumb_title'),
    '#description' => t('Useful when the breadcrumb is not placed just before the title.'),
  ];
}

/**
 * A helper function to create a h3 tag.
 *
 * @param string $value
 *   The translated value for in the h3.
 *
 * @return string
 *   The h3 tag.
 */
function _fortytwo_theme_create_prefix($value) {
  $meta_generator = [
    '#type' => 'html_tag',
    '#tag' => 'h3',
    '#value' => $value,
  ];
  return \Drupal::service('renderer')->render($meta_generator);
}
