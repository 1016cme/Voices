<div id="<?php print $servicesboxes_wapper_id; ?>" class="servicesboxes">
    <div class="servicesboxes-inner"><?php print $content; ?></div>
	<div class="clear"></div>
</div>
<script type="text/javascript">
    // Max Height 
    jQuery(document).ready(function ($) {        
        max_height();
        function max_height() {
            $("#<?php print $servicesboxes_wapper_id; ?>").each(function () {
                var maxHeight = 0;
                $(this).find(".box-inner").each(function () {
                    if ($(this).height() > maxHeight) {
                        maxHeight = $(this).height();
                    }
                }).height(maxHeight);
            });
        }
    });

</script>