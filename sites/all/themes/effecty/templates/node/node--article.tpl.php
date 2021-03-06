<?php
/**
* @file
* Default theme implementation to display a node.
*
* Available variables:
* - $title: the (sanitized) title of the node.
* - $content: An array of node items. Use render($content) to print them all,
* or print a subset such as render($content['field_example']). Use
* hide($content['field_example']) to temporarily suppress the printing of a
* given element.
* - $user_picture: The node author's picture from user-picture.tpl.php.
* - $date: Formatted creation date. Preprocess functions can reformat it by
* calling format_date() with the desired parameters on the $created variable.
* - $name: Themed username of node author output from theme_username().
* - $node_url: Direct URL of the current node.
* - $display_submitted: Whether submission information should be displayed.
* - $submitted: Submission information created from $name and $date during
* template_preprocess_node().
* - $classes: String of classes that can be used to style contextually through
* CSS. It can be manipulated through the variable $classes_array from
* preprocess functions. The default values can be one or more of the
* following:
* - node: The current template type; for example, "theming hook".
* - node-[type]: The current node type. For example, if the node is a
* "Blog entry" it would result in "node-blog". Note that the machine
* name will often be in a short form of the human readable label.
* - node-teaser: Nodes in teaser form.
* - node-preview: Nodes in preview mode.
* The following are controlled through the node publishing options.
* - node-promoted: Nodes promoted to the front page.
* - node-sticky: Nodes ordered above other non-sticky nodes in teaser
* listings.
* - node-unpublished: Unpublished nodes visible only to administrators.
* - $title_prefix (array): An array containing additional output populated by
* modules, intended to be displayed in front of the main title tag that
* appears in the template.
* - $title_suffix (array): An array containing additional output populated by
* modules, intended to be displayed after the main title tag that appears in
* the template.
*
* Other variables:
* - $node: Full node object. Contains data that may not be safe.
* - $type: Node type; for example, story, page, blog, etc.
* - $comment_count: Number of comments attached to the node.
* - $uid: User ID of the node author.
* - $created: Time the node was published formatted in Unix timestamp.
* - $classes_array: Array of html class attribute values. It is flattened
* into a string within the variable $classes.
* - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
* teaser listings.
* - $id: Position of the node. Increments each time it's output.
*
* Node status variables:
* - $view_mode: View mode; for example, "full", "teaser".
* - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
* - $page: Flag for the full page state.
* - $promote: Flag for front page promotion state.
* - $sticky: Flags for sticky post setting.
* - $status: Flag for published status.
* - $comment: State of comment settings for the node.
* - $readmore: Flags true if the teaser content of the node cannot hold the
* main body content.
* - $is_front: Flags true when presented in the front page.
* - $logged_in: Flags true when the current user is a logged-in member.
* - $is_admin: Flags true when the current user is an administrator.
*
* Field variables: for each field instance attached to the node a corresponding
* variable is defined; for example, $node->body becomes $body. When needing to
* access a field's raw values, developers/themers are strongly encouraged to
* use these variables. Otherwise they will have to explicitly specify the
* desired field language; for example, $node->body['en'], thus overriding any
* language negotiation rule that was previously applied.
*
* @see template_preprocess()
* @see template_preprocess_node()
* @see template_process()
*
* @ingroup themeable
*/
?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> " <?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>

        <div class="blog-item">
          <div class="blog-date ">
            <span class="day"><?php print date('d', $created)?></span>
            <span class="month"><?php print date('M', $created)?></span>
          </div>
          <div class="blog-image">

            <div class="image-detail ImageWrapper">
              <?php print render($content['field_image']);?>
            </div>
            <div class="blog-social">
              <div class="blog-comment inline-block"><i class="fa fa-comments-o mr3"></i>
                <span class="mr3"> <?php print $comment_count; ?></span>
                <?php print t('Replies')?>
              </div>
              <div class="blog-flag inline-block">
                <?php print flag_create_link("flag_like", $node->nid);?>
              </div>
            </div>

          </div>

          <div class="blog-detail">
            <h3 class="blog-title">
        <a href="<?php print $node_url;?>" title=""><?php print $title;?></a>
      </h3>
            <!-- end title -->
            <div class="blog-meta">

              <div class="author inline-block">
                <?php print t('Posted By '); ?>
                  <?php print $name;?>
              </div>

              <div class="blog-category inline-block">
                <span><?php print t('in ');?></span>
                <?php if(isset($content['field_blog_categories'])) print render($content['field_blog_categories']);?>
              </div>
            </div>
            <!-- end meta -->
            <div class="blog-desc">
              <?php print render($content['body']);?>
            </div>
            <!-- end desc -->

          </div>
        </div>
        <div class="divider-1 d1 pb20">
        </div>
        <div class="blog-share text-left ">
          <h3> <i class="fa fa-share fa"></i> Share this post</h3>
          <?php print render($content['sharethis']);?>


        </div>
        <div class="box-author row ml0 mr0">
          <h3>
           <i class="fa fa-user fa"></i><?php print t(' Author'); ?>
        </h3>
          <div class="col-lg-2 col-md-2 col-sm-2 col-xs-12 text-center">
            <?php print $user_picture;?>
          </div>
          <div class="col-lg-10 col-md-10 col-sm-10 col-xs-12 author-desc">
            <h4><?php print $name;?></h4>
            <p>
              <?php
      $uid = user_load($node->uid);
      if (module_exists('profile2')) {
        $profile = profile2_load_by_user($uid, 'main');
        if (isset($profile->field_desciption[$node->language][0]['value'])) {
          print ($profile->field_desciption[$node->language][0]['value']);
        }
      }
      ?>
            </p>
          </div>
        </div>
  </div>
  <div class="blog-comment-counter">
    <h3 class="mb20"> <i class="fa fa-comments fa"></i><?php print t(' Comments ');print t('('); print $comment_count; print t(')');?></h3></div>
  <div class="comments-single">
    <?php print render($content['comments']); ?>
  </div>
