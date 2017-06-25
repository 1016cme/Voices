<?php
$place_holder='';
if ($icon) {
    $place_holder = '<i class="' . $icon . '"></i>';
}
if ($image) {
    $place_holder = '<img alt="" src="' . $image . '">';
}
if ($number) {
    $place_holder = '<i>'.$number.'</i>';
}
if ($link != "") {
    $place_holder = "<a href=" . $link . ">" . $place_holder . "</a>";
}
?>
<div class="<?php print $classes; ?>"><?php if ($place_holder): ?><div class="box-icon"><span class="border-effect"><?php print $place_holder; ?></span></div><?php endif; ?><?php if ($title): ?><h3 class="box-title"><?php print $title; ?></h3><?php endif; ?><?php if ($content): ?><p class="box-content"><?php print $content; ?><?php if($readmore!=''){print "<div class='readmore-button'><a href='".$link."'>".$readmore."</a></div>";}?></p><?php endif; ?></div>