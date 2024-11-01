<?php

namespace Drupal\dimension\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\FieldItemInterface;
use Drupal\Core\Field\Plugin\Field\FieldFormatter\StringFormatter;
use Drupal\dimension\Plugin\Field\DimensionInterface;

/**
 * Abstract class for length, area and volume formatters.
 */
abstract class Components extends StringFormatter implements DimensionInterface {

  /**
   * Builds the render array for dimension components.
   *
   * @param \Drupal\Core\Field\FieldItemInterface $item
   *   The field item.
   *
   * @return array
   *   The render array.
   *
   * @throws \Drupal\Core\TypedData\Exception\MissingDataException
   */
  protected function viewValue(FieldItemInterface $item): array {
    $build = [
      '#theme' => $this->pluginId,
    ];
    foreach ($this->fields() as $name => $label) {
      $build['#' . $name] = $item->get($name)->getValue();
    }
    return $build;
  }

}
