<?php
/**
 * @file
 * Template for Bootstrap Carousel.
 */
?>
<?php if(empty($settings['interval'])) $settings['interval'] = 'false';?>
<div id="<?php print $carousel_id; ?>" data-interval="<?php print $settings['interval'];?>" class="carousel slide" data-ride="carousel">
  <?php if($settings['pager'] && count($items) > 1):?>
  <!-- Indicators -->
  <ol class="carousel-indicators">
    <?php foreach($items as $key => $item): ?>
      <li data-target="#<?php print $carousel_id; ?>" data-slide-to="<?php print $key;?>" class="<?php print ($key == 0)?'active':'';?>"></li>
    <?php endforeach; ?>
  </ol>
  <?php endif;?>
  <!-- Wrapper for slides -->
  <div class="carousel-inner" role="listbox">
    <?php foreach($items as $key => $item): ?>
    <div class="item <?php print ($key == 0)?'active':'';?>">
      <?php print $item['slide']; ?>
    </div>
    <?php endforeach;?>
  </div>
  <?php if($settings['control'] && count($items) > 1):?>
  <!-- Controls -->
  <a class="left carousel-control" href="#<?php print $carousel_id; ?>" role="button" data-slide="prev">
    <span class="fa angle-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#<?php print $carousel_id; ?>" role="button" data-slide="next">
    <span class="fa angle-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
  <?php endif;?>
</div>
