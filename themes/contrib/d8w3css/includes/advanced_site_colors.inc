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

$form['drupal8_w3css_theme_settings']['w3_colors'] = [
  '#type' => 'details',
  '#title' => t('Advanced Site Colors - W3CSS Theme'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description'   => t("

<h2>This is a visual guide to show each region's placement on the page. Click on the name to go to the field.</h2>


<table border='1' cellpadding='8' style='width: 100%;  color:LightSlateGray; font-size: 16px; font-family: Helvetica; text-align: center;border-collapse: collapse; border:3px solid LightBlue'>
  <tbody>
    <tr>
      <td style='text-align: center;'>
      <h1><a href='#edit-color-primary-menu'>Main Navigation - Vertical</a></h1>
      <p>Visible on all pages - W3.CSS Color Theme Class w3-theme</p>
      </td>
    </tr>
  </tbody>
</table>
<table cellpadding='8' style='width: 100%;  color: LightSlateGray; font-size: 16px; font-family: Helvetica; border-collapse: collapse; border:3px solid LightBlue'>
  <tbody>
    <tr>
      <td style='text-align: center;'>
      <h1><a href='#edit-color-page-wrapper'>Page Wrapper</a></h1>
      <table cellpadding='6' style='width: 100%;'>
        <tbody>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%; border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-header'>Header</a></h1>
                  <p>Visible on all pages - W3.CSS Color Theme Class w3-theme-l4</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-primary-menu'>Main Navigation - Horizontal</a></h1>
                  <p>Visible on all pages - W3.CSS Color Theme Class w3-theme</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-welcome-text'>Welcome Text</a></h1>
                  <p>Visible on front page only - W3.CSS Color Theme Class w3-theme-l5</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-highlighted'>Highlighted</a></h1>
                  <p>Visible on all pages - W3.CSS Color Theme Class w3-theme-l2</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td style='text-align: center;'>
            <h1><a href='#edit-color-top-container'>Top Container Wrapper</a></h1>
            <p>Visible on front page only - W3.CSS Color Theme Class w3-theme-l4</p>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-top-first'>Top First</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-top-second'>Top Second</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-top-third'>Top Third</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-page-title'>Page Title</a></h1>
                  <p>Visible on all pages except front page - W3.CSS Color Theme Class w3-theme-d5</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td style='text-align: center;'>
            <h1><a href='#edit-color-main'>Main Container Wrapper</a></h1>
            <p>Visible on all pages - W3.CSS Color Theme Class w3-theme-l5</p>
            <p>Main Container (Left SideBar - W3CSS Content - Right SideBar) can be (25% - 50% - 25%) or (33% - 33% - 33%).</p>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h2><a href='#edit-color-breadcrumb'>Breadcrumb</a></h2>
                  </td>
                </tr>
              </tbody>
            </table>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-sidebar-first'>Left SideBar</a></h2>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-content'>W3CSS Content</a></h2>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-sidebar-second'>Right SideBar</a></h2>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td style='text-align: center;'>
            <h1><a href='#edit-color-bottom-container'>Bottom Container Wrapper</a></h1>
            Visible on front page only - W3.CSS Color Theme Class w3-theme-l2
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-bottom-first'>Bottom First</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-bottom-second'>Bottom Second</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-bottom-third'>Bottom Third</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-bottom-forth'>Bottom Forth</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td style='text-align: center;'>
            <h1><a href='#edit-color-footer-container'>Footer Container Wrapper</a></h1>
            Visible on all pages - W3.CSS Color Theme Class w3-theme-d3
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-footer-first'>Footer First</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-footer-second'>Footer Second</a></h2>
                  <p>w3-theme-l5</p>
                  </td>
                  <td style='text-align: center; border:1px solid LightBlue;'>
                  <h2><a href='#edit-color-footer-third'>Footer Third</a></h2>
                  <p>w3-theme-l4</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-footer-menu'>Footer Menu</a></h1>
                  <p>Visible on all pages - W3.CSS Color Theme Class w3-theme-d4</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
          <tr>
            <td>
            <table cellpadding='5' style='width: 100%;border-collapse: collapse; border:3px solid LightBlue'>
              <tbody>
                <tr>
                  <td style='text-align: center;'>
                  <h1><a href='#edit-color-copyright'>Copyright</a></h1>
                  <p>Visible on all pages - W3.CSS Color Theme Class w3-theme-d5</p>
                  </td>
                </tr>
              </tbody>
            </table>
            </td>
          </tr>
        </tbody>
      </table>
      </td>
    </tr>
  </tbody>
</table>

<table style='width: 100%; line-height:1.6;  color: LightSlateGray; font-size: 16px; font-family: Helvetica;'>
<tr>
  <td> </td>
  <th><strong>To utilize the following classes, the w3.css library needs to be activated. Any of the CSS classes can be copied and pasted into the text field. It's possible to paste multiple classes, just ensure there is a space separating each one.</strong></th>
 </tr>

  <tr>
    <th>Background Colors w3-<em>color</em>:</th>
    <td>w3-red, w3-pink, w3-purple, w3-deep-purple, w3-indigo, w3-blue, w3-light-blue, w3-cyan, w3-aqua, w3-teal, w3-green, w3-light-green, w3-lime, w3-sand, w3-khaki, w3-yellow, w3-amber, w3-orange, w3-deep-orange, w3-blue-grey, w3-brown, w3-light-grey, w3-grey, w3-dark-grey, w3-black, w3-white, w3-pale-red, w3-pale-yellow, w3-pale-green and w3-pale-blue. <a target='_blank' href='https://flex6.com/node/169'>Click here to view a live demo for the CSS classes</a></td>
  </tr>
  <tr>
    <th>Background Hover Colors w3-hover-<em>color</em>:</th>
    <td>w3-hover-red, w3-hover-pink, w3-hover-purple, w3-hover-deep-purple, w3-hover-indigo, w3-hover-blue, w3-hover-light-blue, w3-hover-cyan, w3-hover-aqua, w3-hover-teal, w3-hover-green, w3-hover-light-green, w3-hover-lime, w3-hover-sand, w3-hover-khaki, w3-hover-yellow, w3-hover-amber, w3-hover-orange, w3-hover-deep-orange, w3-hover-blue-grey, w3-hover-brown, w3-hover-light-grey, w3-hover-grey, w3-hover-dark-grey, w3-hover-black, w3-hover-white, w3-hover-pale-red, w3-hover-pale-yellow, w3-hover-pale-green and w3-hover-pale-blue. <a target='_blank' href='https://flex6.com/node/168'>Click here to view a live demo for the CSS classes</a></td>
  </tr>

  <tr>
    <th>Text Colors w3-text-<em>color</em>:</th>
    <td>w3-text-red, w3-text-pink, w3-text-purple, w3-text-deep-purple, w3-text-indigo, w3-text-blue, w3-text-light-blue, w3-text-cyan, w3-text-aqua, w3-text-teal, w3-text-green, w3-text-light-green, w3-text-lime, w3-text-sand, w3-text-khaki, w3-text-yellow, w3-text-amber, w3-text-orange, w3-text-deep-orange, w3-text-blue-grey, w3-text-brown, w3-text-light-grey, w3-text-grey, w3-text-dark-grey, w3-text-black, w3-text-white , w3-text-pale-red, w3-text-pale-yellow, w3-text-pale-green and w3-text-pale-blue. <a target='_blank' href='https://flex6.com/node/124'>Click here to view a live demo for the CSS classes</a></td>
  </tr>
  <tr>
    <th>Text Hover Colors w3-hover-text-<em>color</em>:</th>
    <td>w3-hover-text-red, w3-hover-text-pink, w3-hover-text-purple, w3-hover-text-deep-purple, w3-hover-text-indigo, w3-hover-text-blue, w3-hover-text-light-blue, w3-hover-text-cyan, w3-hover-text-aqua, w3-hover-text-teal, w3-hover-text-green, w3-hover-text-light-green, w3-hover-text-lime, w3-hover-text-sand, w3-hover-text-khaki, w3-hover-text-yellow, w3-hover-text-amber, w3-hover-text-orange, w3-hover-text-deep-orange, w3-hover-text-blue-grey, w3-hover-text-brown, w3-hover-text-light-grey, w3-hover-text-grey, w3-hover-text-dark-grey, w3-hover-text-black and w3-hover-text-white, w3-hover-text-pale-red, w3-hover-text-pale-yellow, w3-hover-text-pale-green and w3-hover-text-pale-blue. <a target='_blank' href='https://flex6.com/node/143'>Click here to view a live demo for the CSS classes</a></td>
  </tr>

  <tr>
    <th>Link Text Colors w3-link-<em>color</em>:</th>
    <td>w3-link-red, w3-link-pink, w3-link-purple, w3-link-deep-purple, w3-link-indigo, w3-link-blue, w3-link-light-blue, w3-link-cyan, w3-link-aqua, w3-link-teal, w3-link-green, w3-link-light-green, w3-link-lime, w3-link-sand, w3-link-khaki, w3-link-yellow, w3-link-amber, w3-link-orange, w3-link-deep-orange, w3-link-blue-grey, w3-link-brown, w3-link-light-grey, w3-link-grey, w3-link-dark-grey, w3-link-black and w3-link-white, w3-link-pale-red, w3-link-pale-yellow, w3-link-pale-green and w3-link-pale-blue. <a target='_blank' href='https://flex6.com/node/135'>Click here to view a live demo for the CSS classes</a></td>
  </tr>

  <tr>
    <th>Link Background Colors w3-link-bg-<em>color</em>:</th>
    <td>w3-link-bg-red, w3-link-bg-green, w3-link-bg-blue, w3-link-bg-yellow, w3-link-bg-white, w3-link-bg-black, w3-link-bg-grey, w3-link-bg-amber, w3-link-bg-aqua, w3-link-bg-light-blue, w3-link-bg-brown, w3-link-bg-cyan, w3-link-bg-blue-grey, w3-link-bg-blue-gray, w3-link-bg-light-green, w3-link-bg-indigo, w3-link-bg-khaki, w3-link-bg-lime, w3-link-bg-orange, w3-link-bg-deep-orange, w3-link-bg-pink, w3-link-bg-purple, w3-link-bg-deep-purple, w3-link-bg-sand, w3-link-bg-teal, w3-link-bg-light-gray, w3-link-bg-light-grey, w3-link-bg-dark-gray, w3-link-bg-dark-grey, w3-link-bg-pale-red, w3-link-bg-pale-yellow, w3-ling-bg-pale-green and w3-link-bg-pale-blue. <a target='_blank' https://flex6.com/node/137'>Click here to view a live demo for the CSS classes</a></td>
  </tr>

  <tr>
    <th>Link Background Hover Colors w3-link-hover-<em>color</em>:</th>
    <td>w3-link-hover-red, w3-link-hover-green, w3-link-hover-blue, w3-link-hover-yellow, w3-link-hover-white, w3-link-hover-black, w3-link-hover-grey, w3-link-hover-amber, w3-link-hover-aqua, w3-link-hover-light-blue, w3-link-hover-brown, w3-link-hover-cyan, w3-link-hover-blue-grey, w3-link-hover-blue-gray, w3-link-hover-light-green, w3-link-hover-indigo, w3-link-hover-khaki, w3-link-hover-lime, w3-link-hover-orange, w3-link-hover-deep-orange, w3-link-hover-pink, w3-link-hover-purple, w3-link-hover-deep-purple, w3-link-hover-sand, w3-link-hover-teal, w3-link-hover-light-gray, w3-link-hover-light-grey, w3-link-hover-dark-gray, w3-link-hover-dark-grey, w3-link-hover-pale-red, w3-link-hover-pale-yellow, w3-link-hover-pale-green and w3-link-hover-pale-blue. <a target='_blank' href='https://flex6.com/node/136'>Click here to view a live demo for the CSS classes</a></td>
  </tr>

  <tr>
    <th>Button Colors w3-button-<em>color</em>:</th>
    <td>w3-button-red, w3-button-green, w3-button-blue, w3-button-yellow, w3-button-white, w3-button-black, w3-button-gray, w3-button-grey, w3-button-amber, w3-button-aqua, w3-button-light-blue, w3-button-brown, w3-button-cyan, w3-button-blue-grey, w3-button-blue-gray, w3-button-light-green, w3-button-indigo, w3-button-khaki, w3-button-lime, w3-button-orange, w3-button-deep-orange, w3-button-pink, w3-button-purple, w3-button-deep-purple, w3-button-sand, w3-button-teal, w3-button-light-gray, w3-button-light-grey, w3-button-dark-gray, w3-button-dark-grey, w3-button-pale-red, w3-button-pale-yellow, w3-button-pale-green and w3-button-pale-blue. <a target='_blank' href='https://flex6.com/node/162'>Click here to view a live demo for the CSS classes</a></td>
  </tr>

  <tr>
    <th>Button Hover Colors w3-button-hover-<em>color</em>:</th>
    <td>w3-button-hover-red, w3-button-hover-green, w3-button-hover-blue, w3-button-hover-yellow, w3-button-hover-white, w3-button-hover-black, w3-button-hover-gray, w3-button-hover-grey, w3-button-hover-amber, w3-button-hover-aqua, w3-button-hover-light-blue, w3-button-hover-brown, w3-button-hover-cyan, w3-button-hover-blue-grey, w3-button-hover-blue-gray, w3-button-hover-light-green, w3-button-hover-indigo, w3-button-hover-khaki, w3-button-hover-lime, w3-button-hover-orange, w3-button-hover-deep-orange, w3-button-hover-pink, w3-button-hover-purple, w3-button-hover-deep-purple, w3-button-hover-sand, w3-button-hover-teal, w3-button-hover-light-gray, w3-button-hover-light-grey, w3-button-hover-dark-gray, w3-button-hover-dark-grey, w3-button-hover-pale-red, w3-button-hover-pale-yellow, w3-button-hover-pale-green and w3-button-hover-pale-blue. <a target='_blank' href='https://flex6.com/node/161'>Click here to view a live demo for the CSS classes</a></td>
  </tr>
</table>"),
];

$form['drupal8_w3css_theme_settings']['w3_colors']['color_page_wrapper'] = [
  '#type' => 'textfield',
  '#title' => t('Page Wrapper'),
  '#default_value' => theme_get_setting('color_page_wrapper'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_header'] = [
  '#type' => 'textfield',
  '#title' => t('Header'),
  '#default_value' => theme_get_setting('color_header'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_primary_menu'] = [
  '#type' => 'textfield',
  '#title' => t('Main Menu'),
  '#default_value' => theme_get_setting('color_primary_menu'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_welcome_text'] = [
  '#type' => 'textfield',
  '#title' => t('Welcome Text'),
  '#default_value' => theme_get_setting('color_welcome_text'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_highlighted'] = [
  '#type' => 'textfield',
  '#title' => t('Highlighted'),
  '#default_value' => theme_get_setting('color_highlighted'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_top_container'] = [
  '#type' => 'textfield',
  '#title' => t('Top Container Wrapper'),
  '#default_value' => theme_get_setting('color_top_container'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_top_first'] = [
  '#type' => 'textfield',
  '#title' => t('Top First'),
  '#default_value' => theme_get_setting('color_top_first'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_top_second'] = [
  '#type' => 'textfield',
  '#title' => t('Top Second'),
  '#default_value' => theme_get_setting('color_top_second'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_top_third'] = [
  '#type' => 'textfield',
  '#title' => t('Top Third'),
  '#default_value' => theme_get_setting('color_top_third'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_page_title'] = [
  '#type' => 'textfield',
  '#title' => t('Page Title'),
  '#default_value' => theme_get_setting('color_page_title'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_main'] = [
  '#type' => 'textfield',
  '#title' => t('Main Container Wrapper'),
  '#default_value' => theme_get_setting('color_main'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_breadcrumb'] = [
  '#type' => 'textfield',
  '#title' => t('Breadcrumb'),
  '#default_value' => theme_get_setting('color_breadcrumb'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_sidebar_first'] = [
  '#type' => 'textfield',
  '#title' => t('Sidebar First'),
  '#default_value' => theme_get_setting('color_sidebar_first'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_content'] = [
  '#type' => 'textfield',
  '#title' => t('W3CSS Content'),
  '#default_value' => theme_get_setting('color_content'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_sidebar_second'] = [
  '#type' => 'textfield',
  '#title' => t('Sidebar Second'),
  '#default_value' => theme_get_setting('color_sidebar_second'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_bottom_container'] = [
  '#type' => 'textfield',
  '#title' => t('Bottom Container Wrapper'),
  '#default_value' => theme_get_setting('color_bottom_container'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_bottom_first'] = [
  '#type' => 'textfield',
  '#title' => t('Bottom First'),
  '#default_value' => theme_get_setting('color_bottom_first'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_bottom_second'] = [
  '#type' => 'textfield',
  '#title' => t('Bottom Second'),
  '#default_value' => theme_get_setting('color_bottom_second'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_bottom_third'] = [
  '#type' => 'textfield',
  '#title' => t('Bottom Third'),
  '#default_value' => theme_get_setting('color_bottom_third'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_bottom_forth'] = [
  '#type' => 'textfield',
  '#title' => t('Bottom Forth'),
  '#default_value' => theme_get_setting('color_bottom_forth'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_footer_container'] = [
  '#type' => 'textfield',
  '#title' => t('Footer Container Wrapper'),
  '#default_value' => theme_get_setting('color_footer_container'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_footer_first'] = [
  '#type' => 'textfield',
  '#title' => t('Footer First'),
  '#default_value' => theme_get_setting('color_footer_first'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_footer_second'] = [
  '#type' => 'textfield',
  '#title' => t('Footer Second'),
  '#default_value' => theme_get_setting('color_footer_second'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_footer_third'] = [
  '#type' => 'textfield',
  '#title' => t('Footer Third'),
  '#default_value' => theme_get_setting('color_footer_third'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_footer_menu'] = [
  '#type' => 'textfield',
  '#title' => t('Footer Menu'),
  '#default_value' => theme_get_setting('color_footer_menu'),
];
$form['drupal8_w3css_theme_settings']['w3_colors']['color_copyright'] = [
  '#type' => 'textfield',
  '#title' => t('Copyright'),
  '#default_value' => theme_get_setting('color_copyright'),
];
