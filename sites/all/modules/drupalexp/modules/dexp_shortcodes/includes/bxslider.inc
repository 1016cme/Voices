<?php

function dexp_shortcodes_process_page(&$variables) {
  //$path = drupal_get_path('module', 'dexp_shortcodes');  
  //drupal_add_js($path . '/asset/js/dexp_shortcode_bxslider.js');  
  //drupal_add_js($path . '/asset/js/modernizr-latest.js');
  //drupal_add_js($path . '/asset/js/jquery.3dgallery.js');
}

function dexp_shortcodes_bxslider_shortcode_info(&$shortcodes) {
  $shortcodes['bxslider'] = array(
      'title' => t('Bx Slider'),
      'description' => t('Bx Slider'),
      'process callback' => 'dexp_shortcodes_bxslider',
      'attributes callback' => 'dexp_shortcodes_bxslider_attributes',
      'tips callback' => 'dexp_shortcodes_bxslider_tips',
  );
}

function dexp_shortcodes_bxitem_shortcode_info(&$shortcodes) {
  $shortcodes['bxitem'] = array(
      'title' => t('Bx Slider Item'),
      'description' => t('Bx Slider Item'),
      'attributes callback' => 'dexp_shortcodes_bxitem_attributes',
      'process callback' => 'dexp_shortcodes_bxitem',
  );
}

function dexp_shortcodes_bxslider_attributes($form, &$form_state) {
  $form['bxslider-auto'] = array(
    '#title' => t('Auto Slide'),
    '#type' => 'checkbox',
    '#options' => array("false" => "False", "true" => "True"),
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'bxslider'),
      ),
    ),
  );
  $form['bxslider-control'] = array(
    '#title' => t('Show Control'),
    '#type' => 'checkbox',
    '#options' => array("false" => "False", "true" => "True"),
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'bxslider'),
      ),
    ),
  );
  $form['bxslider-pager'] = array(
    '#title' => t('Show Pager'),
    '#type' => 'checkbox',
    '#options' => array("false" => "False", "true" => "True"),
  );
  $form['bxslider-min'] = array(
    '#title' => t('Min item'),
    '#type' => 'textfield',
    '#default_value' => '1',
  );
  $form['bxslider-max'] = array(
    '#title' => t('Max items'),
    '#type' => 'textfield',
    '#default_value' => '1',
  );
  $form['bxslider-width'] = array(
    '#title' => t('Item width'),
    '#type' => 'textfield',
    '#default_value' => '200',
  );
  $form['bxslider-margin'] = array(
    '#title' => t('Margin item'),
    '#type' => 'textfield',
    '#default_value' => '0',
  );
  return $form;
}

function dexp_shortcodes_bxitem_attributes($form, &$form_state) {
    $form['bxitem-content'] = array(
    '#title' => t('Content'),
    '#type' => 'textarea',
  );
  return $form;
}

function dexp_shortcodes_bxslider($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'auto' => "false",
      'control' => "false",
      'pager' => "true",
      'min' => 1,
      'max' => 1,
      'move' => 1,
      'width' => 0,
      'margin' => 0,
      'class' => ''),$attrs);
  $attrs['content'] = $text;
  return trim(theme('dexp_shortcodes_bxslider', $attrs));
}

function dexp_shortcodes_bxitem($attrs, $text) {
  $attrs = shortcode_attrs(array('id' => ''),$attrs);  
  $attrs['content'] = $text;
  return theme('dexp_shortcodes_bxitem', $attrs);
}

function dexp_shortcodes_bxslider_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_bxslider'] = array(
      'template' => 'bxslider',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_bxslider',
      ),
      'variables' => array(
        'auto' => "false",
        'control' => "false",
        'pager' => "true",
        'min' => 1,
        'max' => 1,
        'move' => 1,
        'width' => 0,
        'margin' => 0,
        'class' => '',
        'content' => '',
      )
  );
}

function dexp_shortcodes_bxitem_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_bxitem'] = array(
      'template' => 'bxitem',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_bxitem',
      ),
      'variables' => array(
        'content' => '',
      )
  );
}

function dexp_shortcodes_preprocess_shortcode_bxslider(&$vars) {
  $vars['bx_slider_wapper_id'] = drupal_html_id("dexp_bx_slider_wrapper_".$_SERVER['REQUEST_TIME']);
  $vars['theme_hook_suggestions'][] = 'shortcode__bxslider';
}

function dexp_shortcodes_preprocess_shortcode_bxitem(&$vars) {
  $vars['theme_hook_suggestions'][] = 'shortcode__bxitem';
}

function dexp_shortcodes_bxslider_tips($format, $long) {
  $output = "[bxslider auto='TRUE|FALSE' pager='TRUE|FALSE' control='TRUE|FALSE' min='MINIMUM ITEM TO DISPLAY'
      max='MAXIMUM ITEM TO DISPLAY' move = 'NUMBER ITEM TO MOVE' width='ITEM WIDTH' margin='ITEM MARGIN' class='']
      [bxitem] ITEM 1[/bxitem][bxitem] ITEM 2[/bxitem] [bxitem] ITEM 3[/bxitem][/bxslider]";
  return $output;
}
