<?php
/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */
?>
  <?php global $base_url;?>
    <li class="comment-row row ml0 mr0 pb10 pt10 <?php print $classes; ?>" <?php print $attributes; ?>>
      <div class="comment-avatar col-lg-2 col-md-2 col-sm-2 colxs-2 text-center">
        <?php
            if (!empty($picture))
                print $picture;
            else {
                print '<img src="'.$base_url.'/sites/all/themes/effecty/assets/images/person.png"/>';
            }
          ?>
      </div>
      <div class='comment-content col-lg-10 col-md-10 col-sm-2 colxs-10'>

        <h4 class="comment-heading">
          <?php// print $author; ?>
          <h4><?php print render($content['field_author']);?></h4>

        <a class="reply pull-right" href="<?php print $base_url; ?>/<?php if(isset($content['links']['comment']['#links']['comment-reply']))
              print_r($content['links']['comment']['#links']['comment-reply']['href']); ?>">
          <?php print t('Reply');?>
        </a>
        </h4>

        <div class="comment-text" <?php print $content_attributes; ?>>
          <?php
             // We hide the comments and links now so that we can render them later.
             hide($content['links']);
             print render($content);
           ?>
        </div>
        <span class="comment-date"><?php  print date('F d, Y g:i a', $comment->created);?></span>
      </div>
    </li>
