<?php

function dexp_shortcodes_button_shortcode_info(&$shortcodes) {
  $shortcodes['dexpbutton'] = array(
      'title' => t('Dexp Button'),
      'description' => t('Create button'),
      'process callback' => 'dexp_shortcodes_button',
      'attributes callback' => 'dexp_shortcodes_button_attributes',
      'tips callback' => 'dexp_shortcodes_button_tips',
  );
}

function dexp_shortcodes_button_attributes($form, &$form_state) {
  $form['dexpbutton-size'] = array(
    '#title' => t('Size'),
    '#type' => 'select',
    '#options' => array('xl'=>'Extra Large button', 'lg'=>'Large button', 'md' => 'Medium button', 'sm' => 'Small button', 'xs' => 'XSmall button'),
  );
  $form['dexpbutton-type'] = array(
    '#title' => t('Type'),
    '#type' => 'select',
    '#options' => array('default'=>'Default', 'primary' => 'Primary', 'success' => 'Success','info' => 'Info','warning' => 'Warning','danger' => 'Danger', 'link' => 'Link'),
  );
  $form['dexpbutton-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#attributes' => array('class'=>array('icon-picker')),
  );
  $form['dexpbutton-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
  );
  $form['dexpbutton-class'] = array(
    '#title' => t('Class'),
    '#type' => 'textfield',
  );
  $form['content'] = array(
    '#title' => t('Button Name'),
    '#type' => 'textfield',
  );
  $form['dexpbutton-hover_text'] = array(
    '#title' => t('Hover Text'),
    '#type' => 'textfield',
  );
  return $form;
}

function dexp_shortcodes_button($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'size' => '', //lg,sm,xs
      'type' => 'default', //default, primary, success, info, warning, danger, link
      'class' => '',
      'icon' => '',
      'link' => '',
      'hover_text' => '',), $attrs);
  $attrs['content'] = $text;
  return trim(theme('dexp_shortcodes_button', $attrs));
}

function dexp_shortcodes_button_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_button'] = array(
      'template' => 'button',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_button',
      ),
      'variables' => array(
          'size' => '',
          'type' => 'default',
          'class' => '',
          'icon' => '',
          'link' => '',
          'hover_text' => '',
          'content' => '',
      )
  );
}

function dexp_shortcodes_preprocess_shortcode_button(&$vars) {
  $size = $vars['size'];
  $type = $vars['type'];
  $vars['classes_array'][] = 'btn';
  if($size){
    $vars['classes_array'][] = 'btn-'.$size;
  }
  if ($vars['class']) {
    $vars['classes_array'][] = $vars['class'];
  }
  if($type!="" && $type!="link"){
  $vars['classes_array'][] = 'btn-'.$type;
  }
  $vars['theme_hook_suggestions'][] = 'shortcode__button';
  $vars['theme_hook_suggestions'][] = 'shortcode__button__'.$type;
}

function dexp_shortcodes_button_tips($format, $long) {
  $output = "[dexpbutton size='' type='' icon='' link='' class='' hover_text='']Button Name[/dexpbutton]";
  return $output;
}
