<div id="<?php print $testimonial_wapper_id; ?>" class="testimonials <?php if ($total_items > 1) { print "carousel slide dexp_carousel";}?> <?php print $class; ?>" data-ride="carousel"><!-- Wrapper for slides -->
<div class="carousel-inner"><?php print $content; ?></div><!-- End Wrapper for slides -->
<!-- Carousel indicators -->
<?php if ($total_items > 1): ?>
<div class="clearfix"></div>
<ol class="carousel-indicators">
<?php for ($i = 0; $i < $total_items; $i++): ?>
<li data-target="#<?php print $testimonial_wapper_id; ?>" data-slide-to="<?php print $i; ?>" <?php print $i == 0 ? 'class=active' : ''; ?>></li>
<?php endfor; ?></ol><?php endif; ?><!-- End Carousel indicators --><i class="fa fa-quote-right icon_quotations"></i>
<!-- Controls -->
  <a class="left carousel-control" href="#<?php print $testimonial_wapper_id; ?>" role="button" data-slide="prev">
    <span class="fa fa-angle-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#<?php print $testimonial_wapper_id; ?>" role="button" data-slide="next">
    <span class="fa fa-angle-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>