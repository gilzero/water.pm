<?php

namespace Drupal\site_audit\Plugin\SiteAuditCheck;

use Drupal\site_audit\Plugin\SiteAuditCheckBase;
use Drupal\views\Views;

/**
 * Provides the ViewsCount Check.
 *
 * @SiteAuditCheck(
 *  id = "views_count",
 *  name = @Translation("Count"),
 *  description = @Translation("Number of enabled Views."),
 *  checklist = "views",
 *  weight = -1,
 * )
 */
class ViewsCount extends SiteAuditCheckBase {

  /**
   * {@inheritdoc}.
   */
  public function getResultFail() {}

  /**
   * {@inheritdoc}.
   */
  public function getResultInfo() {}

  /**
   * {@inheritdoc}.
   */
  public function getResultPass() {
    $views_count = count($this->registry->views);
    if (!$views_count) {
      return $this->t('There are no enabled views.');
    }
    return $this->t('There are @count_views enabled views.', [
      '@count_views' => count($this->registry->views),
    ]);
  }

  /**
   * {@inheritdoc}.
   */
  public function getResultWarn() {
    return $this->getResultPass();
  }

  /**
   * {@inheritdoc}.
   */
  public function getAction() {
    if ($this->score == SiteAuditCheckBase::AUDIT_CHECK_SCORE_WARN) {
      return $this->t('Consider disabling the views module if you don\'t need it.');
    }
  }

  /**
   * {@inheritdoc}.
   */
  public function calculateScore() {
    $this->registry->views = [];

    foreach (Views::getEnabledViews() as $view) {
      $this->registry->views[] = $view;
    }

    if (empty($this->registry->views)) {
      $this->abort = TRUE;
      return SiteAuditCheckBase::AUDIT_CHECK_SCORE_WARN;
    }
    return SiteAuditCheckBase::AUDIT_CHECK_SCORE_PASS;
  }

}
