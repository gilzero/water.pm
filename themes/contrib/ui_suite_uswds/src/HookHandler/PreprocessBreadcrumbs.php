<?php

declare(strict_types=1);

namespace Drupal\ui_suite_uswds\HookHandler;

use Drupal\ui_patterns_settings\Plugin\UiPatterns\SettingType\LinksSettingType;

/**
 * Ensure breadcrumb structure fits into links prop structure.
 */
class PreprocessBreadcrumbs {

  /**
   * Ensure breadcrumb structure fits into links prop structure.
   *
   * @param array $variables
   *   The preprocessed variables.
   */
  public function preprocess(array &$variables): void {
    $variables['breadcrumb'] = LinksSettingType::normalize($variables['breadcrumb']);
  }

}
