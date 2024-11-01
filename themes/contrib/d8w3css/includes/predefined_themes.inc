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

$form['drupal8_w3css_theme_settings']['w3_theme_current'] = [
  '#type' => 'details',
  '#title' => t('Predefined Color Themes - W3CSS Theme'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description'   => t('<p>w3-theme-amber, w3-theme-black, w3-theme-blue-grey, w3-theme-blue, w3-theme-brown, w3-theme-cyan, w3-theme-dark-grey, w3-theme-deep-orange, w3-theme-deep-purple, w3-theme-green, w3-theme-grey, w3-theme-indigo, w3-theme-khaki, w3-theme-light-blue, w3-theme-light-green, w3-theme-lime, w3-theme-orange, w3-theme-pink, w3-theme-purple, w3-theme-red, w3-theme-teal, w3-theme-yellow, w3-theme-00000, w3-theme-00001, w3-theme-00002, w3-theme-00003, w3-theme-00004, w3-theme-00005, w3-theme-00006, w3-theme-00007, w3-theme-00008, w3-theme-00009, w3-theme-00010, w3-theme-00011, w3-theme-00012, w3-theme-00013, w3-theme-00014, w3-theme-00015, w3-theme-00016, w3-theme-00017, w3-theme-00018, w3-theme-00019, w3-theme-00020, w3-theme-00021, w3-theme-00022, w3-theme-00023, w3-theme-00024, w3-theme-00025, w3-theme-00026, w3-theme-00027, w3-theme-00028 and w3-theme-00029. <strong><a target="_blank" href="https://flex6.com/w3css-predefined-color-themes">Demo Site has an example for all color themes</a>.</strong></p>'),
];
$form['drupal8_w3css_theme_settings']['w3_theme_current']['current_theme'] = [
  '#type' => 'select',
  '#title' => t("Choose the desired predefined theme"),
  '#options' => [
    'none' => t('Default - Black Gray White'),
    'w3-theme-amber' => t('Amber'),
    'w3-theme-black' => t('Black'),
    'w3-theme-blue-grey' => t('Blue Gray'),
    'w3-theme-blue' => t('Blue'),
    'w3-theme-brown' => t('Brown'),
    'w3-theme-cyan' => t('Cyan'),
    'w3-theme-dark-grey' => t('Dark Gray'),
    'w3-theme-deep-orange' => t('Deep Orange'),
    'w3-theme-deep-purple' => t('Deep Purple'),
    'w3-theme-green' => t('Green'),
    'w3-theme-grey' => t('Gray'),
    'w3-theme-indigo' => t('Indigo'),
    'w3-theme-khaki' => t('Khaki'),
    'w3-theme-light-blue' => t('Light Blue'),
    'w3-theme-light-green' => t('Light Green'),
    'w3-theme-lime' => t('Lime'),
    'w3-theme-orange' => t('Orange'),
    'w3-theme-pink' => t('Pink'),
    'w3-theme-purple' => t('Purple'),
    'w3-theme-red' => t('Red'),
    'w3-theme-teal' => t('Teal'),
    'w3-theme-yellow' => t('Yellow'),
    'w3-theme-00000' => t('00000 - Plain No Colors'),
    'w3-theme-00001' => t('00001 - Blue Gray'),
    'w3-theme-00002' => t('00002 - Blue'),
    'w3-theme-00003' => t('00003 - Green'),
    'w3-theme-00004' => t('00004 - Purple'),
    'w3-theme-00005' => t('00005 - Brown'),
    'w3-theme-00006' => t('00006 - Red'),
    'w3-theme-00007' => t('00007 - Indigo'),
    'w3-theme-00008' => t('00008 - Red Turquoise'),
    'w3-theme-00009' => t('00009 - DarkCyan'),
    'w3-theme-00010' => t('00010 - Green Grass'),
    'w3-theme-00011' => t('00011 - Dark Brown'),
    'w3-theme-00012' => t('00012 - Blue Red'),
    'w3-theme-00013' => t('00013 - CadetBlue'),
    'w3-theme-00014' => t('00014 - SlateGray'),
    'w3-theme-00015' => t('00015 - CadetBlue SteelBlue'),
    'w3-theme-00016' => t('00016 - BlueOrange'),
    'w3-theme-00017' => t('00017 - DarkOrange MidnightBlue'),
    'w3-theme-00018' => t('00018 - Dark Theme - BlackGray'),
    'w3-theme-00019' => t('00019 - Dark Theme - BlackGreen'),
    'w3-theme-00020' => t('00020 - Dark Theme - BlackBlue'),
    'w3-theme-00021' => t('00021 - Dark Theme - BlackPurple'),
    'w3-theme-00022' => t('00022 - Dark Theme - BlackRed'),
    'w3-theme-00023' => t('00023 - Dark Theme - BlackPink'),
    'w3-theme-00024' => t('00024 - Dark Theme - BlackLightGreen'),
    'w3-theme-00025' => t('00025 - Dark Theme - BlackDarkPurple'),
    'w3-theme-00026' => t('00026 - Dark Theme - BlackYellow'),
    'w3-theme-00027' => t('00027 - Dark Theme - BlackLightBlue'),
    'w3-theme-00028' => t('00028 - DarkRed LightBlue'),
    'w3-theme-00029' => t('00029 - Colorfull Image Background'),
  ],
  '#default_value' => theme_get_setting('current_theme'),
];
