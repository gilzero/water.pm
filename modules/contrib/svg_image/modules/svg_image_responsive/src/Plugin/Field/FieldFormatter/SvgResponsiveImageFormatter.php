<?php

namespace Drupal\svg_image_responsive\Plugin\Field\FieldFormatter;

use Drupal\Core\Cache\Cache;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Markup;
use Drupal\file\Entity\File;
use Drupal\responsive_image\Plugin\Field\FieldFormatter\ResponsiveImageFormatter;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Plugin implementation of the 'responsive_image' formatter.
 *
 * We have to fully override standard field formatter, so we will keep original
 * label and formatter ID.
 *
 * @FieldFormatter(
 *   id = "responsive_image",
 *   label = @Translation("Responsive image"),
 *   field_types = {
 *     "image"
 *   },
 *   quickedit = {
 *     "editor" = "image"
 *   }
 * )
 */
class SvgResponsiveImageFormatter extends ResponsiveImageFormatter {

  /**
   * File logger channel.
   *
   * @var \Drupal\Core\Logger\LoggerChannel
   */
  private $logger;

  /**
   * File Url Generator service.
   *
   * @var \Drupal\Core\File\FileUrlGeneratorInterface
   */
  protected $fileUrlGenerator;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    $instance = parent::create($container, $configuration, $plugin_id, $plugin_definition);

    $instance->logger = $container->get('logger.channel.file');
    $instance->fileUrlGenerator = $container->get('file_url_generator');

    return $instance;
  }

  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $elements = [];
    /** @var \Drupal\file\Entity\File[] $files */
    $files = $this->getEntitiesToView($items, $langcode);

    // Early opt-out if the field is empty.
    if (empty($files)) {
      return $elements;
    }

    $url = NULL;
    $imageLinkSetting = $this->getSetting('image_link');
    // Check if the formatter involves a link.
    if ($imageLinkSetting === 'content') {
      $entity = $items->getEntity();
      if (!$entity->isNew()) {
        $url = $entity->toUrl();
      }
    }
    elseif ($imageLinkSetting === 'file') {
      $linkFile = TRUE;
    }

    // Collect cache tags to be added for each item in the field.
    $responsiveImageStyle = $this->responsiveImageStyleStorage->load($this->getSetting('responsive_image_style'));
    $imageStylesToLoad = [];
    $cacheTags = [];
    if ($responsiveImageStyle) {
      $cacheTags = Cache::mergeTags($cacheTags, $responsiveImageStyle->getCacheTags());
      $imageStylesToLoad = $responsiveImageStyle->getImageStyleIds();
    }

    $imageStyles = $this->imageStyleStorage->loadMultiple($imageStylesToLoad);
    foreach ($imageStyles as $image_style) {
      $cacheTags = Cache::mergeTags($cacheTags, $image_style->getCacheTags());
    }

    $svgAttributes = $this->getSetting('svg_attributes');
    foreach ($files as $delta => $file) {
      $attributes = [];
      $isSvg = svg_image_is_file_svg($file);

      if ($isSvg) {
        $attributes = $svgAttributes;
      }

      $cacheContexts = [];
      if (isset($linkFile)) {
        $imageUri = $file->getFileUri();
        $url = $this->fileUrlGenerator->generate($imageUri);
        $cacheContexts[] = 'url.site';
      }
      $cacheTags = Cache::mergeTags($cacheTags, $file->getCacheTags());

      // Link the <picture> element to the original file.
      if (isset($linkFile)) {
        $url = $this->fileUrlGenerator->generateString($file->getFileUri());
      }
      // Extract field item attributes for the theme function, and unset them
      // from the $item so that the field template does not re-render them.
      $item = $file->_referringItem;
      if (isset($item->_attributes)) {
        $attributes += $item->_attributes;
      }
      unset($item->_attributes);

      if (!$isSvg) {
        $elements[$delta] = [
          '#theme' => 'responsive_image_formatter',
          '#item' => $item,
          '#item_attributes' => $attributes,
          '#responsive_image_style_id' => $responsiveImageStyle ? $responsiveImageStyle->id() : '',
          '#url' => $url,
          '#cache' => [
            'tags' => $cacheTags,
          ],
        ];
      }
      elseif ($this->getSetting('svg_render_as_image')) {
        $elements[$delta] = [
          '#theme' => 'image_formatter',
          '#item' => $item,
          '#item_attributes' => $attributes,
          '#image_style' => NULL,
          '#url' => $url,
          '#cache' => [
            'tags' => $cacheTags,
            'contexts' => $cacheContexts,
          ],
        ];
      }
      else {
        // Render as SVG tag.
        $svgRaw = $this->fileGetContents($file);
        if ($svgRaw) {
          $svgRaw = str_replace('<?xml version="1.0" encoding="UTF-8"?>', '', $svgRaw);
          $svgRaw = trim($svgRaw);

          $elements[$delta] = [
            '#markup' => Markup::create($svgRaw),
            '#cache' => [
              'tags' => $cacheTags,
              'contexts' => $cacheContexts,
            ],
          ];
        }
      }
    }

    return $elements;
  }

  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return [
      'svg_attributes' => ['width' => NULL, 'height' => NULL],
      'svg_render_as_image' => TRUE,
    ] + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $element, FormStateInterface $formState) {
    $element = parent::settingsForm($element, $formState);

    $element['svg_render_as_image'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Render SVG image as &lt;img&gt;'),
      '#description' => $this->t('Render SVG images as usual image in IMG tag instead of &lt;svg&gt; tag'),
      '#default_value' => $this->getSetting('svg_render_as_image'),
    ];

    $element['svg_attributes'] = [
      '#type' => 'fieldset',
      '#title' => $this->t('SVG Images dimensions (attributes)'),
      '#tree' => TRUE,
    ];

    $element['svg_attributes']['width'] = [
      '#type' => 'number',
      '#min' => 0,
      '#title' => $this->t('Width'),
      '#size' => 10,
      '#field_suffix' => 'px',
      '#default_value' => $this->getSetting('svg_attributes')['width'],
    ];

    $element['svg_attributes']['height'] = [
      '#type' => 'number',
      '#min' => 0,
      '#title' => $this->t('Height'),
      '#size' => 10,
      '#field_suffix' => 'px',
      '#default_value' => $this->getSetting('svg_attributes')['height'],
    ];

    return $element;
  }

  /**
   * Provides content of the file.
   *
   * @param \Drupal\file\Entity\File $file
   *   File to handle.
   *
   * @return string
   *   File content.
   */
  protected function fileGetContents(File $file) {
    $fileUri = $file->getFileUri();

    if (file_exists($fileUri)) {
      return file_get_contents($fileUri);
    }

    $this->logger->error(
      'File @file_uri (ID: @file_id) does not exists in filesystem.',
      ['@file_id' => $file->id(), '@file_uri' => $fileUri]
    );

    return FALSE;
  }

}
