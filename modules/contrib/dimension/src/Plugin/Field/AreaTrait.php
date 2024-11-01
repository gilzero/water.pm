<?php

namespace Drupal\dimension\Plugin\Field;

/**
 * Trait for area field classes.
 */
trait AreaTrait {

  /**
   * {@inheritdoc}
   */
  public static function fields(): array {
    return [
      'width' => t('Width'),
      'height' => t('Height'),
    ];
  }

}
