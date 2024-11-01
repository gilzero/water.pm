<?php

namespace Drupal\dimension\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\Plugin\Field\FieldFormatter\DecimalFormatter;
use Drupal\dimension\Plugin\Field\DimensionInterface;

/**
 * Abstract class for length, area and volume formatters.
 */
abstract class Dimension extends DecimalFormatter implements DimensionInterface {

  /**
   * {@inheritdoc}
   */
  protected function getFieldSettings(): array {
    $settings = parent::getFieldSettings();
    if (!empty($settings['value']['prefix'])) {
      $settings['prefix'] = $settings['value']['prefix'];
    }
    if (!empty($settings['value']['suffix'])) {
      $settings['suffix'] = $settings['value']['suffix'];
    }
    return $settings;
  }

}
