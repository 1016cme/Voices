<?php

/**
 * @file
 * Wysiwyg API integration.
 */

/**
 * Implements hook_wysiwyg_plugin().
 */
function dexp_shortcode_wysiwyg_dexp_shortcode_wysiwyg_plugin() {
  drupal_add_css(drupal_get_path('module','dexp_shortcode_wysiwyg').'/plugins/font-awesome/css/font-awesome.css');
  $plugins['dexp_shortcode_wysiwyg'] = array(
    'title' => t('DrupalExp Shortcode'),
    'vendor url' => 'http://drupal.org/project/shortcode',
    'icon file' => 'insert.png',
    'icon title' => t('Insert a Shortcode'),
    'settings' => array(),
  );
  return $plugins;
}
