<?php

function dexp_shortcodes_row_shortcode_info(&$shortcodes) {
  $shortcodes['row'] = array(
      'title' => t('Row'),
      'description' => t('Row shortcode'),
      'process callback' => 'dexp_shortcodes_row',
      'attributes callback' => 'dexp_shortcodes_row_attributes',
      'tips callback' => 'dexp_shortcodes_row_tips',
  );
}

function dexp_shortcodes_row($attrs, $content = null ) {
  extract(shortcode_attrs(array('class'=>'', 'wrapper'=>''), $attrs));
  if ($wrapper != "") {
    return '<div class="'.$wrapper.'"><div class="row '.$class.'">'.$content.'</div></div>';
  }
  return '<div class="row '.$class.'">'.$content.'</div>';
}

/**
 * Attributes form element for row shortcode.
 *
 */
function dexp_shortcodes_row_attributes($form, &$form_state) {
  $form['row-wrapper'] = array(
    '#title' => t('Wrapper Row'),
    '#type' => 'select',
    '#options' => array('' => 'None', 'container' => 'Container', 'container-fluid' => 'Container Fluid'),
    '#description' => t('Add wrapper class container or container-fluid for this row'),  
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'row'),
      ),
    ),
  );
  $form['row-class'] = array(
    '#title' => t('Custom Row class'),
    '#type' => 'textfield',
    '#description' => t('Add custom classes to row and split by space'),
  );
  return $form;
}

function dexp_shortcodes_row_tips ($format, $long) {
  $output = '[row class=""]TEXT_HERE[/row]';
  return $output;
}

