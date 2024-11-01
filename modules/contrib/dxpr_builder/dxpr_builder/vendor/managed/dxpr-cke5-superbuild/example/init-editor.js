const editor = CKEDITOR.ClassicEditor.create(document.querySelector("#editor"), {
  toolbar: {
      items: [
        'bold',
        'italic',
        'underline',
        'strikethrough',
        'superscript',
        'subscript',
        'removeFormat',
        '|',
        'fontColor',
        '|',
        'heading',
        'style',
        'fontSize',
        '|',
        'alignment:left',
        'alignment:center',
        'alignment:right',
        'alignment:justify',
        'bulletedList',
        'numberedList',
        'outdent',
        'indent',
        'blockQuote',
        '|',
        'link',
        '|',
        'insertImage',
        'horizontalLine',
        'specialCharacters',
        'insertTable',
        '|',
        'sourceEditing',
        '|',
        'showBlocks',
        '|',
        'undo',
        'redo',
      ]
  },
  style: {
      definitions: [
        {
          name: 'Article category',
          element: 'h3',
          classes: [ 'category' ]
        },
        {
          name: 'Info box',
          element: 'p',
          classes: [ 'info-box' ]
        },
      ]
  },
  image: {
      styles: [
          'alignCenter',
          'alignLeft',
          'alignRight'
      ],
      resizeOptions: [
          {
              name: 'resizeImage:original',
              label: 'Original',
              value: null
          },
          {
              name: 'resizeImage:50',
              label: '50%',
              value: '50'
          },
          {
              name: 'resizeImage:75',
              label: '75%',
              value: '75'
          }
      ],
      toolbar: [
          'imageTextAlternative', 'toggleImageCaption', '|',
          'imageStyle:inline', 'imageStyle:wrapText', 'imageStyle:breakText', 'imageStyle:side', '|',
          'resizeImage'
      ],
      insert: {
          integrations: [
              'insertImageViaUrl'
          ]
      }
  },
  table: {
      contentToolbar: [
          'tableColumn',
          'tableRow',
          'mergeTableCells',
          'tableProperties',
          'tableCellProperties',
          'toggleTableCaption'
      ]
  },
});