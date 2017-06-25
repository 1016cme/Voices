(function ($) {
  Drupal.behaviors.dexp_bxslider = {
    attach: function (context, settings) {
      $('.dexp-bxslider').once('dexp-bxslider', function () {
        var $this = $(this),
          responsiveID = $(this).attr('id');
        settings.dexpbxsliders[responsiveID].total = $('.bxslide', $this).length;
        var options = dexp_adjust_options(settings.dexpbxsliders[responsiveID], $this.innerWidth());
        options.pagerCustom = options.pagerCustom || '';
        settings.dexpbxsliders[responsiveID].pageCustomClone = null;
        if(options.pagerCustom != '' && $(options.pagerCustom).length == 1){
          settings.dexpbxsliders[responsiveID].pageCustomClone = $(options.pagerCustom).clone();
        }
        //if(options.pagerCustom)
        //console.log(options);
        //return;
        //var slide = null;
        var slide = $(this).bxSlider(options);
        //return;
        if (options.auto) {
          setInterval(function () {
            slide.startAuto();
          }, options.pause);
        }
        var windowW = $(window).width();
        var resizeH = null;
        $(window).resize(function () {
          clearTimeout(resizeH);
          resizeH = setTimeout(function () {
            //console.log(windowW);
            //console.log($(window).width());
            if (windowW == $(window).width()) return;
            windowW = $(window).width();
            //slide.destroySlider();
            //options = dexp_adjust_options(settings.dexpbxsliders[responsiveID], $this.innerWidth());
            //slide = $this.bxSlider(options);
            //$this.after($pageCustom);
            slide = dexp_adjust_slide($this, settings.dexpbxsliders[responsiveID], slide);
          }, 1000);
        }).load(function(){
          //console.log(responsiveID);
          //$this.after($pageCustom);
          slide = dexp_adjust_slide($this, settings.dexpbxsliders[responsiveID], slide);
        });
      });
    }
  };

  function dexp_adjust_slide(slide_element, options, slide_handler){
    slide_handler.destroySlider();
    $(options.pagerCustom).remove();
    slide_element.after(options.pageCustomClone);
    var new_options = dexp_adjust_options(options, slide_element.innerWidth());
    return slide_element.bxSlider(new_options);
  }

  /*Adjust bxslider options to fix on any screen*/
  function dexp_adjust_options(options, container_width) {
    var _options = {};
    $.extend(_options, options);
    var wWidth = $(window).width();
    if (wWidth >= 1200) {
      _options.maxSlides = _options.minSlides = parseInt(options.lg_items);
    } else if (wWidth > 991 && wWidth < 1200) {
      _options.maxSlides = _options.minSlides = parseInt(options.md_items);
    } else if (wWidth > 767 && wWidth < 992) {
      _options.maxSlides = _options.minSlides = parseInt(options.sm_items);
    } else {
      _options.maxSlides = _options.minSlides = parseInt(options.xs_items);
    }
    if (_options.maxSlides > _options.total) {
      //_options.maxSlides = _options.minSlides = options.total;
    }
    _options.slideWidth = (container_width - (_options.slideMargin * (_options.maxSlides - 1))) / _options.maxSlides;
    //console.log(_options);
    return _options;
  }
})(jQuery);
