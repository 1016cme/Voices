(function ($) {
	Drupal.behaviors.drupalexp_effecty = {
		attach: function (context, settings) {
			$('.dexp-menu').find('ul.menu').onePageNav({
				currentClass: 'active',
				changeHash: true,
				end: function(){
					$('.dexp-menu').removeClass('open');
				}
			});
		}
	}
})(jQuery);
