<?php

function dexp_shortcodes_image_shortcode_info(&$shortcodes) {
    $shortcodes['image'] = array(
        'title' => t('Image'),
        'description' => t('Create image shortcode'),
        'process callback' => 'dexp_shortcodes_image',
        'tips callback' => 'dexp_shortcodes_image_tips',
        'attributes callback' => 'dexp_shortcodes_image_attributes'
    );
}

function dexp_shortcodes_image_attributes($form, &$form_state) {
  $form['image-path'] = array(
    '#title' => t('Image Path'),
    '#type' => 'textfield',
    //'#attributes' => array('class'=>array('image-picker')),
  );

  $form['image-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
  );
  $form['image-alt'] = array(
    '#title' => t('Alt'),
    '#type' => 'textfield',
  );
  $form['image-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
  );
  $form['image-class'] = array(
    '#title' => t('Class'),
    '#type' => 'textfield',
  );
  $form['content'] = array(
    '#title' => t('Content'),
    '#type' => 'textarea',
    '#wysiwyg' => false,
  );
  return $form;
}

function dexp_shortcodes_image($attrs, $text) {
    $attrs = shortcode_attrs(array(
        'class' => '', // font awesome class 
        'link' => '',
        'alt' => '',
        'path' => '',
        'title' => '',
        'path' => ''), $attrs);
    $attrs['content'] = $text;
    return trim(theme('dexp_shortcodes_image', $attrs));
}

function dexp_shortcodes_image_theme(&$themes) {
    $path = drupal_get_path('module', 'dexp_shortcodes');
    $themes['dexp_shortcodes_image'] = array(
        'template' => 'image',
        'path' => $path . '/theme',
        'pattern' => 'shortcode__',
        'preprocess functions' => array(
            'template_preprocess',
            'dexp_shortcodes_preprocess_shortcode_image',
        ),
        'variables' => array(
            'class' => '',
            'link' => '',
            'alt' => '',
            'path' => '',
            'title' => '',
            'path' => '',
            'content' => '',
        )
    );
}

function dexp_shortcodes_preprocess_shortcode_image(&$vars) {
    $vars['theme_hook_suggestions'][] = 'shortcode__image';
}

function dexp_shortcodes_image_tips($format, $long) {
    $output = "[image title='' alt='' class='' link='' path='']content[/image]";
    return $output;
}
