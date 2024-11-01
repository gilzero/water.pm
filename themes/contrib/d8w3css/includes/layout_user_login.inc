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

$form['drupal8_w3css_theme_settings']['w3_layout_user'] = [
  '#type' => 'details',
  '#title' => t('Enable custom layout for the login, register and reset password pages.'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description'   => t('<p>If you check this box the login form will be centered and left/right sides will be hidden.</p>'),
];
$form['drupal8_w3css_theme_settings']['w3_layout_user']['layout_user_login_custom'] = [
  '#type' => 'checkbox',
  '#title' => t('Check this box to change the layout for the login, register and reset password pages.'),
  '#default_value' => theme_get_setting('layout_user_login_custom'),
];
