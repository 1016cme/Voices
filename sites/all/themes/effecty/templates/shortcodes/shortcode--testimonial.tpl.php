<div class="item <?php if ($sequence == 0) print 'active';?>">
	<?php if($image!=''):?><div class="testimonial-image"><img alt="" src="<?php print $image;?>"></div><?php endif;?>
	<div class="person-says">
      <strong><?php print $name;?></strong><br>
      <span class="text-small"><?php print $position; ?></span>
    </div>
    <div class="testimonials-content">
      <?php print $content; ?>
    </div>    
</div> 