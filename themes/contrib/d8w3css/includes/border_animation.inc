<?php

/**
 * @file
 * W3CSS Theme.theme.
 *
 * Filename:     drupal8_w3css_theme.theme
 * Website:      http://www.flashwebcenter.com
 * Description:  template
 * Author:       Alaa Haddad http://www.alaahaddad.com.
 */

/**
 * The theme settings.
 */

$form['drupal8_w3css_theme_settings']['w3_border_animation'] = [
  '#type' => 'details',
  '#title' => t("Enable Border Animation - W3CSS Theme"),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description'   => t("<p><strong>You can enable/disable the border animation for the top regions, bottom regions and footer regions.</strong></p>"),
];

$form['drupal8_w3css_theme_settings']['w3_border_animation']['border_animation'] = [
  '#type' => 'checkbox',
  '#title' => t("Check this box to animate the region's border."),
  '#default_value' => theme_get_setting('border_animation'),
];
