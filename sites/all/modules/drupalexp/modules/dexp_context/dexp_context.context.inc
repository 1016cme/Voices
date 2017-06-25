<?php

class dexp_context_context_condition extends context_reaction_theme{
  /**
  * Allow admins to provide custom logo path.
  */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form = array(
      'custom_logo' => array(
        '#title' => t('Path to custom logo'),
        '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'),
        '#type' => 'textfield',
        '#maxlength' => 64,
        '#default_value' => isset($values['custom_logo']) ? $values['custom_logo'] : '',
      ),
    );
    return $form;
  }

  /**
   * Change logo path to custom logo.
   */
  function execute(&$vars) {
    $classes = array();
    foreach ($this->get_contexts() as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['custom_logo'])) {
        $vars['logo'] = file_create_url($v->reactions[$this->plugin]['custom_logo']);
      }
    }
  }
}
