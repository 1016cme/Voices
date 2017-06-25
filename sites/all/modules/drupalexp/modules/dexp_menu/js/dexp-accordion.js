(function($){
	Drupal.behaviors.dexp_accordion = {
    	attach: function(context,settings) {
    		$('.dexp-menu-accordion').each(function(){
    			var $this = $(this);
    			$this.find('span.menu-toggle').click(function(){
    				$(this).parent('li').toggleClass('menu-expanded');
    				if($(this).parent('li').hasClass('menu-expanded')){
    					$this.find('li').not($(this).parents('li')).removeClass('menu-expanded');
    				}
    			});
                $this.find('ul li a').data({click:true}).on('touchstart',function() {
                    var $link = $(this),$li = $(this).parent();
                    if($li.find('ul,.dexp-menu-mega').length > 0){
                        $link.data({
                            click:  $link.data('click').toString() == 'true'?false:true
                        });
                    }
                    $('.dexp-menu-accordion ul li a').not($link).data({click:true});
                    if($link.data('click') == false){
                        $(this).parent().addClass('menu-expanded');
                    }
                    return $link.data('click');
                });
    		})
    	}
	}
})(jQuery)