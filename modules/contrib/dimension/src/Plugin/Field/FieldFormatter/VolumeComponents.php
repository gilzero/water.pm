<?php

namespace Drupal\dimension\Plugin\Field\FieldFormatter;

use Drupal\dimension\Plugin\Field\VolumeTrait;

/**
 * Plugin implementation of the 'volume_components_field_formatter' formatter.
 *
 * @FieldFormatter(
 *   id = "volume_components_field_formatter",
 *   label = @Translation("Dimension: Volume Components"),
 *   field_types = {
 *     "volume_field_type"
 *   }
 * )
 */
class VolumeComponents extends Components {

  use VolumeTrait;

}
