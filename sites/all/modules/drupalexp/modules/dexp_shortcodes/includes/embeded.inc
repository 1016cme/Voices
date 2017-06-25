<?php

function dexp_shortcodes_embeded_shortcode_info(&$shortcodes) {
  $shortcodes['embeded'] = array(
      'title' => t('Embeded block'),
      'description' => t('Embeded content view block '),
      'process callback' => 'dexp_shortcodes_embeded',
      'attributes callback' => 'dexp_shortcodes_embeded_attributes',
      'tips callback' => 'dexp_shortcodes_embeded_tips',
      'cache' => DRUPAL_NO_CACHE,
  );
}

function dexp_shortcodes_embeded($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'block_embed' => '',
  ), $attrs);
  $block_info = explode('--',$attrs['block_embed'],2);
  $module = $block_info[0];
  $delta = $block_info[1];
  $block = block_load($module, $delta);
  $block_array = isset($block->theme) ? _block_get_renderable_array(_block_render_blocks(array($block))) : array();
  return "<!--DRUPAL NO CACHE-->" . render($block_array);
}

function dexp_shortcodes_embeded_attributes($form, &$from_state){
  $block = _get_all_blocks_theme();
  $form['embeded-block_embed'] = array(
    '#title' => t('Choose block'),
    '#type' => 'select',
    '#options' => $block,
  );
  return $form;
}

function _get_all_blocks_theme() {
  module_load_include('inc', 'block', 'block.admin');
  global $theme_key;
  $blocks = block_admin_display_prepare_blocks($theme_key);
  $options = array();
  foreach($blocks as $block){
      if($block['module'] == 'block') continue;
      if($block['module'] == 'system' && $block['delta'] == 'main') continue;
      $value = $block['module'].'--'.$block['delta'];
      $options[$value] = $block['info'];
  }
  return $options;
}

function dexp_shortcodes_preprocess_shortcode_embeded(&$vars) {
  $vars['theme_hook_suggestions'][] = 'shortcode__embeded';
}

function dexp_shortcodes_embeded_tips($long, $format) {
  $output = "[embeded block_embed='module_name--block_delta'][/embeded]";
  return $output;
}
