<?php
function dexp_shortcodes_servicesboxes_shortcode_info(&$shortcodes) {
    $shortcodes['servicesboxes'] = array(
        'title' => t('Services boxes wrapper'),
        'description' => t('Services boxes wrapper shortcode'),
        'process callback' => 'dexp_shortcodes_servicesboxes',
        'tips callback' => 'dexp_shortcodes_servicesbox_tips',
    );
}

function dexp_shortcodes_servicesboxes($attrs, $text) {
    $attrs = shortcode_attrs(array(
        'class' => '',), $attrs);
    $attrs['content'] = $text;
    return theme('dexp_shortcodes_servicesboxes', $attrs);
}

function dexp_shortcodes_servicesboxes_theme(&$themes) {
    $path = drupal_get_path('module', 'dexp_shortcodes');
    $themes['dexp_shortcodes_servicesboxes'] = array(
        'template' => 'servicesboxes',
        'path' => $path . '/theme',
        'pattern' => 'shortcode__',
        'preprocess functions' => array(
            'template_preprocess',
            'dexp_shortcodes_preprocess_shortcode_servicesboxes',
        ),
        'variables' => array(
            'class' => ''
        )
    );
}

function dexp_shortcodes_preprocess_shortcode_servicesboxes(&$vars) {
    $vars['servicesboxes_wapper_id'] = drupal_html_id("dexp_servicesboxes_wrapper_" . $_SERVER['REQUEST_TIME']);
    $vars['theme_hook_suggestions'][] = 'shortcode__servicesboxes';   
}
//
function dexp_shortcodes_servicesbox_shortcode_info(&$shortcodes) {
  $shortcodes['servicesbox'] = array(
      'title' => t('Services box'),
      'description' => t('Services box shortcode for service'),
      'process callback' => 'dexp_shortcodes_servicesbox',
      //'tips callback' => 'dexp_shortcodes_servicesbox_tips',
  );
}

function dexp_shortcodes_servicesbox($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'title' => '',
	  'type' => 'type1',
	  'image' =>'',
	  'number' =>'',
	  'color'=>'bg-transparent',
	  'icon' =>'',
	  'link' => '',
	  'class'=>''), $attrs);
  $attrs['content'] = $text;
  return theme('dexp_shortcodes_servicesbox', $attrs);
}

function dexp_shortcodes_servicesbox_theme(&$themes) {
  $path = drupal_get_path('module', 'dexp_shortcodes');
  $themes['dexp_shortcodes_servicesbox'] = array(
      'template' => 'servicesbox',
      'path' => $path . '/theme',
      'pattern' => 'shortcode__',
      'preprocess functions' => array(
          'template_preprocess',
          'dexp_shortcodes_preprocess_shortcode_servicesbox',
      ),
      'variables' => array(
          'title' => '',
		  'type' => 'type1',
		  'image' =>'',
		  'number' =>'',
		  'color'=>'bg-transparent',
		  'icon' =>'',
		  'link' => '',
		  'class' =>'',
          'content' => '',
      )
  );
}

function dexp_shortcodes_preprocess_shortcode_servicesbox(&$vars) {
  $type = $vars['type'];
  $vars['theme_hook_suggestions'][] = 'shortcode__servicesbox';
  $vars['theme_hook_suggestions'][] = 'shortcode__servicesbox__'.$type;
}

function dexp_shortcodes_servicesbox_tips($format, $long) {
  $output = "[servicesboxes class=''][servicesbox title='']Content[/servicesbox][servicesboxes]";
  return $output;
}