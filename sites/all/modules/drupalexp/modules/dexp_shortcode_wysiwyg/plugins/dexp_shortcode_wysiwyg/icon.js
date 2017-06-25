(function ($) {
  Drupal.behaviors.dexp_shortcode_icon = {
    attach: function(context, settings){
      //console.log(Drupal.settings.font_awesome_icons);
      $('.icon-picker').once('icon-picker', function(){
        var $this=$(this), $icons = $('<ul class="icons-list">');
        var $markup = $('<a href="#"><span class="icon-markup fa fa-home"></span></a>');
        $markup.find('span').addClass($this.val());
        $markup.click(function(){
          $icons.toggle();
          return false;
        });
        $(Drupal.settings.font_awesome_icons).each(function(){
          var $icon = $('<li><a href="#"><span class="fa '+this+'"></span>'+this+'</a></li>');
          var icon_class = this.toString();
          $icon.find('a').click(function(e){
            e.preventDefault();
            $this.val('fa ' + icon_class);
            $markup.find('span').attr('class','icon-markup').addClass('fa ' + icon_class);
            $icons.hide();
            return false;
          });
          $icons.append($icon);
        });
        $(this).after($icons).after($markup);
      });
    }
  }
})(jQuery)
