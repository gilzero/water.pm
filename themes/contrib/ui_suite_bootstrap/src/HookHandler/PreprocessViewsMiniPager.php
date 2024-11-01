<?php

declare(strict_types=1);

namespace Drupal\ui_suite_bootstrap\HookHandler;

use Drupal\ui_patterns_settings\Plugin\UiPatterns\SettingType\LinksSettingType;

/**
 * Ensure views mini pager structure fits into links prop structure.
 */
class PreprocessViewsMiniPager extends PreprocessPager {

  /**
   * Ensure views mini pager structure fits into links prop structure.
   *
   * @param array $variables
   *   The preprocessed variables.
   */
  public function preprocess(array &$variables): void {
    if (!isset($variables['items'])) {
      return;
    }
    $this->setLinksAriaLabel($variables['items']);

    $variables['preprocessed_items'] = LinksSettingType::normalize(\array_filter([
      $variables['items']['previous'] ?? [],
      [
        'title' => $variables['items']['current'],
      ],
      $variables['items']['next'] ?? [],
    ]));
  }

}
