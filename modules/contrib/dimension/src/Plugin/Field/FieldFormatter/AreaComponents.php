<?php

namespace Drupal\dimension\Plugin\Field\FieldFormatter;

use Drupal\dimension\Plugin\Field\AreaTrait;

/**
 * Plugin implementation of the 'area_components_field_formatter' formatter.
 *
 * @FieldFormatter(
 *   id = "area_components_field_formatter",
 *   label = @Translation("Dimension: Area Components"),
 *   field_types = {
 *     "area_field_type"
 *   }
 * )
 */
class AreaComponents extends Components {

  use AreaTrait;

}
