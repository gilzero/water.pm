<?php

namespace Drupal\dimension\Plugin\Field\FieldType;

use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\dimension\Plugin\Field\LengthTrait;

/**
 * Plugin implementation of the 'length_field_type' field type.
 *
 * @FieldType(
 *   id = "length_field_type",
 *   label = @Translation("Dimension: Length"),
 *   description = @Translation("Define length"),
 *   default_widget = "length_field_widget",
 *   default_formatter = "length_field_formatter"
 * )
 */
class Length extends Dimension {

  use LengthTrait;

  /**
   * {@inheritdoc}
   */
  public static function defaultStorageSettings(): array {
    return self::defaultFieldTypeStorageSettings(self::fields());
  }

  /**
   * {@inheritdoc}
   */
  public static function defaultFieldSettings(): array {
    return self::defaultFieldTypeSettings(self::fields());
  }

  /**
   * {@inheritdoc}
   */
  public static function propertyDefinitions(FieldStorageDefinitionInterface $field_definition): array {
    return self::propertyFieldTypeDefinitions(self::fields());
  }

  /**
   * {@inheritdoc}
   */
  public static function schema(FieldStorageDefinitionInterface $field_definition): array {
    return self::schemaFieldType($field_definition, self::fields());
  }

}
