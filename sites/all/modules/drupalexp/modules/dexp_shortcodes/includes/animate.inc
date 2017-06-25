<?php

function dexp_shortcodes_animate_shortcode_info(&$shortcodes) {
  $shortcodes['animate'] = array(
      'title' => t('Animate appears'),
      'description' => t('Add appears animate to content'),
      'process callback' => 'dexp_shortcodes_animate',
      'attributes callback' => 'dexp_shortcodes_animate_attributes',
      'tips callback' => 'dexp_shortcodes_animate_tips',
  );
}

/**
 * Attributes form element for animate shortcode.
 *
 */
function dexp_shortcodes_animate_attributes($form, &$form_state) {
  $form['animate-type'] = array(
    '#title' => t('Animation effect'),
    '#type' => 'select',
    '#options' => array(
      'flash' => 'flash',
      'shake' => 'shake',
      'bounce' => 'bounce',
      'tada' => 'tada',
      'swing' => 'swing',
      'wobble' => 'wobble',
      'pulse' => 'pulse',
      'flip' => 'flip',
      'flipInX' => 'flipInX',
      'flipInY' => 'flipInY',
      'fadeIn' => 'fadeIn',
      'fadeInUp' => 'fadeInUp',
      'fadeInDown' => 'fadeInDown',
      'fadeInLeft' => 'fadeInLeft',
      'fadeInRight' => 'fadeInRight',
      'fadeInUpBig' => 'fadeInUpBig',
      'fadeInDownBig' => 'fadeInDownBig',
      'fadeInLeftBig' => 'fadeInLeftBig',
      'fadeInRightBig' => 'fadeInRightBig',
      'slideInDown' => 'slideInDown',
      'slideInLeft' => 'slideInLeft',
      'slideInRight' => 'slideInRight',
      'bounceIn' => 'bounceIn',
      'bounceInUp' => 'bounceInUp',
      'bounceInDown' => 'bounceInDown',
      'bounceInLeft' => 'bounceInLeft',
      'bounceInRight' => 'bounceInRight',
      'rotateIn' => 'rotateIn',
      'rotateInUpLeft' => 'rotateInUpLeft',
      'rotateInDownLeft' => 'rotateInDownLeft',
      'rotateInUpRight' => 'rotateInUpRight',
      'rotateInDownRight' => 'rotateInDownRight',
      'lightSpeedIn' => 'lightSpeedIn',
      'lightSpeedLeft' => 'lightSpeedLeft',
      'lightSpeedRight' => 'lightSpeedRight',
      'rollIn' => 'rollIn',
    ),  
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'animate'),
      ),
    ),
  );
  $form['animate-delay'] = array(
    '#title' => t('Delay time (ms)'),
    '#type' => 'textfield',
  );
  return $form;
}
function dexp_shortcodes_animate($attrs, $text) {
  $attrs = shortcode_attrs(array(
      'type' => 'fade',
      'delay' => 0,
      ), $attrs
  );
  $attrs['content'] = $text;
  return '<div class="dexp-animate" data-animate-delay="'.$attrs['delay'].'" data-animate="'.$attrs['type'].'">'.$text.'</div>';
}

function dexp_shortcodes_animate_tips ($format, $long) {
  $output = '[animate type="" delay=""]CONTENT HERE[/animate]';
  return $output;
}
