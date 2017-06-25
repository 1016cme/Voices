<?php if ($link != ''): ?>
    <div class="image-shortcode-wrapper <?php print $class; ?>">
        <a href="<?php print $link; ?>"><img alt="<?php print $alt; ?>" title="<?php print $title; ?>" src="<?php print $path; ?>"></a>
        <?php if ($content): ?>
            <div class="image-content"><div class="image-inner"><?php print $content; ?></div></div>
        <?php endif; ?>
    </div>

<?php else: ?>
    <div class="image-shortcode-wrapper  <?php print $class; ?>">
        <img alt="<?php print $alt; ?>" title="<?php print $title; ?>" src="<?php print $path; ?>">
        <?php if ($content): ?>
            <div class="image-content"><div class="image-inner"><?php print $content; ?></div></div>
        <?php endif; ?>
    </div>
<?php endif; ?>
