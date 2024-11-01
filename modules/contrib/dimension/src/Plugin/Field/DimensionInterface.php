<?php

namespace Drupal\dimension\Plugin\Field;

/**
 * Interface for dimension variations.
 */
interface DimensionInterface {

  /**
   * Provides the list of fields supported by the dimension variation.
   *
   * @return array
   *   The list of fields.
   */
  public static function fields(): array;

}
