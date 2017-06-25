<?php
/**
 * @file
 * Template for BxSlider.
 */
?>
<div>
<div id="<?php print $slider_id; ?>" class="dexp-bxslider">
	<?php foreach($items as $item): ?>
      <div><?php print $item['slide']; ?></div>
    <?php endforeach; ?>
</div>
<?php if(isset($settings['slider_settings']['pagerCustom_type']) && $settings['slider_settings']['pagerCustom_type'] == 'thumbnail_pager_method1'): ?>
  <div id="<?php  print $settings['slider_settings']['pagerCustom'] ?>">
    <?php foreach($items as $key => $item): ?>
      <a data-slide-index="<?php print $key ?>" href=""><?php print $item['slide_pagerCustom']; ?></a>
    <?php endforeach; ?>
  </div>
<?php endif; ?>
</div>
