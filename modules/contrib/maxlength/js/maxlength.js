(function ($, Drupal, once) {

  // Make variables local.
  var ml = ml || {};
  ml.options = ml.options || {};

  /**
   * Maxlength JS behaviour.
   *
   * @type {Drupal~behavior}
   */
  Drupal.behaviors.maxlength = {
    attach: function(context) {
      let $context = $(context);

      $(once('maxlength', $context.find('.maxlength').filter(':input'))).each(function () {
        let options = {};
        let $this = $(this);
        options['counterText'] = $this.attr('maxlength_js_label');
        if ($this.hasClass('maxlength_js_enforce')) {
          options['enforce'] = true;
          options.cssExceeded = 'error';
        }
        $this.charCount(options);

        // CKEditor 5 integration.
        if (this.dataset.ckeditor5Id) {
          let eid = this.dataset.ckeditor5Id;
          //@todo Tempfix until the issue below is fixed.
          // https://www.drupal.org/project/drupal/issues/3319358
          setTimeout(function() {
            ml.ckeditor5(Drupal.CKEditor5Instances.get(eid), options);
          }, 400);
        }

        // Set up a mutation observer to re-attach this behavior when the text
        // format has been changed. Observer will act on changes to the
        // 'data-ckeditor5-id' attribute on the field.
        // @see Drupal.editors.ckeditor5.attach() and setElementId() in Drupal core ckeditor5.js
        if (Drupal.hasOwnProperty('CKEditor5Instances')) {
          const observerOptions = {
            attributes: true,
            attributeFilter: ['data-ckeditor5-id']
          };
          const observer = new MutationObserver((mutations) => {
            mutations.forEach((mutation) => {
              const eid = mutation.target.dataset.ckeditor5Id;
              if (!Drupal.CKEditor5Instances.has(eid)) {
                observer.disconnect();
                Drupal.behaviors.maxlength.detach(context);
                Drupal.behaviors.maxlength.attach(context);
                // Remove `maxlengthbinding` set by ml.ckeditor5().
                once.remove('maxlengthbinding', mutation.target);
              }
            });
          });
          observer.observe(this, observerOptions);
        }
      });
    },
    detach: function(context, settings) {
      let $context = $(context);
      $(once.remove('maxlength', $context.find('.maxlength'))).each(function () {
        $(this).charCount({
          action: 'detach'
        });
      });
    }
  };

  /**
   * Code below is based on:
   *   Character Count Plugin - jQuery plugin
   *   Dynamic character count for text areas and input fields
   *   written by Alen Grakalic
   *   https://gist.github.com/Fabax/4724890
   *
   *  @param obj
   *    A jQuery object for input elements.
   *  @param options
   *    The array containing the maxlength configurations.
   *  @param count
   *    In case obj.val() wouldn't return the text to count, this should
   *    be passed with the number of characters.
   *  @param wysiwyg
   *    The ckeditor.
   *  @param getter
   *    The name of the data getter function.
   *  @param setter
   *    The name of the data setter function.
   */
  ml.calculate = function(obj, options, count, wysiwyg, getter, setter) {
    let counter = $('#' + obj.attr('id') + '-' + options.css);
    let limit = parseInt(obj.attr('data-maxlength'));

    // Set the aria-describedby attribute to associate obj with the counter.
    obj.attr('aria-describedby', counter.attr('id'));

    if (count === undefined) {
      count = ml.strip_tags(obj.val()).length;
    }

    let available = limit - count;

    if (available <= options.warning) {
      counter.addClass(options.cssWarning);
    }
    else {
      counter.removeClass(options.cssWarning);
    }

    if (available < 0) {
      counter.addClass(options.cssExceeded);
      // Trim text.
      if (options.enforce) {
        if (wysiwyg !== undefined) {
          if (typeof ml[getter] == 'function' && typeof ml[setter] == 'function') {
            let new_html = ml.truncate_html(ml[getter](wysiwyg), limit);
            ml[setter](wysiwyg, new_html);
            count = ml.strip_tags(new_html).length;
          }
        } else {
          obj.val(ml.truncate_html(obj.val(), limit));
          // Re-calculate text length.
          count = ml.strip_tags(obj.val()).length;
        }
      }
      available = limit - count;
    }
    else {
      counter.removeClass(options.cssExceeded);
    }

    counter.html(options.counterText.replace('@limit', limit).replace('@remaining', available).replace('@count', count));

    // Announce important character count milestones to assist screen reader users.
    switch (available) {
      case 10:
        Drupal.announce(Drupal.t('Only 10 characters left'));
        break;
      case 0:
        Drupal.announce(Drupal.t('You have 0 characters left'));
        break;
      default:
        if (available < 0) {
          Drupal.announce(Drupal.t('You have exceeded the limit by @available characters', {'@available': Math.abs(available)}));
        }
        break;
    }
  };

  /**
   * Replaces line endings with "\n".
   *
   *  @param str
   *   The given string to replace line endings for.
   *
   * @see https://stackoverflow.com/questions/1761051/difference-between-n-and-r/1761086#1761086
   */
  ml.unify_lineending = function(str) {
    return str.replace(/(\r\n\r\n|\r\r|\n\n|\r\n|\r|\n)/g, "\n");
  };

  /**
   * Function to strip tags of a given input.
   *
   *  @param input
   *   The given string to strip tags for.
   *  @param allowed
   *   Allowed tags, defaults to empty.
   *
   * @see http://www.sitepoint.com/blogs/2004/02/16/line-endings-in-javascript/
   */
  ml.strip_tags = function(input, allowed) {
    // Remove all newlines, spaces and tabs from the beginning and end of html.
    input = input.trim();
    // Make sure line ending characters are unified.
    input = ml.unify_lineending(input);
    // Making sure the allowed arg is a string containing only tags in
    // lowercase (<a><b><c>).
    allowed = (((allowed || "") + "")
        .toLowerCase()
        .match(/<[a-z][a-z0-9]*>/g) || [])
        .join('');
    let tags = /<\/?([a-z][a-z0-9]*)\b[^>]*>/gi,
        commentsAndPhpTags = /<!--[\s\S]*?-->|<\?(?:php)?[\s\S]*?\?>/gi,
        emptyTags = />[ ]{1,}</gi;
    input = input
        .replace(emptyTags, '><')
        .replace(commentsAndPhpTags, '')
        .replace(tags, function($0, $1){
          return allowed.indexOf('<' + $1.toLowerCase() + '>') > -1 ? $0 : '';
        });

    // Replace all html entities with a single character (#) placeholder.
    return input.replace(/&([a-z]+);/g, '#');
  };

  /**
   * Cuts an HTML text up to limit characters.
   *
   *  @param text
   *   The given text to truncate.
   *  @param limit
   *   The number of characters to which we need to limit the text.
   */
  ml.truncate_html = function(text, limit) {
    // The html result after cut.
    let result_html = '';
    // The text result, that will be actually used when counting characters.
    let result_text = '';
    // A stack that will keep the tags that are open at a given time.
    let tags_open = [];
    // List of self-closing tags
    let self_closing_tags = [
      'area',
      'base',
      'br',
      'col',
      'command',
      'embed',
      'hr',
      'img',
      'input',
      'keygen',
      'link',
      'meta',
      'param',
      'source',
      'track',
      'wbr'
    ];
    // Make sure line ending characters are unified.
    text = ml.unify_lineending(text);
    while (result_text.length < limit && text.length > 0) {
      switch (text.charAt(0)) {
        case '<': {
          if (text.charAt(1) !== '/') {
            let tag_name = '';
            let tag_name_completed = false;
            while (text.charAt(0) !== '>' && text.length > 0) {
              let first_char = text.charAt(0).toString();
              // Until the tag is closed, we do not append anything
              // to the visible text, only to the html.
              result_html += first_char;
              // Also, check if we have a valid tag name.
              if (!tag_name_completed && first_char === ' ') {
                // We have the tag name, so push it into the open tags stack.
                tag_name_completed = true;
                if (self_closing_tags.indexOf(tag_name) === -1) {
                  tags_open.push(tag_name);
                }
              }
              // Check if we are still in the tag name.
              if (!tag_name_completed && first_char !== '<') {
                tag_name += first_char;
              }
              // Done with this char, remove it from the original text.
              text = text.substring(1);
            }
            if (!tag_name_completed && self_closing_tags.indexOf(tag_name) === -1) {
              // In this case we have a tag like "<strong>some text</strong>" so
              // we did not have any attributes in the tag, but still, the tag
              // has to be marked as open. If tag is self-closing, we skip.
              tags_open.push(tag_name);
            }
            // We are here, then the tag is closed, so just remove the
            // remaining ">" character.
            if (text.length > 0) {
              result_html += text.charAt(0).toString();
            }
          } else {
            // In this case, we have an ending tag.
            // The name of the ending tag should match the last open tag,
            // otherwise, something is wrong with the html text.
            let tag_name = '';
            while (text.charAt(0) !== '>' && text.length > 0) {
              let first_char = text.charAt(0).toString();
              if (first_char !== '<' && first_char !== '/') {
                tag_name += first_char;
              }
              result_html += first_char;
              text = text.substring(1);
            }
            if (text.length > 0) {
              result_html = result_html + text.charAt(0).toString();
            }
            // Pop the last element from the tags stack and compare it with
            // the tag name.
            let expected_tag_name = tags_open.pop();
            if (expected_tag_name !== tag_name) {
              // Should throw an exception, but for the moment just alert.
              alert('Expected end tag: ' + expected_tag_name + '; Found end tag: '+tag_name);
            }
          }
          break;
        }
        case '&': {
          // Don't truncate in the middle of an html entity count it as 1.
          entities = text.match(/&([a-z]+);/g);
          if (entities) {
            nextEntity = entities[0];
            result_html += nextEntity;
            result_text += '#';
            text = text.slice(nextEntity.length - 1);
            break;
          }
        }
        default: {
          // In this case, we have a character that should also count for the
          // limit, so append it to both, the html and text result.
          let first_char = text.charAt(0).toString();
          result_html += first_char;
          result_text += first_char;
          break;
        }
      }
      // Remove the first character, it did its job.
      text = text.substring(1);
    }
    // Restore the open tags that were not closed. This happens when the text
    // got truncated in the middle of one or more html tags.
    let tag = '';
    while (tag = tags_open.pop()) {
      result_html += '</' + tag + ">";
    }
    return result_html;
  }

  /**
   * Character counter function that sets the character count message.
   *
   *  @param options
   *    The array containing maxlength configurations.
   */
  $.fn.charCount = function(options) {
    // Default configuration properties.
    let defaults = {
      warning: 10,
      css: 'counter',
      counterElement: 'div',
      cssWarning: 'warning',
      cssExceeded: 'soft-error',
      counterText: Drupal.t('Content limited to @limit characters, remaining: <strong>@remaining</strong>'),
      action: 'attach',
      enforce: false,
    };

    options = $.extend(defaults, options);
    ml.options[$(this).attr('id')] = options;

    if (options.action === 'detach') {
      $(once.remove('maxlength', $(this)));
      $('#' + $(this).attr('id') + '-' + options.css).remove();
      delete ml.options[$(this).attr('id')];
      return 'removed';
    }

    let sanitizedId = ($(this).attr('id') + '-' + options.css).replace(/[^0-9a-z-_]/gi, '');
    let counterElement = $('<' + options.counterElement + ' id="' + sanitizedId + '" class="' + options.css + '"></' + options.counterElement + '>');
    // Use there is a description element use it to place the counterElement.
    let describedBy = $(this).attr('aria-describedby');
    if (describedBy && $('#' + describedBy).length) {
      $('#' + describedBy).after(counterElement);
    }
    else if ($(this).next('div.grippie').length) {
      $(this).next('div.grippie').after(counterElement);
    }
    else if ($(this).next('div.cke_chrome').length) {
      $(this).next('div.cke_chrome').after(counterElement);
    }
    else {
      $(this).after(counterElement);
    }

    ml.calculate($(this), options);
    $(this).keyup(function() {
      ml.calculate($(this), options);
    });
    $(this).change(function() {
      ml.calculate($(this), options);
    });

  };

  /**
   * Function that integrates maxlength behaviour with CKEditor 5.
   *
   *  @param editor
   *    The ckeditor that has the "maxlength" class.
   *  @param options
   *    The array containing the maxlength configurations.
   */
  ml.ckeditor5 = function (editor, options) {
    $(once('maxlengthbinding', editor.sourceElement)).each(function() {
      // Listen to changes to data only.
      editor.model.document.on('change:data', function() {
        let editorData = editor.getData();
        if (editorData !== editor.sourceElement.textContent) {
          // Trim if limit is reached and enforcing is activated.
          if (options['enforce']) {
            let maxlength = $(editor.sourceElement).data('maxlength');
            const trimmed = ml.truncate_html(editorData, maxlength);
            if (editorData.length !== trimmed.length) {
              editor.setData(trimmed);
              setTimeout(() => {
                editor.model.change( writer => {
                    writer.setSelection( writer.createPositionAt( editor.model.document.getRoot(), 'end' ) );
                  }
                )}, 1);
            }
          }
          editor.updateSourceElement();
          $(editor.sourceElement).trigger('change', [true]);
        }
      });
    });
  }

})(jQuery, Drupal, once);
