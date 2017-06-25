<?php

/**
 * @file
 * Defines the style plugin for the Dexp Portfolio
 */
class dexp_grid_plugin_style_grid extends views_plugin_style {

  function option_definition() {
    $options = parent::option_definition();
    $options['grid_style'] = array('default' => 'classic');
    $options['grid_cols_lg'] = array('default' => 4);
    $options['grid_cols_md'] = array('default' => 4);
    $options['grid_cols_sm'] = array('default' => 2);
    $options['grid_cols_xs'] = array('default' => 1);
    $options['grid_margin'] = array('default' => 30);
    $options['grid_filter'] = array('default' => 0);
    $options['grid_ratio'] = array('default' => 1);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['grid_style'] = array(
      '#type' => 'select',
      '#title' => t('Grid Style'),
      '#options' => array(
        'classic' => t('Classic'),
        'masonry' => t('Simple Masonry'),
        'masonry_resize' => t('Masonry Resize'),
      ),
      '#attributes' => array('class' => array('grid-style')),
      '#default_value' => $this->options['grid_style'],
    );
    $field_options = array();
    $fields = field_info_fields();
    foreach($fields as $field){
      if($field['type']=='image'){
        $field_options[$field['field_name']] = $field['field_name'];
      }
    }
    $form['gird_masonry_background'] = array(
      '#type' => 'select',
      '#title' => t('Image'),
      '#options' => $field_options,
      '#default_value' => $this->options['gird_masonry_background'],
      '#states' => array(
        'visible' => array(
          '.grid-style' => array('value' => 'masonry_resize'),
        )
      )
    );
    $form['grid_ratio'] = array(
      '#type' => 'textfield',
      '#title' => t('Aspect ratio'),
      '#description' => t('The ratio of width to height'),
      '#default_value' => $this->options['grid_ratio'],
      '#states' => array(
        'visible' => array(
          '.grid-style' => array('value' => 'masonry_resize'),
        )
      )
    );
    $form['grid_cols_lg'] = array(
      '#type' => 'select',
      '#title' => t('Large Desktop Columns'),
      '#options' => array(1=>1,2,3,4,5,6,7,8,9,10,11,12),
      '#description' => t('Number of columns on Large Screen'),
      '#default_value' => $this->options['grid_cols_lg'],
    );
    $form['grid_cols_md'] = array(
      '#type' => 'select',
      '#title' => t('Desktop Columns'),
      '#options' => array(1=>1,2,3,4,5,6,7,8,9,10,11,12),
      '#description' => t('Number of columns on Medium Screen'),
      '#default_value' => $this->options['grid_cols_md']
    );
    $form['grid_cols_sm'] = array(
      '#type' => 'select',
      '#title' => t('Tablet Columns'),
      '#options' => array(1=>1,2,3,4,5,6,7,8,9,10,11,12),
      '#description' => t('Number of columns on Small Screen (tablet)'),
      '#default_value' => $this->options['grid_cols_sm']
    );
    $form['grid_cols_xs'] = array(
      '#type' => 'select',
      '#title' => t('Phone Columns'),
      '#options' => array(1=>1,2,3,4,5,6,7,8,9,10,11,12),
      '#description' => t('Number of columns on Very Small Screen (smartphone)'),
      '#default_value' => $this->options['grid_cols_xs']
    );
    $form['grid_margin'] = array(
      '#type' => 'textfield',
      '#title' => t('Margin'),
      '#description' => t('The spacing beetween items'),
      '#default_value' => $this->options['grid_margin'],
      '#field_suffix' => 'px',
    );
    $form['grid_filter'] = array(
      '#type' => 'select',
      '#title' => t('Use Filter'),
      '#options' => array(0=>t('No'),1=>t('Yes')),
      '#description' => t('Filter items by taxonomy term'),
      '#default_value' => $this->options['grid_filter'],
      '#attributes' => array('class' => array('grid-filter-option')),
      //'#states' => array(
      //  'invisible' => array(
      //    '.grid-style' => array('value' => 'classic'),
      //  )
      //)
    );
    $opts = array('-'.t('Select').'-');
    $tmp = array();
    foreach (taxonomy_vocabulary_get_names() as $vocab) {
      $tmp[$vocab->vid] = $vocab->name;
    }
    $opts += $tmp;
    $form['grid_filter_vocabulary'] = array(
      '#type' => 'select',
      '#title' => t('Filter Vocabulary'),
      '#options' => $opts,
      '#description' => t('Which taxonomy vocabulary do you want to use for the filter'),
      '#default_value' => $this->options['grid_filter_vocabulary'],
      '#states' => array(
        'visible' => array(
          '.grid-filter-option' => array('value' => 1),
          //'.grid-style' => array(array('value' => 'masonry'),array('value'=>'masonry_resize')),
        ),
      )
    );
  }
}
