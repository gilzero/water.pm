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

$form['drupal8_w3css_theme_settings']['copyright'] = [
  '#type' => 'details',
  '#title' => t('Copyright - W3CSS Theme'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];
$form['drupal8_w3css_theme_settings']['copyright']['copyright_text'] = [
  '#type' => 'textfield',
  '#title' => t('Enter Copyright Text'),
  '#description' => t("Type %year% instead of an actual year number for dynamic copyright. (Copyright © %year% Company Name - All rights reserved)."),
  '#default_value' => theme_get_setting('copyright_text'),
];
