/*!
 * hoverIntent v1.8.0 // 2014.06.29 // jQuery v1.9.1+
 * http://cherne.net/brian/resources/jquery.hoverIntent.html
 *
 * You may use hoverIntent under the terms of the MIT license. Basically that
 * means you are free to use hoverIntent as long as this header is left intact.
 * Copyright 2007, 2014 Brian Cherne
 */
(function($){$.fn.hoverIntent=function(handlerIn,handlerOut,selector){var cfg={interval:100,sensitivity:6,timeout:0};if(typeof handlerIn==="object"){cfg=$.extend(cfg,handlerIn)}else{if($.isFunction(handlerOut)){cfg=$.extend(cfg,{over:handlerIn,out:handlerOut,selector:selector})}else{cfg=$.extend(cfg,{over:handlerIn,out:handlerIn,selector:handlerOut})}}var cX,cY,pX,pY;var track=function(ev){cX=ev.pageX;cY=ev.pageY};var compare=function(ev,ob){ob.hoverIntent_t=clearTimeout(ob.hoverIntent_t);if(Math.sqrt((pX-cX)*(pX-cX)+(pY-cY)*(pY-cY))<cfg.sensitivity){$(ob).off("mousemove.hoverIntent",track);ob.hoverIntent_s=true;return cfg.over.apply(ob,[ev])}else{pX=cX;pY=cY;ob.hoverIntent_t=setTimeout(function(){compare(ev,ob)},cfg.interval)}};var delay=function(ev,ob){ob.hoverIntent_t=clearTimeout(ob.hoverIntent_t);ob.hoverIntent_s=false;return cfg.out.apply(ob,[ev])};var handleHover=function(e){var ev=$.extend({},e);var ob=this;if(ob.hoverIntent_t){ob.hoverIntent_t=clearTimeout(ob.hoverIntent_t)}if(e.type==="mouseenter"){pX=ev.pageX;pY=ev.pageY;$(ob).on("mousemove.hoverIntent",track);if(!ob.hoverIntent_s){ob.hoverIntent_t=setTimeout(function(){compare(ev,ob)},cfg.interval)}}else{$(ob).off("mousemove.hoverIntent",track);if(ob.hoverIntent_s){ob.hoverIntent_t=setTimeout(function(){delay(ev,ob)},cfg.timeout)}}};return this.on({"mouseenter.hoverIntent":handleHover,"mouseleave.hoverIntent":handleHover},cfg.selector)}})(jQuery);
(function ($) {
    var DEXP_MENU = DEXP_MENU || {};
    DEXP_MENU.ww = $(window).width();
    DEXP_MENU.is_mobile = DEXP_MENU.ww < 992;
    DEXP_MENU.submenu = null;
    $(window).resize(function(){
        DEXP_MENU.ww = $(window).width();
        DEXP_MENU.is_mobile = DEXP_MENU.ww < 992;
    });
    Drupal.behaviors.dexp_menu = {
        attach: function (context, settings) {
            $('.dexp-dropdown ul.menu > li.expanded').once('hover', function () {
                $(this).hoverIntent(function () {
                    DEXP_MENU.submenu = $(this).find('>ul, >.dexp-menu-mega');
                    if(DEXP_MENU.submenu.length == 0) return;
                    DEXP_MENU.submenu.addClass('menu-visible');
                    if(!DEXP_MENU.is_mobile){
                        /*Mega menu fullwidth*/
                        if(DEXP_MENU.submenu.hasClass('container')){
                            var transformX = (DEXP_MENU.ww - DEXP_MENU.submenu.outerWidth())/2 - DEXP_MENU.submenu.offset().left;
                            transformX = parseInt(transformX);
                            console.log(transformX);
                            DEXP_MENU.submenu.css('transform','translateX('+transformX+'px)');
                        }else{
                            /*Normal submenu*/
                            /*LTR direction*/
                            if($('body').hasClass('ltr')){
                                var offsetX = DEXP_MENU.submenu.offset().left + DEXP_MENU.submenu.outerWidth() - DEXP_MENU.ww + ($(window).width() - $('.dexp-body-inner').width())/2;
                                if (offsetX > 0) {
                                    var transformX = 0;
                                    if(DEXP_MENU.submenu.parent().parent().parent().is('div')){
                                      transformX = 0 - offsetX + 'px';
                                    }else{
                                      transformX = 0 - DEXP_MENU.submenu.width()*2 + 'px';
                                    }
                                    DEXP_MENU.submenu.css('transform', 'translateX('+transformX+')');
                                }
                            }else{
                                var offsetX =  DEXP_MENU.submenu.offset().left - ($(window).width() - $('.container').width())/2;
                                if (offsetX < 0){
                                    var transformX = parseInt(0 - offsetX);
                                    DEXP_MENU.submenu.css('transform', 'translateX('+transformX+'px)');
                                }
                            }
                        }
                    }
                }, function () {
                    $(this).find('>ul, >.dexp-menu-mega').removeClass('menu-visible').css('transform','translateX(0)');
                });
            });

            $('.dexp-menu-toggler').once('click', function(){
                $(this).click(function(){
                    var $menu = $($(this).data('target'));
                    $menu.toggleClass('open');
                    if($menu.offset().left != 0){
                        $menu.css('left',0);
                        var left = 0-$menu.offset().left;
                        $menu.css('left',left+'px');
                    }
                });
            });
            $('.dexp-menu span.menu-toggle').once('click', function(){
                $(this).click(function(){
                    $(this).toggleClass('fa-angle-right fa-angle-down').parent().find('>ul.menu, >div.dexp-menu-mega').toggleClass('menu-visible-mobile');
                });
            });
        }
    }
})(jQuery);
