<?php

namespace Drupal\dimension\Plugin\Field;

/**
 * Trait for length field classes.
 */
trait LengthTrait {

  /**
   * {@inheritdoc}
   */
  public static function fields(): array {
    return [
      'length' => t('Length'),
    ];
  }

}
