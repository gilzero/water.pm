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

$form['drupal8_w3css_theme_settings']['w3_website_width'] = [
  '#type' => 'details',
  '#title' => t("Website's Width - W3CSS Theme"),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description' => t("<p><strong>You can change the whole website's width by selecting any of the desired width in pixels.</strong></p><p>w3-width-100-percent, w3-width-2560, w3-width-1920, w3-width-1360, w3-width-1280, w3-width-1024 and w3-width-800. The default width is 1600 pixels.</p>"),
];

$form['drupal8_w3css_theme_settings']['w3_website_width']['website_width'] = [
  '#type' => 'select',
  '#title' => t("Choose the desired website's width"),
  '#options' => [
    'none' => t('Default - 1600 Pixels'),
    'w3-width-2560' => t('2560 Pixels'),
    'w3-width-1920' => t('1920 Pixels'),
    'w3-width-1360' => t('1360 Pixels'),
    'w3-width-1280' => t('1280 Pixels'),
    'w3-width-1024' => t('1024 Pixels'),
    'w3-width-800' => t('800 Pixels'),
    'w3-width-100-percent' => t('100%'),
  ],
  '#default_value' => theme_get_setting('website_width'),
];
