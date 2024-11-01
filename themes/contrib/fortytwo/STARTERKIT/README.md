# BUILDING A THEME WITH FORTY TWO

The FortyTwo theme is designed to be extended by a sub-theme. You shouldn't modify the
any of the CSS or PHP files in the fortytwo/ folder; instead create a
sub-theme which is located out side of the root fortytwo/ folder.

We tried to make the base theme as clean and simple as possible. It has some
styling for basic input fields and buttons.

## FortyTwo base theme location

FortyTwo follows the specifications of theme locations as described on the page
https://www.drupal.org/docs/8/theming-drupal-8/drupal-8-theme-folder-structure.

So it is important to install the FortyTwo base theme in the folder `/themes/contrib/fortytwo`

## Automated setup of base theme with composer

To create a subtheme you can run the command `composer subtheme <themename>`
from the fortytwo folder. This will create the subtheme in the themes/custom folder.

The `<themename>` argument is optional. When omitted the subtheme will be called `fortytwo_subtheme`.

## Manual set up
### Setup the location for your new sub-theme.

Copy the STARTERKIT folder out of the fortytwo/ folder and rename it to be your new sub-theme.
**IMPORTANT:** The name of your sub-theme must start with an *alphabetic character* and can only
contain *lowercase letters, numbers and underscores*.

For example, copy the `/themes/contrib/fortytwo/STARTERKIT` folder and rename it as `/themes/custom/foo`.

Why? Each theme should reside in its own folder. To make it easier to upgrade FortyTwo, sub-themes should
reside in a folder separate from the base theme.

### Setup the basic information for your sub-theme.

  In your new sub-theme folder, rename the `STARTERKIT.info.yml.txt` file to include
  the name of your new sub-theme and remove the ".txt" extension. Then edit
  the .info.yml file by editing the name and description field.

  For example, rename the `foo/STARTERKIT.info.yml` file to `foo/foo.info.yml`. Edit the
  foo.info.yml file and change `"name = Forty Two Sub-theme Starter Kit"`. Do the same
  with the description property.
  Make sure you also rename the libraries section `STARTERKIT/main` to `foo/main` in
  the .info.yml file.

  Also rename the STARTERKIT.libraries.yml and the STARTERKIT.theme files. For example rename
  the `foo/STARTERKIT.libraries.yml` file to `foo/foo.libraries.yml` and the `foo/STARTERKIT.theme`
  file to `foo/foo.theme`. Replace any occurences of STARTERKIT in any of these files.

  The main javascript file needs to be renamed in order to work. A reference to
  that file can be found in the subtheme's `.info.yml` file, and the file itself is
  located in the folder `static/js`. Rename the file to whatever you want and
  change the reference to that file in the `.info.yml` file. Best practice is to
  name it like the theme's machine name. Also rename the behavior in the
  `STARTERKIT.js` file to reflect your theme's name.

  Do not forget to rename the file in the config folder as well.

## Configuration of your subtheme.

  A lot of settings can be done on the sub-theme appearance page. CSS/SASS specific
  settings can be set in the config folder `/static/sass/config/**.scss`.

## Flexbox

  This theme is dependent on flexbox. There are several classes defined that you can
  use to create flexbox behaviour. You can take a look at `/static/sass/base/_layout.scss`
  for these classes.

## Responsive

  By default Forty Two theme has 5 separate layouts;
  xl, lg, md, sm and xs. The media queries are defined in
  the `/static/sass/config/_media-grid.scss` file.

  You can use different classes for settings widths on elements. For instance `xl-col-12 md-col-fluid-12` for
  a 12 column width element on xl and a 100% width element on md breakpoint.

  If you want to know what classes you can use, you can take a look at the
  loops in, for instance, `/static/sass/grid/_xl.scss`. Those loops are equal for
  all breakpoints.

## Javascript

  There are some libraries and polyfills provided that can be turned on/off.

## Webpack

  Webpack is used in the STARTERKIT to compile scss and javascipt.
  There are 2 some commands available:
  * `npm run build`: Build the css/js files in production mode
  * `npm run build:dev`: Build the css/js files in dev mode
  * `npm run start`: Build and watch the css/js files in production mode
  * `npm run start:dev`: Build and watch the css/js files in dev mode

  Webpack uses https://stylelint.io/ to check for errors and warnings in your scss files.
  You can chancge the config in the .stylelintrc.json file.
