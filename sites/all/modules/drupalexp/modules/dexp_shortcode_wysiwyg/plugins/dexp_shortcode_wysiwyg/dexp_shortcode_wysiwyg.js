(function ($) {
  /**
   * Wysiwyg plugin button implementation for shortcode plugin.
   */
  Drupal.wysiwyg.plugins.dexp_shortcode_wysiwyg = {
    /**
     * Return whether the passed node belongs to this plugin.
     *
     * @param node
     *   The currently focused DOM element in the editor content.
     */
    isNode: function (node) {
      return ($(node).is('img.dexp_shortcode_wysiwyg-shortcode_wysiwyg'));
    },

    /**
     * Execute the button.
     *
     * @param data
     *   An object containing data about the current selection:
     *   - format: 'html' when the passed data is HTML content, 'text' when the
     *     passed data is plain-text content.
     *   - node: When 'format' is 'html', the focused DOM element in the editor.
     *   - content: The textual representation of the focused/selected editor
     *     content.
     * @param settings
     *   The plugin settings, as provided in the plugin's PHP include file.
     * @param instanceId
     *   The ID of the current editor instance.
     */
    invoke: function (data, settings, instanceId) {
      /*
       if (data.format == 'html') {
       var content = this._getPlaceholder(settings);
       }
       else {
       var content = '<!--shortcode_wysiwyg-->';
       }
       */
      Drupal.wysiwyg.plugins.dexp_shortcode_wysiwyg.insert_form(data, settings, instanceId);
    },

    insert_form: function (data, settings, instanceId) {
      var form_id = Drupal.settings.dexp_shortcode_wysiwyg.current_form;
      // Location, where to fetch the dialog.
      var aurl = Drupal.settings.basePath + 'index.php?q=dexp_shortcode_wysiwyg/' + Drupal.wysiwyg.instances[instanceId].format + '/' + form_id;
      var tmpdiv = $('<div id="dexp-shortcode-wysiwyg-form-wrapper" class="element-invisible"></div>');
      var dialogdiv = $('<div id="shortcode-insert-dialog"></div>');
      // We need to load the whole document so that scripts get executed
      tmpdiv.load(aurl, function () {
        var shortcodeForm = $(this).find('#dexp-shortcode-wysiwyg-form');
        dialogdiv.html(shortcodeForm);
        var dialogClose = function () {
          try {
            dialogdiv.dialog('destroy').remove();
          } catch (e) {}
        }
        var btns = {};
        btns[Drupal.t('Insert shortcode')] = function () {

          var shortcode = dialogdiv.contents().find('#edit-shortcode option:selected').val();
          var editor_id = instanceId;

          var options = [],
            text = '';
          dialogdiv.contents().find('.form-item').not(':hidden').find('input,select,textarea')
            .not('#edit-shortcode,[type="hidden"]')
            .each(function () {
              var $this = $(this),
                name = $this.attr('name'),
                val = $this.val(),
                params;

              // This allows a form field for text and not assuming the user selected the
              // text that will need to be wrapped
              if (name == 'content' && val.length) {
                text = $this.val(); return;
              }

              // Encode textarea content to avoid breakage and obscure dangerous markup.
              // Any shortcodes that use textarea form elements will need to urldecode the
              // results.
              else if ($this.is('textarea')) {
                val = encodeURIComponent($this.val());
              }

              // For radio buttons and checkboxes, only get the value if selected
              else if (val.length && (($this.attr('type') == 'radio' || $this.attr('type') == 'checkbox') && $this.is(':checked')) || ($this.attr('type') != 'radio' && $this.attr('type') != 'checkbox')) {
                val = $this.val();
              }

              // Strip the shortcode prefix from the attribute.
              name = name.replace(shortcode + '-', '');

              // Offer an opportunity for any other modules to alter the value
              // before it's put into the shortcode
              params = {
                element: this,
                shortcode: shortcode,
                name: name,
                value: val
              };
              $(document).trigger('shortcodeWYSIWYG.optionValueAlter', params);

              // Save the option for use in the shortcode that is rendered to
              // the WYSIWYG
              val = params.value;
              if (val.length) {
                options.push(name + '="' + val + '"');
              }

            });
          if (data.content != '' && text == '')
            text = data.content
            // Check if we have a hidden field with custom code.
          //if ($('#edit-custom').length) {
          //  shortcode = $('#edit-custom').val();
          //} else {
            shortcode = '[' + shortcode + (options.length ? ' ' + options.join(' ') : '') + ']' + text + '[/' + shortcode + ']';
          //}
          Drupal.wysiwyg.plugins.dexp_shortcode_wysiwyg.insertIntoEditor(shortcode, editor_id);
          //dialogClose();
        };

        btns[Drupal.t('Close')] = function () {
          dialogClose();
        };

        dialogdiv.dialog({
          modal: false,
          autoOpen: false,
          closeOnEscape: true,
          resizable: false,
          draggable: true,
          autoresize: true,
          namespace: 'jquery_ui_dialog_default_ns',
          dialogClass: 'jquery_ui_dialog-dialog',
          title: Drupal.t('Insert Shortcode'),
          buttons: btns,
          width: 700,
          close: dialogClose
        });
        dialogdiv.dialog("open");
        // fixme: Add context there!
        Drupal.attachBehaviors();
      });
    },

    insertIntoEditor: function (shortcode, editor_id) {
      Drupal.wysiwyg.instances[editor_id].insert(shortcode);
    },

    /**
     * Prepare all plain-text contents of this plugin with HTML representations.
     *
     * Optional; only required for "inline macro tag-processing" plugins.
     *
     * @param content
     *   The plain-text contents of a textarea.
     * @param settings
     *   The plugin settings, as provided in the plugin's PHP include file.
     * @param instanceId
     *   The ID of the current editor instance.
     */
    attach: function (content, settings, instanceId) {
      $('head').append('<style type="text/css">.cke_button__dexp_shortcode_wysiwyg_label{display: inline;}</style>');
      content = content.replace(/<!--dexp_shortcode_wysiwyg-->/g, this._getPlaceholder(settings));
      return content;
    },

    /**
     * Process all HTML placeholders of this plugin with plain-text contents.
     *
     * Optional; only required for "inline macro tag-processing" plugins.
     *
     * @param content
     *   The HTML content string of the editor.
     * @param settings
     *   The plugin settings, as provided in the plugin's PHP include file.
     * @param instanceId
     *   The ID of the current editor instance.
     */
    detach: function (content, settings, instanceId) {
      var $content = $('<div>' + content + '</div>');
      $.each($('img.dexp_shortcode_wysiwyg-shortcode_wysiwyg', $content), function (i, elem) {
        //...
      });
      return $content.html();
    },

    /**
     * Helper function to return a HTML placeholder.
     *
     * The 'drupal-content' CSS class is required for HTML elements in the editor
     * content that shall not trigger any editor's native buttons (such as the
     * image button for this example placeholder markup).
     */
    _getPlaceholder: function (settings) {
      return '<img src="' + settings.path + '/images/spacer.gif" alt="&lt;--shortcode_wysiwyg-&gt;" title="&lt;--shortcode_wysiwyg--&gt;" class="shortcode_wysiwyg-shortcode_wysiwyg drupal-content" />';
    }
  };
})(jQuery);
