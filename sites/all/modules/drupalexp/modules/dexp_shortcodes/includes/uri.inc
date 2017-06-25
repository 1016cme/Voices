<?php

function dexp_shortcodes_uri_shortcode_info(&$shortcodes) {
  $shortcodes['uri'] = array(
      'title' => t('Drupal URI'),
      'description' => t('Use file URI in content'),
      'process callback' => 'dexp_shortcodes_uri',
      'tips callback' => 'dexp_shortcodes_uri_tips',
  );
  $shortcodes['url'] = array(
      'title' => t('Drupal URL'),
      'description' => t('Use url in content'),
      'process callback' => 'dexp_shortcodes_url',
      'tips callback' => 'dexp_shortcodes_url_tips',
  );
}

function dexp_shortcodes_uri($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'uri' => '',
  ), $attrs);
  return file_create_url($attrs['uri']);
}

function dexp_shortcodes_url($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'url' => '',
  ), $attrs);
  return url($attrs['url']);
}
