<span class="<?php print $flag_wrapper_classes; ?>">
<?php if ($link_href): ?>
<a href="<?php print $link_href; ?>" class="<?php print $flag_classes ?>" rel="nofollow">
    <i class="fa fa-thumbs-o-up mr3"></i>
    <span class="mr3"><?php print t('Like '); ?></span>
    <?php print $flag->get_count($entity_id); ?>
</a>
    <span class="flag-throbber">&nbsp;</span>
<?php else: ?>
<span class="<?php print $flag_classes ?>">
    <i class="fa fa-thumbs-o-up mr3"></i>
    <span class="mr3"><?php print t('Like '); ?></span>
    <?php print $flag->get_count($nid); ?>
</span>
<?php endif; ?>
<?php if ($after_flagging): ?>
<span class="flag-message flag-<?php print $status; ?>-message">
<?php print $message_text; ?>
</span>
<?php endif; ?>
</span> 