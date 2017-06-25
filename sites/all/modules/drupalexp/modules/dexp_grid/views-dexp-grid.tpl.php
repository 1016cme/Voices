<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php if ($options['grid_filter']): ?>
  <?php if (isset($categories)): ?>
    <div class="grid-filter">
      <ul class="dexp-grid-filter clearfix">
        <li><a class="active" href="#" data-filter="*"><span><?php print t('Show All') ?></span></a></li>
        <?php foreach ($categories as $key => $c): ?>
          <li>
            <a href="#" class="<?php echo $key; ?>" data-filter="<?php echo $key; ?>"><span><?php echo $c; ?></span></a>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>
<?php endif; ?>

<?php
$lg_zise = 12/$options['grid_cols_lg'];
$md_zise = 12/$options['grid_cols_md'];
$sm_zise = 12/$options['grid_cols_sm'];
$xs_zise = 12/$options['grid_cols_xs'];
$span_class = "";// "col-lg-{$lg_zise} col-md-{$md_zise} col-sm-{$sm_zise} col-xs-{$xs_zise}";
if($options['grid_style'] != 'classic'){
  $span_class = "";
}
$inner_class = "";
if($options['grid_style'] != 'masonry_resize' ){
  //$inner_class .= "rowxx";
  $inner_class .= " grid-margin-".$options['grid_margin'];
}
?>
<div id="<?php print $view_id;?>" class="dexp-grid <?php print $options['grid_filter']?'has-filter':'';?> <?php print drupal_html_class($options['grid_style']);?> grid-lg-<?php print $options['grid_cols_lg'];?> grid-md-<?php print $options['grid_cols_md'];?> grid-sm-<?php print $options['grid_cols_sm'];?> grid-xs-<?php print $options['grid_cols_xs'];?>">
  <div class="<?php print $inner_class;?> dexp-grid-inner">
    <?php foreach($rows as $k=>$row):?>
      <?php
      $classes = "";
      if($options['grid_filter'] && !empty($options['grid_filter_vocabulary'])){
        $nid = isset($view->result[$k]->nid)?$view->result[$k]->nid:0;
        if($nid == 0){
          $nid = isset($view->result[$k]->entity)?$view->result[$k]->entity:0;
        }
        $terms = _dexp_grid_node_get_term($options['grid_filter_vocabulary'], $nid);
        foreach($terms as $term){
          $classes .= ' '.drupal_html_class($term->name);
        }
      }
      if($options['grid_style'] == 'masonry_resize' && isset($options['gird_masonry_background']) && !empty($options['gird_masonry_background'])){
        $nid = isset($view->result[$k]->nid)?$view->result[$k]->nid:0;
        if($nid){
          $node = node_load($nid);
          $images = field_get_items('node',$node, $options['gird_masonry_background']);
          if($images){
            $background = file_create_url($images[0]['uri']);
          }
        }
        $size = dexp_grid_masonry_size($view_id, $k);
        $classes .= " item-w".$size['width'];
        $classes .= " item-h".$size['height'];
      }
      ?>
      <div class="dexp-grid-item <?php print $span_class?><?php print $classes;?>" data-index="<?php print $k ?>">
      <?php if(isset($background)):?>
        <div class="dexp-grid-item-inner <?php print $options['row_class'];?>" style="background-image:url('<?php print $background;?>')">
      <?php else:?>
        <div class="dexp-grid-item-inner <?php print $options['row_class'];?>">
      <?php endif;?>
        <?php print $row;?>
        </div>
      </div>
    <?php endforeach;?>
    <div class="shuffle__sizer"></div>
  </div>
</div>
