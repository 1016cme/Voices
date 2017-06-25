<?php

function dexp_shortcodes_skillbar_shortcode_info(&$shortcodes) {
  $shortcodes['skillbar'] = array(
      'title' => t('Skill bar'),
      'description' => t('Skill bar shortcode'),
      'process callback' => 'dexp_shortcodes_skillbar',
      'attributes callback' => 'dexp_shortcodes_skillbar_attributes',
      'tips callback' => 'dexp_shortcodes_skillbar_tips',
  );
}

/**
 * Attributes form element for skillbar shortcode.
 *
 */
function dexp_shortcodes_skillbar_attributes($form, &$form_state) {
  $form['skillbar-percent'] = array(
    '#title' => t('Percent'),
    '#type' => 'textfield',
    '#description' => t('Input how many percent'),  
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'skillbar'),
      ),
    ),
  );
  $form['skillbar-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#description' => t('Icon using in skillbar'),
    '#attributes' => array('class'=>array('icon-picker')),
  );
  $form['skillbar-class'] = array(
    '#title' => t('Class'),
    '#type' => 'textfield',
    '#description' => t('Class custom for skillbar'),
  );
  $form['skillbar-type'] = array(
    '#title' => t('Type'),
    '#type' => 'select',
    '#options' => array('type1' => t('Type 1'), 'type2' => t('Type 2'), 'type3' => t('Type 3'), 'type4' => t('Type 4')),
    '#description' => t('Select skillbar type'),
  );
  $form['skillbar-content'] = array(
    '#title' => t('Skill text'),
    '#type' => 'textfield',
    '#description' => t('Text display on skillbar '),
  );
  return $form;
}

function dexp_shortcodes_skillbar($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'percent' => '',
      'icon' => '',
      'class' => '',      
      'type' => '',
      'content' => $text,
   ), $attrs);
  return theme('dexp_shortcodes_skillbar',$attrs);
}

function dexp_shortcodes_skillbar_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_skillbar'] = array(
      'template' => 'skillbar',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_skillbar',
      ),
      'variables' => array(
          'percent' => '',
          'icon' => '',
          'class' => '',
          'type' => '',
          'content' => '',      
      )
  );
}

function dexp_shortcodes_preprocess_shortcode_skillbar(&$vars) {
  $vars['element_id'] = drupal_html_id('skill_bar');
  $class=$vars['class'];
  $type=$vars['type'];
  $vars['classes_array'][]=$class;
  $vars['theme_hook_suggestions'][] = 'shortcode__skillbar';
  $vars['theme_hook_suggestions'][] = 'shortcode__skillbar__'.$type;
}

function dexp_shortcodes_skillbar_tips($format, $long) {
  $output = "[skillbar type='' class='' percent='' icon='']Title[/skillbar]";
  return $output;
}
