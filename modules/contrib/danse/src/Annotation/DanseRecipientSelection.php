<?php

namespace Drupal\danse\Annotation;

use Drupal\Component\Annotation\Plugin;

/**
 * Defines Danse recipient selection annotation object.
 *
 * @Annotation
 */
class DanseRecipientSelection extends Plugin {

  /**
   * The plugin ID.
   *
   * @var string
   */
  public $id;

  /**
   * The human-readable name of the plugin.
   *
   * @var \Drupal\Core\Annotation\Translation
   *
   * @ingroup plugin_translatable
   */
  public $title;

  /**
   * The description of the plugin.
   *
   * @var \Drupal\Core\Annotation\Translation
   *
   * @ingroup plugin_translatable
   */
  public $description;

}
