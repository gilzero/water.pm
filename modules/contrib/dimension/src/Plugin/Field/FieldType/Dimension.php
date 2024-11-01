<?php

namespace Drupal\dimension\Plugin\Field\FieldType;

use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\Core\Field\Plugin\Field\FieldType\DecimalItem;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\TypedData\DataDefinition;
use Drupal\dimension\Plugin\Field\DimensionInterface;

/**
 * Abstract base class for the dimension variations.
 */
abstract class Dimension extends DecimalItem implements DimensionInterface {

  /**
   * Default settings for precision and scale.
   *
   * @param array $fields
   *   The fields.
   *
   * @return int[]
   *   Array of precision and scale for dimension fields.
   */
  protected static function defaultFieldTypeStorageSettings(array $fields): array {
    $settings = [
      'value_precision' => 10,
      'value_scale' => 2,
    ];
    foreach ($fields as $key => $label) {
      $settings[$key . '_precision'] = 10;
      $settings[$key . '_scale'] = 2;
    }
    return $settings;
  }

  /**
   * Default settings for the field types.
   *
   * @param array $fields
   *   The fields.
   *
   * @return array[]
   *   The default settings.
   */
  protected static function defaultFieldTypeSettings(array $fields): array {
    $settings = [
      'value' => [
        'factor' => 1,
        'min' => '',
        'max' => '',
        'prefix' => '',
        'suffix' => '',
      ],
    ];
    foreach ($fields as $key => $label) {
      $settings[$key] = [
        'factor' => 1,
        'min' => '',
        'max' => '',
        'prefix' => '',
        'suffix' => '',
      ];
    }
    return $settings;
  }

  /**
   * The default properties for dimension fields.
   *
   * @param array $fields
   *   The fields.
   *
   * @return array
   *   The default properties.
   */
  protected static function propertyFieldTypeDefinitions(array $fields): array {
    $properties = [];
    $properties['value'] = DataDefinition::create('string')
      ->setLabel(t('Value'))
      ->setRequired(TRUE);
    foreach ($fields as $key => $label) {
      $properties[$key] = DataDefinition::create('string')
        ->setLabel($label)
        ->setRequired(TRUE);
    }
    return $properties;
  }

  /**
   * The schema for dimension fields.
   *
   * @param \Drupal\Core\Field\FieldStorageDefinitionInterface $field_definition
   *   The field definition.
   * @param array $fields
   *   The fields.
   *
   * @return array
   *   The schema.
   */
  protected static function schemaFieldType(FieldStorageDefinitionInterface $field_definition, array $fields): array {
    $settings = $field_definition->getSettings();
    $schema = [
      'columns' => [
        'value' => [
          'type' => 'numeric',
          'precision' => $settings['value_precision'],
          'scale' => $settings['value_scale'],
        ],
      ],
    ];
    foreach ($fields as $key => $label) {
      $schema['columns'][$key] = [
        'type' => 'numeric',
        'precision' => $settings[$key . '_precision'],
        'scale' => $settings[$key . '_scale'],
      ];
    }

    return $schema;
  }

  /**
   * Helper form build function for precision and scale.
   *
   * @param array $element
   *   The form element.
   * @param string $key
   *   The field's key.
   * @param string $label
   *   The field's label.
   * @param bool $has_data
   *   Whether the field has data. Will be disabled if not.
   * @param array $settings
   *   The field settings.
   */
  private function storageFieldTypeSettings(array &$element, string $key, string $label, bool $has_data, array $settings): void {
    $range = range(10, 32);
    $element[$key . '_precision'] = [
      '#type' => 'select',
      '#title' => $this->t('%label precision', ['%label' => $label]),
      '#options' => array_combine($range, $range),
      '#default_value' => $settings[$key . '_precision'],
      '#description' => $this->t('The total number of digits to store in the database, including those to the right of the decimal.'),
      '#disabled' => $has_data,
    ];
    $range = range(0, 10);
    $element[$key . '_scale'] = [
      '#type' => 'select',
      '#title' => $this->t('%label scale', ['%label' => $label]),
      '#options' => array_combine($range, $range),
      '#default_value' => $settings[$key . '_scale'],
      '#description' => $this->t('The number of digits to the right of the decimal.'),
      '#disabled' => $has_data,
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function storageSettingsForm(array &$form, FormStateInterface $form_state, $has_data): array {
    $settings = $this->getSettings();
    $element = [];
    foreach ($this->fields() as $key => $label) {
      $this->storageFieldTypeSettings($element, $key, $label, $has_data, $settings);
    }
    $this->storageFieldTypeSettings($element, 'value', $this->t('Full dimension'), $has_data, $settings);

    return $element;
  }

  /**
   * Helper function to build field related form elements.
   *
   * @param array $element
   *   The field element.
   * @param string $key
   *   The field's key.
   * @param string $label
   *   The field's label.
   * @param bool $hide_constraints
   *   Flag to determine if constraints should be hidden.
   */
  private function fieldSettings(array &$element, string $key, string $label, bool $hide_constraints = FALSE): void {
    $settings = $this->getSetting($key);

    $element[$key] = [
      '#type' => 'fieldset',
      '#title' => $label,
    ];
    $element[$key]['factor'] = [
      '#type' => 'number',
      '#title' => $this->t('Factor'),
      '#default_value' => $settings['factor'],
      '#step' => 0.1 ** 2,
      '#required' => TRUE,
      '#description' => $this->t('A factor to multiply the @label with when calculating the @field', [
        '@label' => $label,
        '@field' => $this->getFieldDefinition()->getLabel(),
      ]),
      '#access' => !$hide_constraints,
    ];
    $element[$key]['min'] = [
      '#type' => 'number',
      '#title' => $this->t('Minimum'),
      '#default_value' => $settings['min'],
      '#step' => 0.1 ** $this->getSetting($key . '_scale'),
      '#description' => $this->t('The minimum value that should be allowed in this field. Leave blank for no minimum.'),
      '#access' => !$hide_constraints,
    ];
    $element[$key]['max'] = [
      '#type' => 'number',
      '#title' => $this->t('Maximum'),
      '#default_value' => $settings['max'],
      '#step' => 0.1 ** $this->getSetting($key . '_scale'),
      '#description' => $this->t('The maximum value that should be allowed in this field. Leave blank for no maximum.'),
      '#access' => !$hide_constraints,
    ];
    $element[$key]['prefix'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Prefix'),
      '#default_value' => $settings['prefix'],
      '#size' => 60,
      '#description' => $this->t("Define a string that should be prefixed to the value, like 'cm ' or 'inch '. Leave blank for none. Separate singular and plural values with a pipe ('inch|inches')."),
    ];
    $element[$key]['suffix'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Suffix'),
      '#default_value' => $settings['suffix'],
      '#size' => 60,
      '#description' => $this->t("Define a string that should be suffixed to the value, like ' mm', ' inch'. Leave blank for none. Separate singular and plural values with a pipe ('inch|inches')."),
    ];

  }

  /**
   * {@inheritdoc}
   */
  public function fieldSettingsForm(array $form, FormStateInterface $form_state): array {
    $element = [];

    foreach ($this->fields() as $key => $label) {
      $this->fieldSettings($element, $key, $label);
    }

    $this->fieldSettings($element, 'value', $this->t('Full dimension'), TRUE);

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  public function getConstraints(): array {
    $constraint_manager = \Drupal::typedDataManager()->getValidationConstraintManager();
    $constraints = [];
    foreach ($this->definition->getConstraints() as $name => $options) {
      $constraints[] = $constraint_manager->create($name, $options);
    }

    foreach ($this->fields() as $key => $label) {
      $settings = $this->getSetting($key);
      $constraints[] = $constraint_manager->create('ComplexData', [
        $key => [
          'Regex' => [
            'pattern' => '/^[+-]?((\d+(\.\d*)?)|(\.\d+))$/i',
          ],
        ],
      ]);
      if (!empty($settings['min'])) {
        $min = $settings['min'];
        $constraints[] = $constraint_manager->create('ComplexData', [
          $key => [
            'Range' => [
              'min' => $min,
              'minMessage' => $this->t('%name: the value may be no less than %min.', [
                '%name' => $label,
                '%min' => $min,
              ]),
            ],
          ],
        ]);
      }

      if (!empty($settings['max'])) {
        $max = $settings['max'];
        $constraints[] = $constraint_manager->create('ComplexData', [
          $key => [
            'Range' => [
              'max' => $max,
              'maxMessage' => $this->t('%name: the value may be no greater than %max.', [
                '%name' => $label,
                '%max' => $max,
              ]),
            ],
          ],
        ]);
      }
    }

    return $constraints;
  }

  /**
   * {@inheritdoc}
   */
  public function preSave(): void {
    $values = [];
    foreach ($this->fields() as $key => $label) {
      $values[$key] = $this->{$key};
      $this->{$key} = round($this->{$key}, $this->getSetting($key . '_scale'));
    }
    $this->value = (string) $this->calculate($values);
  }

  /**
   * {@inheritdoc}
   */
  public function isEmpty(): bool {
    foreach ($this->fields() as $key => $label) {
      if (empty($this->{$key}) && (string) $this->{$key} !== '0') {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Helper function to calculate the dimension.
   *
   * @param array $values
   *   The field values.
   *
   * @return float
   *   The calculated dimension.
   */
  public function calculate(array $values): float {
    $value = 1;
    foreach ($this->fields() as $key => $label) {
      $settings = $this->getSetting($key);
      $values[$key] = round($values[$key], $this->getSetting($key . '_scale'));
      $value *= $values[$key] * $settings['factor'];
    }
    return round($value, $this->getSetting('value_scale'));
  }

}
