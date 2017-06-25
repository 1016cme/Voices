(function ($) {
  Drupal.behaviors.dexp_grid_masonry_admin = {
    attach: function () {
      //alert('ok');
    }
  }
})(jQuery);
jQuery(document).ready(function ($) {
  var $grid_message = $('<div class="dexp-grid-message"><span>Saved</span></div>');
  $grid_message.click(function(){
    $(this).hide();
  });
  $('body').append($grid_message);
  $('.dexp-grid.masonry-resize').each(function () {
    var $grid = $(this).find('.dexp-grid-inner'),
      view_id = $(this).attr('id'),
      options = Drupal.settings.dexp_grid_masonry[view_id];
    options.columnHeight = Math.floor(options.columnWidth / options.grid_ratio);
    $grid.find('.dexp-grid-item').resizable({
      grid: [options.columnWidth + options.grid_margin, options.columnHeight + options.grid_margin],
      autoHide: true,
      start: function () {
        $grid.data('resize', false);
      },
      resize: function () {
        $grid.shuffle('update');
      },
      stop: function (event, ui) {
        $grid.data('resize', true);
        var w = Math.round(ui.size.width / options.columnWidth),
          h = Math.round(ui.size.height / options.columnHeight),
          item = $(ui.element).data('index');
        var url = Drupal.settings.basePath + '?q=drupalexp/grid_masonry/save/' + view_id + '/' + item + '/' + w + '/' + h;
        $('.dexp-grid-message span').text('Saving...');
        $('.dexp-grid-message').show();
        $.ajax({
          url: url,
          success: function () {
            $('.dexp-grid-message span').text('Saved');
            setTimeout(function(){$('.dexp-grid-message').hide();},500);
          }
        });
      }
    });
  });
});
