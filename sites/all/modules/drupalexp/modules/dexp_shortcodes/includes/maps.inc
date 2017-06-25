<?php
define('GMAP_API_KEY', 'AIzaSyB7Sh8KJDTRSELkJQm5p-1pUitBJaVOeGQ');
function dexp_shortcodes_maps_shortcode_info(&$shortcodes) {
    $shortcodes['maps'] = array(
        'title' => t('Maps'),
        'description' => t('Create maps shortcode'),
        'process callback' => 'dexp_shortcodes_maps',
        'attributes callback' => 'dexp_shortcodes_maps_attributes',
        'tips callback' => 'dexp_shortcodes_maps_tips',
    );
    $shortcodes['marker'] = array(
        'title' => t('Map Marker'),
        'description' => t('Create map marker shortcode'),
        'attributes callback' => 'dexp_shortcodes_maps_marker_attributes',
        'process callback' => 'dexp_shortcodes_maps_marker',
    );
}

function dexp_shortcodes_maps($attrs, $text) {
	drupal_add_js('//maps.google.com/maps/api/js?key='.GMAP_API_KEY, 'external');
	drupal_add_js(drupal_get_path('module','dexp_shortcodes').'/asset/js/dexp_gmap.js');
	drupal_add_css(drupal_get_path('module','dexp_shortcodes').'/asset/css/gmap.css');
    $attrs = shortcode_attrs(array(
        'class' => '',
        'height' => '400px',
        'type' => 'standard', //gray/color/standard
        'zoom' => '10'), $attrs);
    $attrs['content'] = $text;
    return trim(theme('dexp_shortcodes_maps', $attrs));
}

function dexp_shortcodes_maps_attributes($form, &$form_state) {
  $form['maps-type'] = array(
    '#title' => t('Type'),
    '#type' => 'select',
    '#options' => array('standard' => 'Standard', 'gray' => 'Gray', 'color' => 'Color'),
  );
  $form['maps-zoom'] = array(
    '#title' => t('Zoom'),
    '#type' => 'textfield',
    '#default_value' => '10',
  );
  $form['maps-height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#default_value' => '400px',
  );
  $form['maps-class'] = array(
    '#title' => t('Custom class'),
    '#type' => 'textfield',
  );
  return $form;
}

function dexp_shortcodes_maps_marker($attrs, $text){
	$attrs = shortcode_attrs(array(
        'link' => '',
        'title' => '',
        'image' => '',
        'phone' => '',
        'icon' => '',
        'latitude' => '',
        'longitude' => ''), $attrs);
    $attrs['content'] = $text;
    return "<div class=\"dexp-gmap-marker\" data-link=\"{$attrs['link']}\" data-title=\"{$attrs['title']}\" data-image=\"{$attrs['image']}\" data-phone=\"{$attrs['phone']}\" data-latitude=\"{$attrs['latitude']}\" data-longitude=\"{$attrs['longitude']}\" data-icon=\"{$attrs['icon']}\">{$text}</div>";
}

function dexp_shortcodes_maps_marker_attributes($form, &$form_state) {
  $form['marker-latitude'] = array(
    '#title' => t('Latitude'),
    '#type' => 'textfield',
  );
  $form['marker-longitude'] = array(
    '#title' => t('Longitude'),
    '#type' => 'textfield',
  );
  $form['marker-title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
  );
  $form['marker-image'] = array(
    '#title' => t('Image'),
    '#type' => 'textfield',
  );
  $form['marker-link'] = array(
    '#title' => t('Link'),
    '#type' => 'textfield',
  );
  $form['marker-icon'] = array(
    '#title' => t('Icon'),
    '#type' => 'textfield',
    '#description' => 'fa fa-home',
    '#attributes' => array('class'=>array('icon-picker')),
  );
  $form['marker-phone'] = array(
    '#title' => t('Phone'),
    '#type' => 'textfield',
  );
  return $form;
}

function dexp_shortcodes_maps_theme(&$themes) {
    $path = drupal_get_path('module', 'dexp_shortcodes');
    $themes['dexp_shortcodes_maps'] = array(
        'template' => 'maps',
        'path' => $path . '/theme',
        'pattern' => 'shortcode__',
        'preprocess functions' => array(
            'template_preprocess',
            'dexp_shortcodes_preprocess_shortcode_maps',
        ),
        'variables' => array(
            'class' => '',
            'type' => 'standard',
            'zoom' => '10',
            'height' => '400px',
            'content' => '',
        )
    );
}

function dexp_shortcodes_preprocess_shortcode_maps(&$vars) {
	$vars['attributes_array']['id'] = drupal_html_id('dexp_gmap_shortcode');
	$vars['attributes_array']['class'][] = drupal_html_class('dexp_gmap_shortcode');
	$vars['attributes_array']['style'] = "height:{$vars['height']}";
	$vars['attributes_array']['data-type'] = $vars['type'];
	$vars['attributes_array']['data-zoom'] = $vars['zoom'];
    $vars['theme_hook_suggestions'][] = 'shortcode__maps';
}

function dexp_shortcodes_maps_tips($format, $long) {
    $output = "[maps class='' type='color/standard' zoom='' height='']";
    $output .="[marker image='IMAGE_PATH' title ='TITLE' link='#' phone='PHONE' latitude='LAT' longitude='LONG' icon='ICON_PATH']ADDRESS[/marker]";
    $output .="[/maps]";
    return $output;
}
