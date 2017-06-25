<?php

function dexp_shortcodes_box_shortcode_info(&$shortcodes) {
  $shortcodes['box'] = array(
      'title' => t('Boxes'),
      'description' => t('Create a block content with icon'),
      'process callback' => 'dexp_shortcodes_box',
      'attributes callback' => 'dexp_shortcodes_box_attributes',
      'tips callback' => 'dexp_shortcodes_box_tips',
  );
}

function dexp_shortcodes_box($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'title' => '',
      'border' => 'none',//none,square,circle
      'background' => 'no',
      'align' => 'center',//left,center,right
      'type' => 'icon',
      'icon' => '',
      'image'=>'',
      'number' => '',
      'class'=>'',
      'link'=>'',
      'readmore'=>''), $attrs
  );
  $attrs['content'] = $text;
  return theme('dexp_shortcodes_box', $attrs);
}

function dexp_shortcodes_box_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_box'] = array(
      'template' => 'box',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_box',
      ),
      'variables' => array(
          'title' => '',
          'border' => 'none',
          'background' =>'no',
          'align' => 'center',
          'type' => 'icon',
          'icon' =>'',
          'image'=>'',
          'number' => '',
          'link'=>'',
          'class'=>'',
          'readmore'=>'',
          'content' => '',
      )
  );
}

/**
 * Attributes form element for box shortcode.
 *
 */
function dexp_shortcodes_box_attributes($form, &$form_state) {
  $form['box-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'box'),
      ),
    ),
  );
  $form['box-border'] = array(
    '#title' => t('Border'),
    '#type' => 'select',
    '#options' => array('none' => t('None'), 'circle' => t('Cirlce'), 'square' => t('Square')),
  );
  $form['box-background'] = array(
    '#title' => t('Background Box'),
    '#type' => 'select',
    '#options' => array('no' => t('No'), 'yes' => t('Yes')),
  );
  $form['box-align'] = array(
    '#title' => t('Align'),
    '#type' => 'select',
    '#options' => array('center' => t('Center'), 'left' => t('Left'), 'right' => t('Right'), 'top-left' => t('Top Left'), 'top-right' => t('Top Right')),
  );
  $form['box-type'] = array(
    '#title' => t('Type'),
    '#type' => 'select',
    '#options' => array('' => 'Select','icon' => t('Icon'), 'image' => t('Image')),  
    '#default_values' => '',
    '#description' => t('Box will be use icon or image'),
  );
  $form['box-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#description' => t('Ex: fa fa-phone'),  
    '#attributes' => array('class'=>array('icon-picker')),  
    '#states' => array(
      'visible' => array(
        'select[name="box-type"]' => array('value' => 'icon'),
      ),
    ),
  );
  $form['box-image'] = array(
    '#title' => t('Image'),
    '#type' => 'textfield',
    '#description' => t('Path to image'),  
    '#states' => array(
      'visible' => array(
        'select[name="box-type"]' => array('value' => 'image'),
      ),
    ),
  );
  $form['box-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
    '#description' => t('Link when clicking on box or box tile'),
  );
  $form['box-class'] = array(
    '#title' => t('Box class'),
    '#type' => 'textfield',
    '#description' => t('Add your custom class to box'),
  );
  $form['box-readmore'] = array(
    '#title' => t('Read More Text'),
    '#type' => 'textfield',
    '#description' => t('Add the Read More text for the box'),
  );
  $form['content'] = array(
    '#title' => t('Content'),
    '#type' => 'textarea',
    '#wysiwyg' => false,  
    '#description' => t('Short content in box'),
  );
  return $form;
}

function dexp_shortcodes_preprocess_shortcode_box(&$vars) {
  $border = $vars['border'];
  $align = $vars['align'];
  $class=$vars['class'];
  $image = $vars['image'];
  if($vars['background'] == 'yes'){
    $vars['classes_array'][] = 'box-background';
  }
  if($image!=''){
      $class=$class." image-box";
  }
  $vars['classes_array'][] = $class;  
  $vars['classes_array'][] = 'box-'.$border;
  $vars['classes_array'][] = 'box-'.$align;
  $vars['theme_hook_suggestions'][] = 'shortcode__box__' . $align;
  $vars['theme_hook_suggestions'][] = 'shortcode__box__' . $align.'__'.$border;
}

function dexp_shortcodes_box_tips($long, $format) {
  $output = "[box class='' title='' border='circle|square|diamond|hexagon' background='yes|no', align='left|center|right|top|custom' icon/number='FONT AWESOME/NUMBER' link='' ]Content here[/box]";
  return $output;
}
