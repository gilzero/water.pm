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

$form['drupal8_w3css_theme_settings']['w3_fontawesome_libraries'] = [
  '#type' => 'details',
  '#title' => t('Font awesome - W3CSS Theme'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description'   => t("<p>Font awesome is now not enabled by default. All the default theme's icons were replaced by svg images. You can enable this library if you are using any font awesome icons in your site.</p>"),
];

$form['drupal8_w3css_theme_settings']['w3_fontawesome_libraries']['d8w3css_font_awesome'] = [
  '#type' => 'radios',
  '#title' => t('Select Font Awesome Library'),
  '#default_value' => theme_get_setting('d8w3css_font_awesome'),
  '#options' => [
    0 => t('None'),
    1 => t('Load Font Awesome 4.7 locally.'),
    2 => t('Load Font Awesome 4.7 from the CDN.'),
    3 => t('Load Font Awesome 5.15.4 from the CDN.'),
    4 => t('Load Font Awesome 6.1.1 from the CDN.'),
  ],
];

$form['drupal8_w3css_theme_settings']['w3_external_libraries'] = [
  '#type' => 'details',
  '#title' => t('Google Fonts - W3CSS Theme'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  '#description'   => t('<p>Any font you choose for the site, heading or special will have a CSS class that you can apply to any html tag. <a target="_blank" href="https://www.drupal.org/node/2866181#change-font">click here to view the documentaion on drupal.org</a></p>'),
];

$form['drupal8_w3css_theme_settings']['w3_external_libraries']['d8w3css_google_font_local'] = [
  '#type' => 'checkbox',
  '#title' => t('Check this box if you would like to load Google fonts (Global Site Fonts and Heading Fonts only) locally. This is for use with the W3CSS Theme.'),
  '#default_value' => theme_get_setting('d8w3css_google_font_local'),
];

$form['drupal8_w3css_theme_settings']['w3_external_libraries']['d8w3css_site_gf'] = [
  '#type' => 'select',
  '#title' => t('50 Global Site Fonts: Choose the site font - The font will be applied to the whole website.<a target="_blank" href="flex6.com/node/105"> Click here to view a live demo for all available fonts.</a>'),
  '#description'   => t('<p>Global Site Font CSS Classes: open-sans, abel, alegreya-sans, alegreya-sans-sc, amita, archivo-narrow, arimo, arvo, barlow, barlow-semi-condensed
, bitter, cairo, comfortaa, courgette, domine, dosis, exo-2, fira-sans, glegoo, hind-siliguri, ibm-plex-sans, inconsolata, josefin-sans, kanit, kavivanar, lato, libre-baskerville, lora, merienda, merriweather, montserrat, mukta, nunito, oranienbaum, oswald, oxygen, playfair-display, poppins, prompt, pt-serif, quicksand, raleway, roboto, roboto-condensed, roboto-mono, spline-sans, source-sans-3, titillium-web, ubuntu, work-sans. </p>'),
  '#options' => [
    'none' => t('None'),
    'd8w3css-abel' => t('Abel - sans-serif'),
    'd8w3css-alegreya-sans' => t('Alegreya Sans - sans-serif'),
    'd8w3css-alegreya-sans-sc' => t('Alegreya Sans SC - sans-serif'),
    'd8w3css-amita' => t('Amita - cursive'),
    'd8w3css-archivo-narrow' => t('Archivo Narrow - sans-serif'),
    'd8w3css-arimo' => t('Arimo - sans-serif'),
    'd8w3css-arvo' => t('Arvo - serif'),
    'd8w3css-barlow' => t('Barlow - sans-serif'),
    'd8w3css-barlow-semi-condensed' => t('Barlow Semi Condensed - sans-serif'),
    'd8w3css-bitter' => t('Bitter - serif'),
    'd8w3css-cairo' => t('Cairo - sans-serif'),
    'd8w3css-comfortaa' => t('Comfortaa - cursive'),
    'd8w3css-courgette' => t('Courgette - cursive'),
    'd8w3css-domine' => t('Domine - serif'),
    'd8w3css-dosis' => t('Dosis - sans-serif'),
    'd8w3css-exo-2' => t('EXO 2 - sans-serif'),
    'd8w3css-fira-sans' => t('Fira Sans - sans-serif'),
    'd8w3css-glegoo' => t('Glegoo - serif'),
    'd8w3css-hind-siliguri' => t('Hind Siliguri - sans-serif'),
    'd8w3css-ibm-plex-sans' => t('IBM Plex Sans - sans-serif'),
    'd8w3css-inconsolata' => t('Inconsolata - monospace'),
    'd8w3css-josefin-sans' => t('Josefin Sans  - sans-serif'),
    'd8w3css-kanit' => t('Kanit - sans-serif'),
    'd8w3css-kavivanar' => t('Kavivanar - cursive'),
    'd8w3css-lato' => t('Lato - sans-serif'),
    'd8w3css-libre-baskerville' => t('Libre Baskerville  - serif'),
    'd8w3css-lora' => t('Lora - serif'),
    'd8w3css-merienda' => t('Merienda - cursive'),
    'd8w3css-merriweather' => t('Merriweather  - serif'),
    'd8w3css-montserrat' => t('Montserrat - sans-serif'),
    'd8w3css-mukta' => t('Mukta - sans-serif'),
    'd8w3css-nunito' => t('Nunito - sans-serif'),
    'd8w3css-open-sans' => t('Open Sans - sans-serif'),
    'd8w3css-oranienbaum' => t('Oranienbaum - serif'),
    'd8w3css-oswald' => t('Oswald - sans-serif'),
    'd8w3css-oxygen' => t('Oxygen - sans-serif'),
    'd8w3css-playfair-display' => t('Playfair Display - serif'),
    'd8w3css-poppins' => t('Poppins - sans-serif'),
    'd8w3css-prompt' => t('Prompt - sans-serif'),
    'd8w3css-pt-serif' => t('PT Serif - serif'),
    'd8w3css-quicksand' => t('Quicksand - sans-serif'),
    'd8w3css-raleway' => t('Raleway - sans-serif'),
    'd8w3css-roboto' => t('Roboto - sans-serif'),
    'd8w3css-roboto-condensed' => t('Roboto Condensed - sans-serif'),
    'd8w3css-roboto-mono' => t('Roboto Mono - monospace'),
    'd8w3css-spline-sans' => t('Spline Sans - sans-serif'),
    'd8w3css-source-sans-3' => t('Source Sans 3 - sans-serif'),
    'd8w3css-titillium-web' => t('Titillium Web - sans-serif'),
    'd8w3css-ubuntu' => t('Ubuntu - sans-serif'),
    'd8w3css-work-sans' => t('Work Sans - sans-serif'),

  ],
  '#default_value' => theme_get_setting('d8w3css_site_gf'),
];

$form['drupal8_w3css_theme_settings']['w3_external_libraries']['d8w3css_site_gfh'] = [
  '#type' => 'select',
  '#title' => t('26 Heading Fonts: Choose the heading font - The font will be applied to h1, h2 and h3 only.<a target="_blank" href="flex6.com/node/104"> Click here to view a live demo for all available fonts.</a>'),
  '#description'   => t('<p>THeading Font CSS Classes: abril-fatface, aladin, anton, archivo-black, bebas-neue, big-shoulders-stencil-display, big-shoulders-stencil-text, black-ops-one, bree-serif, cinzel, dancing-script, dm-serif-display, doppio-one, fjalla-one, francois-one, fredericka-the-great, fredoka, hammersmith-one, indie-flower, kalam, lobster-two, patrick-hand, prosto-one, righteous, staatliches, yanone-kaffeesatz.</p>'),
  '#options' => [
    'none' => t('None'),
    'd8w3css-abril-fatface' => t('Abril Fatface  - cursive'),
    'd8w3css-aladin' => t('Aladin  - cursive'),
    'd8w3css-anton' => t('Anton  - sans-serif'),
    'd8w3css-archivo-black' => t('Archivo Black - sans-serif'),
    'd8w3css-bebas-neue' => t('Bebas Neue - cursive'),
    'd8w3css-big-shoulders-stencil-display' => t('Big Shoulders Stencil Display - cursive'),
    'd8w3css-big-shoulders-stencil-text' => t('Big Shoulders Stencil Text - cursive'),
    'd8w3css-black-ops-one' => t('Black Ops One - cursive'),
    'd8w3css-bree-serif' => t('Bree Serif - serif'),
    'd8w3css-cinzel' => t('Cinzel - serif'),
    'd8w3css-dancing-script' => t('Dancing Script - cursive'),
    'd8w3css-dm-serif-display' => t('DM Serif Display - serif'),
    'd8w3css-doppio-one' => t('Doppio - sans-serif'),
    'd8w3css-fjalla-one' => t('Fjalla One - sans-serif'),
    'd8w3css-francois-one' => t('Francois One - sans-serif'),
    'd8w3css-fredericka-the-great' => t('Fredericka The Great  - cursive'),
    'd8w3css-fredoka' => t('Fredoka - cursive'),
    'd8w3css-hammersmith-one' => t('Hammersmith One - sans-serif'),
    'd8w3css-indie-flower' => t('Indie Flower - cursive'),
    'd8w3css-kalam' => t('Kalam - cursive'),
    'd8w3css-lobster-two' => t('Lobster Two - cursive'),
    'd8w3css-patrick-hand' => t('Patrick Hand - cursive'),
    'd8w3css-prosto-one' => t('Prosto One - cursive'),
    'd8w3css-righteous' => t('Righteous - cursive'),
    'd8w3css-staatliches' => t('Staatliches - cursive'),
    'd8w3css-yanone-kaffeesatz' => t('Yanone Kaffeesatz - sans-serif'),

  ],
  '#default_value' => theme_get_setting('d8w3css_site_gfh'),
];

$form['drupal8_w3css_theme_settings']['w3_external_libraries']['d8w3css_site_gfs'] = [
  '#type' => 'select',
  '#title' => t('25 Special Fonts: They are not applied to any html tags by default and they are only imported. Each font library has a CSS class that you can apply to any html tag. <a target="_blank" href="flex6.com/node/102">Click here to view a live demo for all available fonts.</a>'),
  '#description'   => t('<p>Spcial Font CSS Classes: akronim, barriecito, bungee-shade, ceviche-one, creepster, faster-one, finger-paint, frijole, irish-grover, kumar-one, londrina-outline, megrim, metal-mania, monoton, moo-lah-lah, new-rocker, nosifer, pirata-one, ruslan-display, rye, sancreek, slackey, trade-winds, train-one, unifrakturmaguntia.</p>'),
  '#options' => [
    'none' => t('None'),
    'd8w3css-akronim' => t('akronim - cursive'),
    'd8w3css-barriecito' => t('barriecito - cursive'),
    'd8w3css-bungee-shade' => t('bungee-shade - cursive'),
    'd8w3css-ceviche-one' => t('ceviche-one - cursive'),
    'd8w3css-creepster' => t('creepster - cursive'),
    'd8w3css-faster-one' => t('faster-one - cursive'),
    'd8w3css-finger-paint' => t('finger-paint - cursive'),
    'd8w3css-frijole' => t('frijole - cursive'),
    'd8w3css-irish-grover' => t('irish-grover - cursive'),
    'd8w3css-kumar-one' => t('kumar-one - cursive'),
    'd8w3css-londrina-outline' => t('londrina-outline - cursive'),
    'd8w3css-megrim' => t('megrim - cursive'),
    'd8w3css-metal-mania' => t('metal-mania - cursive'),
    'd8w3css-monoton' => t('monoton - cursive'),
    'd8w3css-moo-lah-lah' => t('moo-lah-lah - cursive'),
    'd8w3css-new-rocker' => t('new-rocker - cursive'),
    'd8w3css-nosifer' => t('nosifer - cursive'),
    'd8w3css-pirata-one' => t('pirata-one - cursive'),
    'd8w3css-ruslan-display' => t('ruslan-display - cursive'),
    'd8w3css-rye' => t('rye - cursive'),
    'd8w3css-sancreek' => t('sancreek - cursive'),
    'd8w3css-slackey' => t('slackey - cursive'),
    'd8w3css-trade-winds' => t('trade-winds - cursive'),
    'd8w3css-train-one' => t('train-one - cursive'),
    'd8w3css-unifrakturmaguntia' => t('unifrakturmaguntia - cursive'),

  ],
  '#default_value' => theme_get_setting('d8w3css_site_gfs'),
];
