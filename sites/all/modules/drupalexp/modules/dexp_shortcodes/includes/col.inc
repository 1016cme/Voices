<?php

function dexp_shortcodes_col_shortcode_info(&$shortcodes) {
  $shortcodes['col'] = array(
      'title' => t('Column (Bootstrap using with Row shortcode)'),
      'description' => t('Column shortcode (using with Row shortcode)'),
      'process callback' => 'dexp_shortcodes_col',
      'attributes callback' => 'dexp_shortcodes_col_attributes',
      'tips callback' => 'dexp_shortcodes_col_tips',
  );
}

/**
 * Attributes form element for col shortcode.
 *
 */
function dexp_shortcodes_col_attributes($form, &$form_state) {
  $form['col-lg_col'] = array(
    '#type' => 'select',
    '#options' => array('1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#default_value' => '6',
    '#field_prefix' => '<i class="fa fa-desktop"></i><span> col-lg-</span>',
  );
  $form['col-md_col'] = array(
    '#type' => 'select',
    '#options' => array('1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#default_value' => '6',
    '#field_prefix' => '<i class="fa fa-laptop"></i><span> col-md-</span>',
  );
  $form['col-sm_col'] = array(
    '#type' => 'select',
    '#options' => array('1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#field_prefix' => '<i class="fa fa-tablet"></i><span> col-sm-</span>',
    '#default_value' => '12',
  );
  $form['col-xs_col'] = array(
    '#type' => 'select',
    '#options' => array('1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#field_prefix' => '<i class="fa fa-mobile-phone"></i><span> col-xs-</span>',
    '#default_value' => '12',
  );
  $form['col-lg_offset_col'] = array(
    '#type' => 'select',
    '#options' => array('' => t('Not set'), '1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#field_prefix' => '<i class="fa fa-desktop"></i><span> col-lg-offset-</span>',
  );
  $form['col-md_offset_col'] = array(
    '#type' => 'select',
    '#options' => array('' => t('Not set'), '1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#field_prefix' => '<i class="fa fa-laptop"></i><span> col-md-offset-</span>',
  );
  $form['col-sm_offset_col'] = array(
    '#type' => 'select',
    '#field_prefix' => '<i class="fa fa-tablet"></i><span> col-sm-offset-</span>',
    '#options' => array('' => t('Not set'), '1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),
  );
  $form['col-xs_offset_col'] = array(
    '#type' => 'select',
    '#options' => array('' => t('Not set'), '1' => t('1'), '2' => t('2'),'3' => t('3'), '4' => t('4'), '5' => t('5'), '6' => t('6'), '7' => t('7'), '8' => t('8'), '9' => t('9'), '10' => t('10'), '11' => t('11'), '12' => t('12')),  
    '#field_prefix' => '<i class="fa fa-mobile-phone"></i><span> col-xs-offset-</span>',
  );
  $form['col-class'] = array(
    '#title' => t('Custom class'),
    '#type' => 'textfield',
    '#description' => t('Add custom classes to column. You can put one more class split by space'),
  );
  return $form;
}


function dexp_shortcodes_col($attrs, $content = null ) {
  extract(shortcode_attrs(array('lg_col' => '','md_col' => '', 'sm_col' => '', 'xs_col' => '', 
        'lg_offset_col' => '','md_offset_col' => '', 'sm_offset_col' => '', 'xs_offset_col' => '', 
        'class'=>'',), $attrs));
  $generate = "";
  if ($lg_col != "") {
    $generate .= " col-lg-".$lg_col;
  }
  if ($md_col != "") {
    $generate .= " col-md-".$md_col;
  }
  if ($sm_col != "") {
    $generate .= " col-sm-".$sm_col;
  }
  if ($xs_col != "") {
    $generate .= " col-xs-".$xs_col;
  }
  if ($lg_offset_col != "") {
    $generate .= " col-lg-offset-".$lg_offset_col;
  }
  if ($md_offset_col != "") {
    $generate .= " col-md-offset-".$md_offset_col;
  }
  if ($sm_offset_col != "") {
    $generate .= " col-md-offset-".$sm_offset_col;
  }
  if ($xs_offset_col != "") {
    $generate .= " col-xs-offset-".$xs_offset_col;
  }
  if ($class !="") {
    $generate .= " ".$class;
  }
  return "<div class='".$generate."'>".$content."</div>";
}

function dexp_shortcodes_col_tips ($format, $long) {
  $output = '[col lg_col="" md_col="" sm_col="" xs_col="" lg_offset_col="" md_offsest_col="" sm_offset_col="" xs_offset_col="" class=""]TEXT_HERE[/col]';
  return $output;
}
