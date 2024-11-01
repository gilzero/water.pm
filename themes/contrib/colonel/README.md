# Colonel

## Introduction
Colonel groups all the basic styles (grid, reset, typo, etc ...). But it can not be used alone. Indeed all the variables are declared in its sub-theme "SubColonel".

***
SUB COLONEL
Parent: colonel
***

## Installation
Copy and paste the "subcolonel" folder at the root of the custom themes folder and rename it. Do not forget to change also the name of the files `subcolonel.theme`, `subcolonel.info.yml`, `subcolonel.libraries.yml` and as well the name of the theme inside these files.
In the file `gulpfile.js`, change the proxy with the URL of your local site (in order to prepare browser-sync).

Then:

```
cd /subcolonel_renamed
npm install

/* Compile on the fly the theme for development + launches browser-sync */
npx gulp watch

/* Compile the theme for development mode */
npx gulp sass-dev

/* Compile the theme for production */
npx gulp sass-prod
```

That's it!

## How it works
*Colonel* is a base theme. It contains the basic styles for starting a project (normalize, grid system, typographic styles, etc...). However *Colonel* can not be used alone.

You should use the subtheme called *SubColonel* (which is inside the *Colonel* theme).

*SubColonel* is divided into components that are fully coupled to *Colonel*.
We import *Colonel*'s SCSS file and then we define the variables. It avoids overrides and duplicated code.

Let's see an example in `subcolonel/src/components/pager/styles.scss`:

```
//VARIABLES
$pagerLinkColor: #000;
$pagerLinkHoverColor: #444;
$pagerLinkActiveColor: #FF0000;
$pagerLinkActiveFontWeight: 700;
$pagerIconWidth: 10px;
$pagerIconHeight: 10px;
$pagerIconPreviousMargin: 0 5px 0 0;
$pagerIconNextMargin: 0 0 0 5px;

//IMPORT
@import "../../../../colonel/src/components/pager/styles";

//CUSTOM
...
```

First we initialize a set of variables that are used in the *Colonel* parent theme and we import the *Colonel* theme style file. Then, if needed, we add some additional styles to meet the needs of the project.
Knowing that, it becomes clear that *Colonel* can not be used alone. It contains all the basic styles but it's variables are declared in *SubColonel*.

## Architecture
*Colonel* follows the main principles of the SMACSS guide.

## Grid system
The theme uses a Flexbox grid, inspired by the Bootstrap grid system.

## CSS files
*Colonel* uses SCSS compiled with Gulp that works with Nodejs.

## Coding with synchronised browsers
*Colonel* uses Browsersync which allows to render the site on several devices at the same time. With Gulp and Browsersync, there is no need to reload the page after compiling the SCSS. CSS is automatically injected without reloading the page.
To make it work, in the file `gulpfile.js`, change the proxy with the URL of your local site (in order to prepare browser-sync).
Then run `npx gulp watch`

---
