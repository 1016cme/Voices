<?php

function dexp_shortcodes_stats_shortcode_info(&$shortcodes) {
  $shortcodes['stats'] = array(
      'title' => t('Stats'),
      'description' => t('Js Stats shortcode'),
      'process callback' => 'dexp_shortcodes_stats',
      'attributes callback' => 'dexp_shortcodes_stats_attributes',
      'tips callback' => 'dexp_shortcodes_stats_tips',
  );
}

function dexp_shortcodes_stats($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'title' => '',
      'class' => '',
      'icon' => '',
      //'timer' => '',
	  'start_number'=>'0',
	  'inc_step'=>'1',
	  'duration'=>'300', //ms
      'number' => ''), $attrs);
  $attrs['content'] = $text;
  return trim(theme('dexp_shortcodes_stats', $attrs));
}

/**
 * Attributes form element for stats shortcode.
 *
 */
function dexp_shortcodes_stats_attributes($form, &$form_state) {
   $form['stats-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'stats'),
      ),
    ),
  );
    $form['stats-number'] = array(
    '#title' => t('Number goal'),
    '#type' => 'textfield',
    '#description' => t('Input the number the stats will be stop'),
  );
  $form['stats-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#attributes' => array('class'=>array('icon-picker')),  
    '#description' => t('Icon using in stats'),
  );
  $form['stats-dudation'] = array(
    '#title' => t('Dudation'),
    '#type' => 'textfield',
    '#default_value'=>'300',
    '#description' => t('Dudation in ms'),
  );
  $form['stats-start_number'] = array(
    '#title' => t('Number Start'),
    '#type' => 'textfield',
    '#default_value'=>'1',
    '#description' => t('Input the number to start stats'),
  );
  $form['stats-inc_step'] = array(
    '#title' => t('Increase step number'),
    '#type' => 'textfield',
    '#default_value'=>'1',
    '#description' => t('Input Increase step'),
  );
  $form['stats-class'] = array(
    '#title' => t('Custom Stats class'),
    '#type' => 'textfield',
    '#description' => t('Add custom classes split by space'),
  );
  $form['content'] = array(
    '#title' => t('Content'),
    '#type' => 'textarea',
  );
  return $form;
}

function dexp_shortcodes_stats_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_stats'] = array(
      'template' => 'stats',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_stats',
      ),
      'variables' => array(
          'title' => '',
          'class' => '',
          'icon' => '',
	  'start_number'=>'0',
	  'inc_step'=>'1',
	  'duration'=>'300',
          'number' => '',
          'content' => '',
      )
  );
}

function dexp_shortcodes_preprocess_shortcode_stats(&$vars) {
  $vars['stats_id'] = drupal_html_id("dexp_stats_".REQUEST_TIME);
  $vars['theme_hook_suggestions'][] = 'shortcode__stats';
}

function dexp_shortcodes_stats_tips($format,$long) {
  $output = "[stats number='' start_number='0' inc_step='1' duration='300' icon='' class='' title='']Content[/stats]";
  return $output;
}
