(function ($) {

  Drupal.behaviors.MenuMobile = {
    attach: function(context, settings) {
      // Trigger menu hide/show when in mobile display
      $('#navburger').click(function(e) {
        $('body').toggleClass('with-menu');
        e.stopPropagation();
      });
    }
  };

})(jQuery);
