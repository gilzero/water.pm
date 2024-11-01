// plugins/CustomTableClassPlugin.js

import Plugin from '@ckeditor/ckeditor5-core/src/plugin';

/**
 * Plugin to add a custom class to table elements in CKEditor 5.
 */
class CustomTableClassPlugin extends Plugin {
  init() {
    const editor = this.editor;

    // Add the downcast conversion for the 'table' element.
    editor.conversion.for('downcast').add(dispatcher =>
      dispatcher.on('insert:table', (evt, data, conversionApi) => {
        const modelTable = data.item;
        const viewFigure = conversionApi.mapper.toViewElement(modelTable);

        if (viewFigure && viewFigure.name === 'figure') {
          conversionApi.writer.addClass('table-responsive', viewFigure);
          // Find the table within the figure's children.
          const viewTable = this._findTableViewElement(viewFigure);

          if (viewTable) {
            conversionApi.writer.addClass('table', viewTable);
          } else {
            // Use the editor's logging utility instead of `console.warn`.
            editor.plugins.get('Logging').warn('CustomTableClassPlugin: No table element found within the figure element.');
          }
        }
      }, { priority: 'low' }) // We use 'low' to ensure the table has been inserted into the view.
    );
  }

  /**
   * Finds the view table element within a view figure element.
   *
   * @private
   * @param {module:engine/view/element~Element} viewFigure
   * @returns {module:engine/view/element~Element|null}
   */
  _findTableViewElement(viewFigure) {
    for (const child of viewFigure.getChildren()) {
      if (child.name === 'table') {
        return child;
      }
    }
    return null;
  }
}

export default CustomTableClassPlugin;
