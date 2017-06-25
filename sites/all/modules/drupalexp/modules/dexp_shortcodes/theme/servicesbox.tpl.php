<?php
$style_css='';
$bg_class='';
if($type=="type1" && $image!=""){
	$style_css="background-image: url(".$image.")";
}else if($type=="type2" && $color!="")
{
	$bg_class=$color;
}
?>
<?php if ($type=='type1' || $type=='type2'):?>
<div class="box-services <?php print $type.' '. $bg_class.' '. $class;?>" style="<?php print $style_css;?>">
	<div class="bg-overlay"></div>
	<div class="box-inner">
		<h3 class="box-title"><?php if($title!=""){print $title;}?><?php if($link!=""):?> <a class="link-read-more" href="<?php print $link;?>">read more</a><?php endif;?></h3>
		<p class="mb0 "><?php print $content;?></p>
		<?php if($icon!=""){print "<i class='".$icon."'></i>";}?>
		<?php if($number!=""){print "<span class='fa box-number'>".$number."</span>";}?>
	</div>
</div>
<?php else:?>
<div class="box-services <?php print $type.' '. $class;?>">
<div class="box-services-image">
    <img src="<?php print $image; ?>" alt="">
	<div class="box-hover-overlay">
        <div class="box-info">
            <div class="box-tools">
                <a href="<?php print $image; ?>" rel="prettyPhoto['box-image']"><span class="fa fa-search"></span></a>
            </div>            
        </div>
    </div>
</div>
<div class="box-inner">
<h3 class="box-title"><?php print $title; ?><?php if($link!=""):?> <a class="link-read-more" href="<?php print $link;?>">read more</a><?php endif;?></h3>
<?php print $content; ?>
</div>
</div>
<?php endif;?>