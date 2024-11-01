/**
 * @file
 * Defines Javascript behaviors for the W3CSS Theme.
 */
(function (Drupal, $, once) {
  'use strict';
  // Used for fixed menu.
  let origOffsetY;
  let didScroll = false;
  let mainNavigation = document.querySelector('#main-navigation-h');
  // Remove Fa class from social links.
  if ($('.social-media > a > i').length > 0) {
    if ($('.social-media > a > i').hasClass('fa')) {
      $('.social-media > a > i').removeClass('fa')
    }
  }
  // In case the admin toolbar search installed.
  if ($('#admin-toolbar-search-tab').length > 0) {
    $('#admin-toolbar-search-tab > div').removeClass('w3-section');
  }
  // In case the main menu not printed.
  if ($('#main-navigation-h .ul-parent').length > 0) {
    origOffsetY = mainNavigation.offsetTop;
  }
  // Add flex position to the main menu at scroll.
  let scrollWindow = function () {
    didScroll = true;
    if (mainNavigation) {
      if (window.scrollY > origOffsetY) {
        mainNavigation.classList.add('w3-sticky');
      } else {
        mainNavigation.classList.remove('w3-sticky');
      }
    }
  };
  setInterval(function () {
    if (didScroll) {
      didScroll = false;
    }
  }, 100);
  // Add and remove classes on window resize.
  let mediaSize = function () {
    let currentWidth = window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth;
    let mainMenuChild = $('#main-navigation-h').css('background-color');
    const bodyTag = $('body');
    if (currentWidth >= 993) {
      // Add class to the body for large screen.
      bodyTag.addClass('large-screen').removeClass('small-screen', 'medium-screen');
      $('.ul-parent').removeClass('w3-show');
      $('.ul-child').removeClass('w3-show');
      $('.ul-responsive-h .ul-parent').removeAttr('style');
      $('.ul-responsive-h .ul-child').removeAttr('style');
      $('#main-navigation-h .ul-parent').removeAttr('style');
      $('#main-navigation-h .ul-child').removeAttr('style').css('background-color', mainMenuChild);
      if ($('.top-container-inner > div').length > 1) {
        $('.top-container-inner').addClass('w3-f-display');
      }
      if ($('.main-container-inner > .w3-clear > div').length > 1) {
        $('.main-container-inner > .w3-clear').addClass('w3-f-display');
      }
      if ($('.bottom-container-inner > div').length > 1) {
        $('.bottom-container-inner').addClass('w3-f-display');
      }
      if ($('.footer-container-inner > div').length > 1) {
        $('.footer-container-inner').addClass('w3-f-display');
      }
    } else {
      // Remove the match height on medium/small screen.
      $('.top-container-inner, .main-container-inner > .w3-clear, .bottom-container-inner, .footer-container-inner').removeClass('w3-f-display');
    }
    if ((currentWidth >= 601) && (currentWidth <= 992)) {
      // Add class to the body for medium screen.
      bodyTag.addClass('medium-screen').removeClass('large-screen', 'small-screen');
    }
    if (currentWidth <= 600) {
      // Add class to the body for small screen.
      bodyTag.addClass('small-screen').removeClass('large-screen', 'medium-screen');
    }
  };

  function show_hide($this) {
    if ($this.next().hasClass('show')) {
      $this.next().removeClass('show');
      $this.next().slideUp(350);
    } else {
      $this.parent().parent().find('li .ul-child').removeClass('show');
      $this.parent().parent().find('li .ul-child').slideUp(350);
      $this.next().toggleClass('show');
      $this.next().slideToggle(350);
    }
  }
  Drupal.behaviors.d8w3cssMenuDepth = {
    attach: function (context, settings) {
      // Add class to any UL/LI according to the depth.
      $(once('body', 'ul', context)).each(function () {
        let depth = $(this).parents('ul').length;
        $(this).addClass('ul-' + depth);
      });
      $(once('ul', 'li', context)).each(function () {
        let depth = $(this).parents('li').length;
        $(this).addClass('li-' + depth);
      });
    }
  };
  Drupal.behaviors.d8w3cssResponsiveMenu = {
    attach: function (context, settings) {
      // $(context)
      //   .find('.mobile-nav-responsive')
      //   .once('.mobile-nav-responsive')
      $(once('.mobile-nav-responsive', '.mobile-nav-responsive', context)).on('click', function () {
        if ($('.ul-responsive-h .ul-parent').is(':hidden')) {
          $('.ul-responsive-h .ul-parent').slideDown(350);
        } else {
          $('.ul-responsive-h .ul-parent').slideUp(350);
          if ($('.ul-responsive-h .ul-parent li .ul-child')) {
            $('.ul-responsive-h .ul-parent li .ul-child').removeClass('show');
            $('.ul-responsive-h .ul-parent li .ul-child').slideUp(350);
          }
        }
      });
      $(once('body', '.tMenu-v', context)).on('click', function (e) {
        e.preventDefault();
        let $this = $(this);
        show_hide($this);
      });
      $(once('body', '.clickable-dropdown-menu-fa-down', context)).on('click', function () {
        let $this = $(this);
        show_hide($this);
      });
      $(once('body', '.clickable-dropdown-menu-fa-down-h', context)).on('click', function () {
        let $this = $(this);
        show_hide($this);
      });
      $(once('body', '.clickable-dropdown-menu-fa-down-v', context)).on('click', function () {
        let $this = $(this);
        show_hide($this);
      });
    }
  };
  Drupal.behaviors.d8w3cssMainNav = {
    attach: function (context, settings) {
      // Change the sub menu color as the main menu.
      const mainMenuChild = $('.main-navigation-wrapper').css('background-color');
      $(once('body', '.main-navigation-wrapper .ul-child', context)).css('background-color', mainMenuChild);
      // On click show/hide the vertical main menu.
      $(once('#main-navigation-v', '#close-nav', context)).on('click', function () {
        document.getElementById('main-navigation-v').style.display = 'none';
        if ($('#main-navigation-v .ul-parent li .ul-child')) {
          $('#main-navigation-v .ul-parent li .ul-child').removeClass('show');
          $('#main-navigation-v .ul-parent li .ul-child').slideUp(350);
        }
      });
      $(once('body', '#open-nav-inner', context)).on('click', function () {
        document.getElementById('main-navigation-v').style.display = 'block';
      });
      // Show the mobile menu on click horizontal.
      $(once('#main-navigation-h', '.mobile-nav', context)).on('click', function () {
        if ($('#main-navigation-h .ul-parent').is(':hidden')) {
          $('#main-navigation-h .ul-parent').slideDown(350);
        } else {
          $('#main-navigation-h .ul-parent').slideUp(350);
          if ($('#main-navigation-h .ul-parent li .ul-child')) {
            $('#main-navigation-h .ul-parent li .ul-child').removeClass('show');
            $('#main-navigation-h .ul-parent li .ul-child').slideUp(350);
          }
        }
      });
      // On click expand the dropdown menu for small device.
      $(once('body', '.tMenu', context)).on('click', function (e) {
        e.preventDefault();
        let currentWidth = window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth;
        let $this = $(this);
        if ((currentWidth <= 992) || ($('#main-navigation-v').css('display') === 'block')) {
          show_hide($this);
        }
      });
    }
  };
  Drupal.behaviors.d8w3cssTheme = {
    attach: function (context, settings) {
      // Change the form color to match the footer color.
      const footerFormBg = $('#footer-menu').css('background-color')
      const footerFormTxt = $('#footer-menu').css('color');
      $(once('#footer-menu', '#footer-menu form', context)).css('background-color', footerFormBg).css('color', footerFormTxt);
      // apply background and color to opened dialog.
      let layoutBuilderBox = function () {
        if ($('.ui-dialog').is(':visible')) {
          const pageTitleBg = $('#page-title').css('background-color');
          const pageTitleTxt = $('#page-title h1').css('color');
          const mainContainerBg = $('#main-container').css('background-color');
          const mainContainerTxt = $('#main-container p').css('color');
          $(once('.ui-dialog', '.ui-dialog .ui-dialog-titlebar', context)).css('background', pageTitleBg).css('color', pageTitleTxt);
          $(once('body', '.ui-dialog', context)).css('background', mainContainerBg).css('color', mainContainerTxt);
          $(once('.ui-dialog', '.ui-dialog .ui-dialog-content', context)).css('background', mainContainerBg).css('color', mainContainerTxt);
          $(once('.ui-dialog', '.ui-dialog .ui-dialog-buttonpane', context)).css('background', footerFormBg).css('color', footerFormTxt);
        }
      }
      // Add classes to search page.
      $(once('.search-form', '.search-form .search-advanced', context)).addClass('w3-padding-large w3-border w3-bar w3-left-align w3-margin-bottom');
      $(once('.search-form', '.search-form .search-advanced > summary', context)).addClass('w3-button w3-bar w3-left-align');
      $(once('.search-form', '.search-form .search-help-link', context)).addClass('w3-button w3-right w3-border w3-margin-top');
      $(once('.tabledrag-toggle-weight-wrapper', '.tabledrag-toggle-weight-wrapper button', context)).addClass('w3-button');
      // Theme settings.
      $(once('#system-theme-settings', '#system-theme-settings details', context)).removeAttr('open').addClass('w3-border w3-bar w3-left-align w3-margin-bottom');
      $(once('#system-theme-settings', '#system-theme-settings details > summary', context)).addClass('w3-button w3-bar w3-left-align');
      $(once('#system-theme-settings', '#system-theme-settings details > .details-wrapper', context)).addClass('w3-padding w3-left-align');
      // Disable top margin if breadcrumb exist.
      if (document.querySelector('nav.breadcrumb')) {
        $(once('body', '.main-box', context)).addClass('breadcrumb-found');
      }
      $(once('body', 'a > .w3-image', context)).each(function () {
        $(this).parent().addClass('d8-has-image');
      });
      mediaSize();
      window.addEventListener('resize', mediaSize);
      window.addEventListener('scroll', scrollWindow);
    }
  };
})(Drupal, jQuery, once);
