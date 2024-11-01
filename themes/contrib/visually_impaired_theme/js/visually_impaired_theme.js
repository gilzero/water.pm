(function ($, Drupal) {
  Drupal.behaviors.VITheme = {
    attach(context) {
      $('.a-fontsize-small').click(function () {
        // eslint-disable-next-line
        $('body').css('fontSize', '100%');
        $('body').addClass('fontsize-small');
        $('body').removeClass('fontsize-normal');
        $('body').removeClass('fontsize-big');
        $.cookie('visually-impaired-fontsize', 'fontsize-small', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-fontsize-normal').click(function () {
        // eslint-disable-next-line
        $('body').css('fontSize', '120%');
        $('body').removeClass('fontsize-small');
        $('body').addClass('fontsize-normal');
        $('body').removeClass('fontsize-big');
        $.cookie('visually-impaired-fontsize', 'fontsize-normal', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-fontsize-big').click(function () {
        // eslint-disable-next-line
        $('body').css('fontSize', '150%');
        $('body').removeClass('fontsize-small');
        $('body').removeClass('fontsize-normal');
        $('body').addClass('fontsize-big');
        $.cookie('visually-impaired-fontsize', 'fontsize-big', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-color1').click(function () {
        // eslint-disable-next-line
        $('body').css('backgroundColor', '#fff');
        // eslint-disable-next-line
        $('body').css('color', '#000');
        $('a').each(function () {
          // eslint-disable-next-line
          $(this)
            .not('#toolbar-bar a')
            .not('#toolbar-item-administration-tray a')
            .css('color', '#309');
        });
        $('body').addClass('color1');
        $('body').removeClass('color2');
        $('body').removeClass('color3');
        $.cookie('visually-impaired-color', 'color1', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-color2').click(function () {
        // eslint-disable-next-line
        $('body').css('backgroundColor', '#000');
        // eslint-disable-next-line
        $('body').css('color', '#fff');
        $('a').each(function () {
          // eslint-disable-next-line
          $(this)
            .not('#toolbar-bar a')
            .not('#toolbar-item-administration-tray a')
            .css('color', '#fff');
        });
        $('body').removeClass('color1');
        $('body').addClass('color2');
        $('body').removeClass('color3');
        $.cookie('visually-impaired-color', 'color2', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-color3').click(function () {
        // eslint-disable-next-line
        $('body').css('backgroundColor', '#9dd1ff');
        // eslint-disable-next-line
        $('body').css('color', '#063462');
        $('a').each(function () {
          // eslint-disable-next-line
          $(this)
            .not('#toolbar-bar a')
            .not('#toolbar-item-administration-tray a')
            .css('color', '#309');
        });
        $('body').removeClass('color1');
        $('body').removeClass('color2');
        $('body').addClass('color3');
        $.cookie('visually-impaired-color', 'color3', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-imgcolor').click(function () {
        $('img').each(function () {
          $(this).removeClass('img-grayscale');
          $(this).removeClass('hidden');
        });
        $('body').addClass('imgcolor');
        $('body').removeClass('imggray');
        $('body').removeClass('imgnone');
        $.cookie('visually-impaired-images', 'imgcolor', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-imggray').click(function () {
        $('img').each(function () {
          $(this).addClass('img-grayscale');
          $(this).removeClass('hidden');
        });
        $('body').removeClass('imgcolor');
        $('body').addClass('imggray');
        $('body').removeClass('imgnone');
        $.cookie('visually-impaired-images', 'imggray', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-imgnone').click(function () {
        $('img').each(function () {
          $(this).addClass('hidden');
        });
        $('body').removeClass('imgcolor');
        $('body').removeClass('imggray');
        $('body').addClass('imgnone');
        $.cookie('visually-impaired-images', 'imgnone', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-kernstd').click(function () {
        // eslint-disable-next-line
        $('body').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('.access').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('#toolbar-bar').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('#toolbar-item-administration-tray').css('letterSpacing', 'normal');
        $('body').addClass('kernstd');
        $('body').removeClass('kernmid');
        $('body').removeClass('kernbig');
        $.cookie('visually-impaired-kerning', 'kernstd', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-kernmid').click(function () {
        // eslint-disable-next-line
        $('body').css('letterSpacing', '2px');
        // eslint-disable-next-line
        $('.access').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('#toolbar-bar').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('#toolbar-item-administration-tray').css('letterSpacing', 'normal');
        $('body').removeClass('kernstd');
        $('body').addClass('kernmid');
        $('body').removeClass('kernbig');
        $.cookie('visually-impaired-kerning', 'kernmid', {
          expires: 30,
          path: '/',
        });
      });

      $('.a-kernbig').click(function () {
        // eslint-disable-next-line
        $('body').css('letterSpacing', '4px');
        // eslint-disable-next-line
        $('.access').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('#toolbar-bar').css('letterSpacing', 'normal');
        // eslint-disable-next-line
        $('#toolbar-item-administration-tray').css('letterSpacing', 'normal');
        $('body').removeClass('kernstd');
        $('body').removeClass('kernmid');
        $('body').addClass('kernbig');
        $.cookie('visually-impaired-kerning', 'kernbig', {
          expires: 30,
          path: '/',
        });
      });

      $('.access', context)
        .once('VITheme')
        .each(function () {
          if ($.cookie('visually_impaired') === 'on') {
            if ($('body').hasClass('user-logged-in')) {
              // eslint-disable-next-line
              $(this).css('top', '78px');
              // eslint-disable-next-line
              $('.access').css('z-index', '1');
            }

            switch ($.cookie('visually-impaired-fontsize')) {
              case 'fontsize-small':
                $('.a-fontsize-small').click();
                break;
              case 'fontsize-normal':
                $('.a-fontsize-normal').click();
                break;
              case 'fontsize-big':
                $('.a-fontsize-big').click();
                break;
            }

            switch ($.cookie('visually-impaired-color')) {
              case 'color1':
                $('.a-color1').click();
                break;
              case 'color2':
                $('.a-color2').click();
                break;
              case 'color3':
                $('.a-color3').click();
                break;
            }

            switch ($.cookie('visually-impaired-images')) {
              case 'imgcolor':
                $('.a-imgcolor').click();
                break;
              case 'imggray':
                $('.a-imggray').click();
                break;
              case 'imgnone':
                $('.a-imgnone').click();
                break;
            }

            switch ($.cookie('visually-impaired-kerning')) {
              case 'kernstd':
                $('.a-kernstd').click();
                break;
              case 'kernmid':
                $('.a-kernmid').click();
                break;
              case 'kernbig':
                $('.a-kernbig').click();
                break;
            }
          }
        });
    },
  };
})(jQuery, Drupal);
