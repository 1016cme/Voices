<?php $has_sub_title = false;
if (strpos($content, '~')): ?><?php $has_sub_title = true;
    $title_array = explode('~', $content);
    $main_title = $title_array[0];
    $sub_title = $title_array[1]; ?> <?php endif; ?>
<div class="title-wrapper <?php print $class; ?>"><?php if ($has_sub_title): ?>
        <h1 class="title"><?php print $main_title; ?></h1>
        <div class="line-style"><span></span></div>
        <p class="subtitle"><?php print $sub_title; ?></p>
<?php else: ?>
        <h1 class="title nosubtitle"><?php print $content; ?></h1>
        <div class="line-style"><span></span></div>
<?php endif; ?>
</div>