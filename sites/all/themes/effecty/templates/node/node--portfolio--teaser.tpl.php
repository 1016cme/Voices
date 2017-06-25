<?php
// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['body']);
?>
  <div id="node-<?php print $node->nid; ?>" class=" <?php print $classes; ?> clearfix" <?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
        <div class="ImageWrapper content row " <?php print $content_attributes; ?>>
          <?php
// We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_image']);

        $lightboxrel = 'portfolio';

        $portfolio_images = field_get_items('node', $node, 'field_image');
        $first_image = '';
        if ($portfolio_images) {
            foreach ($portfolio_images as $k => $portfolio_image) {
                $first_image = file_create_url($portfolio_image['uri']);
                break;
            }
        }
        ?>
            <div class="col-lg-12 col-md-12 col-sm-12 col-xs-12">
              <div class="portfolio-items">
                <div class="portfolio-images">
                  <?php print render($content['field_image']); ?>
                </div>
                <div class="portfolio-overlay">
                  <div class="porfolio-middle">

                    <div class="visible-button">
                      <a href="<?php print $node_url;?>" title="">
                        <?php print t('more info');?>
                      </a>
                    </div>
                    <div class="visible-button">
                      <a title="<?php print $title; ?>" rel="prettyPhoto[<?php print $lightboxrel; ?>]" href="<?php print $first_image;?>">
                        <?php print t('view lager');?>
                      </a>
                    </div>

                  </div>

                </div>
              </div>

            </div>

        </div>
  </div>
