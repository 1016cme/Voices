<?php if ($tooltip == ""):?>
<a href="<?php print $link;?>" target="_blank" class="dexp-social-icon <?php print $class;?>"><span><i class="<?php print $icon;?>"></i></span> <?php print $content;?></a>
<?php else: ?>
<a data-placement="bottom" target="_blank" data-toggle="tooltip" title="<?php print $tooltip;?>" href="<?php print $link;?>" class="dtooltip dexp-social-icon <?php print $class;?>"><span><i class="<?php print $icon;?>"></i></span> <?php print $content;?></a>
<?php endif;?>
    
