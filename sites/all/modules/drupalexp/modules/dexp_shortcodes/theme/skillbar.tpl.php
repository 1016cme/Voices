<?php
$icon_class = '';
if ($icon !== '') {
    $icon_class = "<i class='" . $icon . "'></i> ";
}
?>
<div id="<?php print $element_id; ?>" class="skill-bar <?php print 'skillbar-'.$type; ?>" data-percent="<?php print $percent . "%"; ?>">
    <div class="progress <?php print $classes; ?>">
        <div class="progress-bar"  role="progressbar" aria-valuenow="<?php print $percent; ?>" aria-valuemin="0" aria-valuemax="100" style="width: 0%;">
            <span class="progress-type">
                <?php
                print $icon_class . $content;
                ?>
            </span>
            <span class="progress-completed"><?php print $percent . "%"; ?></span>
        </div>
    </div>
</div>