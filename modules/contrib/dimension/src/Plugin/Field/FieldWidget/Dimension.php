<?php

namespace Drupal\dimension\Plugin\Field\FieldWidget;

use Drupal\Core\Field\FieldFilteredMarkup;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\Plugin\Field\FieldWidget\NumberWidget;
use Drupal\Core\Form\FormStateInterface;
use Drupal\dimension\Plugin\Field\DimensionInterface;

/**
 * Abstract base class for the dimension variations.
 */
abstract class Dimension extends NumberWidget implements DimensionInterface {

  /**
   * Provides the default settings for a dimension field.
   *
   * @param array $fields
   *   The list of fields.
   *
   * @return array
   *   The list of fields with DimensionInterface properties being defined.
   */
  protected static function defaultFieldSettings(array $fields): array {
    $settings = [];
    foreach ($fields as $key => $label) {
      $settings[$key] = [
        'placeholder' => '',
        'label' => $label,
        'description' => '',
      ];
    }
    return $settings;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state): array {
    $element = [];
    foreach ($this->fields() as $key => $label) {
      $settings = $this->getSetting($key);
      $element[$key] = [
        '#type' => 'fieldset',
        '#title' => $settings['label'],
      ];
      $element[$key]['label'] = [
        '#type' => 'textfield',
        '#title' => $this->t('Label'),
        '#default_value' => $settings['label'],
        '#required' => TRUE,
        '#description' => $this->t('To be done.'),
      ];
      $element[$key]['placeholder'] = [
        '#type' => 'textfield',
        '#title' => $this->t('Placeholder'),
        '#default_value' => $settings['placeholder'],
        '#description' => $this->t('Text that will be shown inside the field until a value is entered. This hint is usually a sample value or a brief description of the expected format.'),
      ];
      $element[$key]['description'] = [
        '#type' => 'textfield',
        '#title' => $this->t('Description'),
        '#default_value' => $settings['description'],
        '#description' => $this->t('To be done.'),
      ];
    }
    return $element;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsSummary(): array {
    $summary = [];
    foreach ($this->fields() as $key => $label) {
      $settings = $this->getSetting($key);
      $placeholder = $settings['placeholder'];
      if (!empty($placeholder)) {
        $summary[] = $this->t('@label: @placeholder', [
          '@label' => $settings['label'],
          '@placeholder' => $placeholder,
        ]);
      }
      else {
        $summary[] = $this->t('@label: No placeholder', ['@label' => $settings['label']]);
      }
    }
    return $summary;
  }

  /**
   * {@inheritdoc}
   */
  public function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state): array {
    $default = $items->getFieldDefinition()->getDefaultValue($items->getEntity());
    $element += [
      '#type' => 'fieldset',
      '#attached' => [
        'library' => [],
      ],
    ];

    $arguments = [];

    foreach ($this->fields() as $key => $label) {
      $settings = $this->getSetting($key);
      $field_settings = $this->getFieldSetting($key);
      $value = $items[$delta]->{$key} ?? $default[0][$key] ?? NULL;

      $arguments['fields'][$key] = [
        'scale' => $this->getFieldSetting($key . '_scale'),
        'factor' => $field_settings['factor'],
      ];

      $element[$key] = [
        '#type' => 'number',
        '#title' => $settings['label'],
        '#default_value' => $value,
        '#placeholder' => $settings['placeholder'],
        '#step' => 0.1 ** $this->getFieldSetting($key . '_scale'),
        '#description' => $settings['description'],
        '#attributes' => [
          'dimension-key' => $key,
        ],
      ];

      // Set minimum and maximum.
      if (is_numeric($field_settings['min'])) {
        $element[$key]['#min'] = $field_settings['min'];
      }
      if (is_numeric($field_settings['max'])) {
        $element[$key]['#max'] = $field_settings['max'];
      }

      // Add prefix and suffix.
      if ($field_settings['prefix']) {
        $prefixes = explode('|', $field_settings['prefix']);
        $element[$key]['#field_prefix'] = FieldFilteredMarkup::create(array_pop($prefixes));
      }
      if ($field_settings['suffix']) {
        $suffixes = explode('|', $field_settings['suffix']);
        $element[$key]['#field_suffix'] = FieldFilteredMarkup::create(array_pop($suffixes));
      }
    }

    $element['value'] = [
      '#type' => 'number',
      '#title' => $this->t('Dimension'),
      '#default_value' => '',
      '#disabled' => TRUE,
      '#attributes' => [
        'dimension-key' => 'value',
      ],
    ];
    $field_settings = $this->getFieldSetting('value');
    $arguments['value'] = [
      'scale' => $this->getFieldSetting('value_scale'),
      'factor' => $field_settings['factor'],
    ];
    // Add prefix and suffix.
    if ($field_settings['prefix']) {
      $prefixes = explode('|', $field_settings['prefix']);
      $element['value']['#field_prefix'] = FieldFilteredMarkup::create(array_pop($prefixes));
    }
    if ($field_settings['suffix']) {
      $suffixes = explode('|', $field_settings['suffix']);
      $element['value']['#field_suffix'] = FieldFilteredMarkup::create(array_pop($suffixes));
    }

    $id = $this->fieldDefinition->getConfig($items->getEntity()->bundle())->id();
    $element['#attached']['library'][] = 'dimension/widget';
    $element['#attached']['drupalSettings']['dimension'][$id] = $arguments;
    $element['#attributes']['dimension-id'] = $id;
    $element['#attributes']['class'][] = 'dimension-wrapper';

    return $element;
  }

}
