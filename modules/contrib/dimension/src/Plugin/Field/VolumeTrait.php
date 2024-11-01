<?php

namespace Drupal\dimension\Plugin\Field;

/**
 * Trait for volume field classes.
 */
trait VolumeTrait {

  /**
   * {@inheritdoc}
   */
  public static function fields(): array {
    return [
      'length' => t('Length'),
      'width' => t('Width'),
      'height' => t('Height'),
    ];
  }

}
