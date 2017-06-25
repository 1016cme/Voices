<?php

function dexp_shortcodes_flipbox_shortcode_info(&$shortcodes) {
  $shortcodes['flipbox'] = array(
      'title' => t('Flip box'),
      'description' => t('Flip box shortcode for service'),
      'process callback' => 'dexp_shortcodes_flipbox',
      'tips callback' => 'dexp_shortcodes_flipbox_tips',
      'attributes callback' => 'dexp_shortcodes_flipbox_attributes',
  );
}

function dexp_shortcodes_flipbox($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'type' => '',
      'icon' => '', 
      'image' => '',
      'class' => '',
      'link' => '',
      'title' => ''), $attrs);
  $attrs['content'] = $text;
  return theme('dexp_shortcodes_flipbox', $attrs);
}

function dexp_shortcodes_flipbox_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_flipbox'] = array(
      'template' => 'flipbox',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_flipbox',
      ),
      'variables' => array(
          'type' => '',
          'icon' => '',
          'image' => '',
          'class' => '',
          'link' => '',
          'title' => '',
          'content' => '',
      )
  );
}

/**
 * Attributes form element for flipbox shortcode.
 *
 */
function dexp_shortcodes_flipbox_attributes($form, &$form_state) {
  $form['flipbox-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
  );
  
  $form['flipbox-type'] = array(
    '#title' => t('Type'),
    '#type' => 'select',
    '#options' => array(''=>t('Select'), 'icon' => t('Icon'), 'image' => t('Image')),  
    '#description' => t('FlipBox will be use icon or image'),
  );
  $form['flipbox-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#attributes' => array('class'=>array('icon-picker')), 
    '#states' => array(
      'visible' => array(
        'select[name="flipbox-type"]' => array('value' => 'icon'),
      ),
    ),
  );
  $form['flipbox-image'] = array(
    '#title' => t('Image'),
    '#type' => 'textfield',
    '#description' => t('Path to image'),  
    '#states' => array(
      'visible' => array(
        'select[name="flipbox-type"]' => array('value' => 'image'),
      ),
    ),
  );
  $form['box-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
    '#description' => t('Link when clicking on flipbox or flipbox tile'),
  );
  $form['flipbox-class'] = array(
    '#title' => t('Flipbox class'),
    '#type' => 'textfield',
    '#description' => t('Add your custom class to flipbox'),
  );
  $form['content'] = array(
    '#title' => t('Content'),
    '#type' => 'textarea',
    '#wysiwyg' => false,  
    '#description' => t('Short content in flipbox'),
  );
  return $form;
}

function dexp_shortcodes_preprocess_shortcode_flipbox(&$vars) {
  $vars['theme_hook_suggestions'][] = 'shortcode__flipbox';
}

function dexp_shortcodes_flipbox_tips($format, $long) {
  $output = "[flipbox type='icon OR img' icon='FONT AWESOME CLASS or SS-GIZMO' image='' title='' class='']Content[/flipbox]";
  return $output;
}
