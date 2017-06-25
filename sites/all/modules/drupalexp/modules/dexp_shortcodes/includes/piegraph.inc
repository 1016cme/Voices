<?php

function dexp_shortcodes_piegraph_shortcode_info(&$shortcodes) {
  $shortcodes['piegraph'] = array(
      'title' => t('Pie Graph'),
      'description' => t('Draw percer circle use HTML5 canvas'),
      'process callback' => 'dexp_shortcodes_piegraph',
      'attributes callback' => 'dexp_shortcodes_piegraph_attributes',
      'tips callback' => 'dexp_shortcodes_piegraph_tips',
  );
}

function dexp_shortcodes_piegraph($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'title' => '',
      'percent' => '0',
      'style' => 'style01',
      'class' => '',
      ), $attrs
  );
  $attrs['content'] = $text;
  return theme('dexp_shortcodes_piegraph', $attrs);
}

function dexp_shortcodes_piegraph_attributes($form, $form_state) {
  $form['piegraph-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'piegraph'),
      ),
    ),
  );
  $form['piegraph-percent'] = array(
    '#title' => t('Percent'),
    '#type' => 'textfield',
  );
  $form['piegraph-style'] = array(
    '#title' => t('Style'),
    '#type' => 'select',
    '#options' => array('style01'=>'Style 01 (Default)', 'style02'=>'Style 02', 'style03' => 'Style 03'),
  );
  $form['content'] = array(
    '#title' => t('Content'),
    '#type' => 'textarea',
  );
  $form['piegraph-class'] = array(
    '#title' => t('Class'),
    '#type' => 'textfield',
     '#description'=>'Put your custom class',
  );
  return $form;
}

function dexp_shortcodes_piegraph_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_piegraph'] = array(
      'template' => 'piegraph',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_piegraph',
      ),
      'variables' => array(
          'title' => '',
          'percent' => '',
          'style' => 'style01',
          'class' => '',
          'content' => '',
      )
  );
}

function dexp_shortcodes_preprocess_shortcode_piegraph(&$vars) {
  $vars['element_id'] = drupal_html_id("dexp_piegraph".REQUEST_TIME);
  $style = $vars['style'];  
  $class = $vars['class'];  
  $vars['classes_array'][] = 'dexp-piegraph-'.$style; 
  $vars['classes_array'][] = $class; 
  $vars['theme_hook_suggestions'][] = 'shortcode__piegraph';
  $vars['theme_hook_suggestions'][] = 'shortcode__piegraph__'. $style;
}

function dexp_shortcodes_piegraph_tips($format, $long) {
  $output = "[piegraph title='' percent='' style='']Content[/piegraph]";
  return $output;
}
