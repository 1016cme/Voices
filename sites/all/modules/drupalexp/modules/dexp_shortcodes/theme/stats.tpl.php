<div id="<?php print $stats_id;?>" class="milestone-counter <?php print $class;?>"><div class="milestone-icon"><i class="<?php if ($icon != '') {print $icon;} ?>"></i></div><div class="stat-count highlight"><?php print $number; ?></div><div class="milestone-details"><?php print $content; ?></div></div>
<script type="text/javascript">
jQuery(document).ready(function($){
	$('#<?php print $stats_id;?> .stat-count').each(function() {
		var start = <?php print $start_number;?>;
                var number = <?php print $number;?>;
		var duration=<?php print $duration;?>;
                var speed = parseInt(duration / number);
		var inc=<?php print $inc_step;?>;
            if (typeof $.fn.appear === 'function') {
                $(this).appear(function() {
                    statcount($(this), start, inc, speed);
                }, {
                    accX: 0,
                    accY: 0,
                    one: true
                });
            } else {
                statcount($(this), start, inc, speed);
            }
    });

});
function statcount($element, $start, $inc_step, $speed) {
        var end = parseInt($element.html(), 10);
        if (end <= $start)
            return false;
        var interval = setInterval(function() {
            $start=$start+$inc_step;
            $element.html($start.toString());
            if ($start >= end) {
				$element.html(end.toString());
                clearInterval(interval);
            }
       }, $speed);
}
</script>
