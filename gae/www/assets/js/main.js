var Anchor = {
	init: function() {
		Anchor.slidey = $('.slidey');
		
		//  Uh, bind to the resizing of the window?
		$(window).resize(Anchor.bindResize).trigger('resize');
		
		//  Set up the toggle link
		Anchor.linky = $('.linky').click(Anchor.toggleSlidey);

		//  Hide the thingymabob
		setTimeout(function() {
		    //  Set up the slidey panel
		    Anchor.hideSlidey();
		    
			$('body').addClass('js-enabled');
		}, 10);
		
		//  Listen for search link
		$('a[href="#search"]').click(function() {
			if(!Anchor.linky.hasClass('active')) {
				return Anchor.toggleSlidey.call(Anchor.linky);
			}
		});
	},
	
	hideSlidey: function() {
		Anchor.slidey.css('margin-top', this._slideyHeight);
		Anchor.linky && Anchor.linky.removeClass('active');
		
		return this;
	},
	
	toggleSlidey: function() {
		var self = Anchor;
		var me = $(this);
			
		me.toggleClass('active');
		self.slidey.css('margin-top', me.hasClass('active') ? 0 : self._slideyHeight);
		
		return false;
	},
	
	bindResize: function() {
		Anchor._slideyHeight = -(Anchor.slidey.height() + 1);
		Anchor.hideSlidey();
	}
};

//  And bind loading
$(Anchor.init);