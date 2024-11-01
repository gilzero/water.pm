<?php

/**
 * @file
 * Theme settings form for FlexiStyle Bootstrap theme.
 */

use Drupal\Core\Form\FormState;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function flexistyle_bootstrap_scss_form_system_theme_settings_alter(array &$form, FormState $form_state): void {
  $form['theme_settings']['#open'] = FALSE;
  $form['logo']['#open'] = FALSE;
  $form['favicon']['#open'] = FALSE;

  $form['flexistyle_bootstrap_tabs'] = [
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>' . t('FlexiStyle Bootstrap SCSS Settings') . '</small></h2>',
    '#weight' => -10,
  ];
  // Bootstrap configs
  $form['flexi_bootstrap'] = [
    '#type' => 'details',
    '#title' => t('Bootstrap'),
    '#open' => TRUE,
    '#group' => 'flexistyle_bootstrap_tabs',
  ];
  $form['flexi_bootstrap']['bootstrap_container'] = [
    '#type' => 'select',
    '#title' => t('Container Size'),
    '#default_value' => theme_get_setting('bootstrap_container'),
    '#options' => [
      'container' => t('container - (fixed width)'),
      'container-fluid' => t('container-fluid - (Full width)'),
    ],
  ];

  // Global configs
  $form['flexi_global'] = [
    '#type' => 'details',
    '#title' => t('Global'),
    '#open' => FALSE,
    '#group' => 'flexistyle_bootstrap_tabs',
  ];
  $form['flexi_global']['local_fonts'] = [
    '#type' => 'select',
    '#title' => t('Local Fonts'),
    '#default_value' => theme_get_setting('local_fonts'),
    '#options' => [
      'none' => t('Default'),
      'helvetica' => t('Helvetica, "Trebuchet MS", Verdana, sans-serif'),
      'verdana' => t('Verdana, sans-serif'),
    ],
  ];
  $form['flexi_global']['google_fonts'] = [
    '#type' => 'select',
    '#title' => t('Google Fonts'),
    '#default_value' => theme_get_setting('google_fonts'),
    '#options' => [
      'none' => t('None'),
      'open-sans' => t('Open Sans, sans-serif'),
      'roboto' => t('Roboto, sans-serif'),
      'lato' => t('Lato, sans-serif'),
      'poppins' => t('Poppins, sans-serif'),
    ],
  ];
  $form['flexi_global']['global_icons'] = [
    '#type' => 'select',
    '#title' => t('Global Icons'),
    '#default_value' => theme_get_setting('global_icons'),
    '#options' => [
      'none' => t('None'),
      'fontawesome' => t('Font Awesome Icons'),
      'google-material' => t('Google Material Icons'),
      'bootstrap-icons' => t('Bootstrap Icons'),
    ],
  ];
  $form['flexi_global']['global_icons_fontawesome'] = [
    '#type' => 'select',
    '#title' => t('Fontawesome Icons Library'),
    '#default_value' => theme_get_setting('global_icons_fontawesome'),
    '#options' => [
      'fa_local' => t('FA Local'),
      'fa_cdn' => t('FA CDN'),
    ],
    '#states' => [
      'visible' => [
        [':input[name="global_icons"]' => ['value' => 'fontawesome']],
      ],
    ],
  ];
  $form['flexi_global']['global_style'] = [
    '#type' => 'textarea',
    '#title' => t('Global Style'),
    '#placeholder' => t('Global CSS'),
    '#default_value' => theme_get_setting('global_style'),
  ];
  $background = [
    'bg-none' => t('bg-none'),
    'bg-white' => t('bg-white'),
    'bg-black' => t('bg-black'),
    'bg-light' => t('bg-light'),
    'bg-light-subtle' => t('bg-light-subtle'),
    'bg-dark' => t('bg-dark'),
    'bg-dark-subtle' => t('bg-dark-subtle'),
    'bg-primary' => t('bg-primary'),
    'bg-primary-subtle' => t('bg-primary-subtle'),
    'bg-secondary' => t('bg-secondary'),
    'bg-secondary-subtle' => t('bg-secondary-subtle'),
    'bg-success' => t('bg-success'),
    'bg-success-subtle' => t('bg-success-subtle'),
    'bg-danger' => t('bg-danger'),
    'bg-danger-subtle' => t('bg-danger-subtle'),
    'bg-warning' => t('bg-warning'),
    'bg-warning-subtle' => t('bg-warning-subtle'),
    'bg-info' => t('bg-info'),
    'bg-purple' => t('bg-purple'),
    'bg-purple-dark' => t('bg-purple-dark'),
    'bg-info-subtle' => t('bg-info-subtle'),
    'bg-transparent' => t('bg-transparent'),
  ];

  // Top Header configs
  $form['flexi_top_header'] = [
    '#type' => 'details',
    '#title' => t('Top Header'),
    '#open' => FALSE,
    '#group' => 'flexistyle_bootstrap_tabs',
  ];
  $form['flexi_top_header']['top_header_classes'] = [
    '#type' => 'textfield',
    '#title' => t('Top Header Classes'),
    '#placeholder' => t('Top Header Classes'),
    '#default_value' => theme_get_setting('top_header_classes'),
    '#description' => t('You can add your custom classes on the <strong>Top Header</strong> i.e: <em>"shadow border-bottom"</em>.'),
  ];

  // Header configs
  $form['flexi_header'] = [
    '#type' => 'details',
    '#title' => t('Header'),
    '#open' => FALSE,
    '#group' => 'flexistyle_bootstrap_tabs',
  ];
  $form['flexi_header']['header_position'] = [
    '#type' => 'select',
    '#title' => t('Header Position'),
    '#default_value' => theme_get_setting('header_position'),
    '#options' => [
      'header-normal' => t('Header Normal'),
      'sticky-top' => t('Header Sticky'),
    ],
  ];
  $form['flexi_header']['header_style'] = [
    '#type' => 'select',
    '#title' => t('Header Styles'),
    '#default_value' => theme_get_setting('header_style'),
    '#options' => [
      'style-1' => t('Style 1'),
      'style-2' => t('Style 2'),
      'style-3' => t('Style 3'),
    ],
  ];
  $form['flexi_header']['header_navbar_bg'] = [
    '#type' => 'select',
    '#title' => t('Header Navbar BG'),
    '#default_value' => theme_get_setting('header_navbar_bg'),
    '#options' => $background,
  ];
  $form['flexi_header']['header_classes'] = [
    '#type' => 'textfield',
    '#title' => t('Header Classes'),
    '#placeholder' => t('Header Classes'),
    '#default_value' => theme_get_setting('header_classes'),
    '#description' => t('You can add your custom classes on the <strong>Header</strong> i.e: <em>"shadow border-bottom"</em>.'),
  ];

  // Sidebar configs
  $form['flexi_sidebar'] = [
    '#type' => 'details',
    '#title' => t('Sidebar'),
    '#open' => FALSE,
    '#group' => 'flexistyle_bootstrap_tabs',
  ];
  $form['flexi_sidebar']['sidebar_block_bg'] = [
    '#type' => 'select',
    '#title' => t('Sidebar Blocks BG'),
    '#default_value' => theme_get_setting('sidebar_block_bg'),
    '#options' => $background,
  ];
  $form['flexi_sidebar']['sidebar_block_classes'] = [
    '#type' => 'textfield',
    '#title' => t('Sidebar Block Classes'),
    '#default_value' => theme_get_setting('sidebar_block_classes'),
    '#description' => t('You can add your custom classes on the <strong>Sidebar First</strong> and <strong>Sidebar Second</strong> Blocks i.e: <em>"shadow border-bottom"</em>.'),
  ];

  // Footer configs
  $form['flexi_footer'] = [
    '#type' => 'details',
    '#title' => t('Footer'),
    '#open' => FALSE,
    '#group' => 'flexistyle_bootstrap_tabs',
  ];
  $form['flexi_footer']['footer_bg'] = [
    '#type' => 'select',
    '#title' => t('Footer BG'),
    '#default_value' => theme_get_setting('footer_bg'),
    '#options' => $background,
  ];
  $form['flexi_footer']['footer_classes'] = [
    '#type' => 'textfield',
    '#title' => t('Footer Classes'),
    '#placeholder' => t('Footer Classes'),
    '#default_value' => theme_get_setting('footer_classes'),
    '#description' => t('You can add your custom classes on the <strong>Footer</strong> i.e: <em>border-top border-4 border-danger text-light</em>.'),
  ];
  $form['flexi_footer']['footer_top_classes'] = [
    '#type' => 'textfield',
    '#title' => t('Footer Top Classes'),
    '#placeholder' => t('Footer Top Classes'),
    '#default_value' => theme_get_setting('footer_top_classes'),
    '#description' => t('You can add your custom classes on the <strong>Footer Top</strong> i.e: <em>"py-4"</em>.'),
  ];
  $form['flexi_footer']['footer_bottom_bg'] = [
    '#type' => 'select',
    '#title' => t('Footer Bottom BG'),
    '#default_value' => theme_get_setting('footer_bottom_bg'),
    '#options' => $background,
  ];
  $form['flexi_footer']['footer_bottom_classes'] = [
    '#type' => 'textfield',
    '#title' => t('Footer Bottom Classes'),
    '#placeholder' => t('Footer Bottom Classes'),
    '#default_value' => theme_get_setting('footer_bottom_classes'),
    '#description' => t('You can add your custom classes on the <strong>Footer Bottom</strong> i.e: <em>"py-3 text-center small"</em>.'),
  ];
}
