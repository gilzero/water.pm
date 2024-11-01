<?php

namespace Drupal\fortytwo;

use Composer\Script\Event;
use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Finder\Finder;

class ScriptHandler {
  public static function subtheme(Event $event) {

    // Get safe subtheme machine name from args.
    $sub_name = 'fortytwo_subtheme';
    $args = $event->getArguments();
    if (!empty($args)) {
      $input = $args[0];
      $strip_chars = preg_replace('/[^a-zA-Z\_\s]*/', '', $input);
      $strip_space = preg_replace('/\s+/', '_', $strip_chars);
      $sub_name = strtolower($strip_space);
    }

    // Copy STARTERKIT to parent dir.
    $fs = new Filesystem();
    $fs->mirror(getcwd() . '/STARTERKIT', '../../custom/' . $sub_name);

    // Rename STARTERKIT.* files
    $finder = new Finder();
    $finder->files()->name('/STARTERKIT/')->in('../../custom/' . $sub_name);

    foreach ($finder as $file) {
      $location_segments = explode('/', $file->getRealPath());
      $old_filename = array_pop($location_segments);
      $location = implode('/', $location_segments) . '/';

      $new_filename = preg_replace('/STARTERKIT/', $sub_name, $old_filename);

      $fs->rename($file->getRealPath(), $location . $new_filename);
    }

    // Activate subtheme .info file.
    $finder = new Finder();
    $finder->files()->name('*.ymltmp')->in('../../custom/' . $sub_name);

    foreach ($finder as $file) {
      $location_segments = explode('/', $file->getRealPath());
      $old_filename = array_pop($location_segments);
      $location = implode('/', $location_segments) . '/';

      $new_filename = preg_replace('/ymltmp/', 'yml', $old_filename);

      $fs->rename($file->getRealPath(), $location . $new_filename);
    }

    // Replace STARTERKIT in file contents.
    $finder = new Finder();
    $finder->files()->contains('/STARTERKIT/')->in('../../custom/' . $sub_name);

    foreach ($finder as $file) {
      $old_contents = file_get_contents($file->getRealPath());

      $new_contents = preg_replace('/STARTERKIT/', $sub_name, $old_contents);

      file_put_contents($file->getRealPath(), $new_contents);
    }
  }
}
