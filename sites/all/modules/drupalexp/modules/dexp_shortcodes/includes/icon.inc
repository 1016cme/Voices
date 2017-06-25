<?php

function dexp_shortcodes_icon_shortcode_info(&$shortcodes) {
    $shortcodes['icon'] = array(
        'title' => t('Icon'),
        'description' => t('Create Icon shortcode'),
        'process callback' => 'dexp_shortcodes_icon',
        'tips callback' => 'dexp_shortcodes_icon_tips',
        'attributes callback' => 'dexp_shortcodes_icon_attributes'
    );
}

function dexp_shortcodes_icon_attributes($form, &$form_state) {
  $form['icon-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#default_value' => 'fa fa-home',
    '#attributes' => array('class'=>array('icon-picker')),
  );

  $form['icon-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
  );
  $form['icon-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
  );
  $form['icon-class'] = array(
    '#title' => t('Class'),
    '#type' => 'textfield',
  );
  return $form;
}

function dexp_shortcodes_icon($attrs, $text) {
    $attrs = shortcode_attrs(array(
        'class' => '', // font awesome class 
        'link' => '',
        'icon' => '',
        'title' => ''), $attrs);
    //$attrs['content'] = $text;
    return trim(theme('dexp_shortcodes_icon', $attrs));
}

function dexp_shortcodes_icon_theme(&$themes) {
    $path = drupal_get_path('module', 'dexp_shortcodes');
    $themes['dexp_shortcodes_icon'] = array(
        'template' => 'icon',
        'path' => $path . '/theme',
        'pattern' => 'shortcode__',
        'preprocess functions' => array(
            'template_preprocess',
            'dexp_shortcodes_preprocess_shortcode_icon',
        ),
        'variables' => array(
            'class' => '',
            'link' => '',
            'icon' => '',
            'title' => '',
            //'content' => '',
        )
    );
}

function dexp_shortcodes_preprocess_shortcode_icon(&$vars) {
    $vars['theme_hook_suggestions'][] = 'shortcode__icon';
}

function dexp_shortcodes_icon_tips($format, $long) {
    $output = "[icon title='' class='' link='' icon=''][/icon]";
    return $output;
}
