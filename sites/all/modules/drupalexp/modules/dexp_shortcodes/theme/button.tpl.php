<?php
$i="";
$has_icon="";
if(!empty($icon)){
 $i = "<i class=\"{$icon}\"></i> ";
 $has_icon="btn-icon";  
}
?>
<?php if ($type == 'link'): ?><a role="button" class="<?php print $classes; print ' '.$has_icon;?>" href="<?php print $link; ?>"><?php print $i . $content; ?></a><?php else: ?><button type="button" class="<?php print $classes;  print ' '.$has_icon;?>"><?php print $i . $content; ?></button><?php endif; ?>