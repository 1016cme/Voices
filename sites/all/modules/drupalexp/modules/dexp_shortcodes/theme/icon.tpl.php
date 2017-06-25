<div class="btn-icon <?php print $class;?>">
<?php if ($link == ""):?>
<i class="<?php print $icon; ?>"></i> <?php print $title;?>
<?php else: ?>
<a href="<?php print $link;?>"><i class="<?php print $icon;?>"></i> <?php print $title;?></a>
<?php endif;?>
</div>
    
