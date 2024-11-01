## Table of contents

- Introduction
- Requirements
- Installation
- Configuration
- Create subtheme
- Recommended Libraries
- Maintainers


## Introduction

FlexiStyle Bootstrap theme is a base theme for Drupal.
This theme is fully compatible with Drupal 10.
It is a dynamic and modern custom theme designed
specifically for Drupal. Its theme completely overwrites
standard root twig templates. This theme is based on
bootstrap based layout and structure. This theme seamlessly
integrates aesthetics with functionality, offering a
visually striking and user-friendly.

This theme supports all the bootstrap versions. It is a
lightweight theme because we are attaching all the CSS and
JS libraries based on the components and disabling
unnecessary libraries. theme performance, best practices,
and SEO scores are high in a lighthouse.

The theme is fully responsive and mobile-first. Use the
latest version of Fontawesome and Google material libraries
for icons in this theme. All the sections, colors, sizes,
widths, columns and containers are fully based on the
bootstrap.

"Flexi Style Bootstrap" theme settings are manageable, You
can change the header, navbar, footer, Bootstrap version,
and maintenance mode time settings and styles from the theme
appearance. This theme is fully supportable with the
Progressive web application (PWA).


## Requirements

This theme requires Drupal core `>= 9.0`.
This theme does not require any theme and modules outside of Drupal core.


## Installation

Install as you would normally install a contributed Drupal theme.
Install with composer `composer require 'drupal/flexistyle_bootstrap'`
then enable the theme.


## Configuration

Go to the `Administration » Appearance`.
On the same page **FlexiStyle Bootstrap** theme and click on
the install and set as default.


## Create subtheme

1. You can create a subtheme through a shell script.
2. Install the **"FlexiStyle Bootstrap"** theme with the composer
   `composer require 'drupal/flexistyle_bootstrap'` but don't enable it.
3. Go to the theme folder from shell or command
   prompt: `cd themes/contrib/flexistyle_bootstrap`.
4. Run this command from the shell "Make script
   executable": `chmod +x script/subtheme.sh`.
5. Run this command from the shell to launch the
   script: `sh script/subtheme.sh` or `./script/subtheme.sh`.
6. That script will ask the questions for you to create your subtheme.
	1. The `machine name` of your custom theme?
      `[e.g. mytheme_flexistyle_bootstrap]`: **mytheme_flexistyle_bootstrap**.
	2. The `theme name` of your custom theme?
      `[e.g. Mytheme FlexiStyle Bootstrap]`: **Mytheme FlexiStyle Bootstrap**
7. Go to the **administration -> Appearance** and enable
   the `Mytheme FlexiStyle Bootstrap`.


## Recommended Libraries

### Method 1:
1. Go to the theme folder from the shell or command prompt:
    `cd web/themes/contrib/flexistyle_bootstrap`.
2. Run this command from the shell "Make script executable":
   `chmod +x script/library.sh`.
3. Run this command from the shell to launch the script:
   `./script/library.sh`.
4. That script will ask the questions.
   1. Do you want to move your bootstrap library from vendor to
   libraries: [Yes]?.
   2. Do you want to download popper.js libraries: [Yes]?
5. Press enter, within a few seconds Download will be completed.
6. Now you can change your theme settings Bootstrap configuration from
   local to libraries.

### Method 2: Manual
1. Download compiled Bootstrap source files and popper.js with your asset.
2. Click on [Download](https://github.com/twbs/bootstrap/archive/v5.3.3.zip) to latest bootstrap library.
3. Create a **"libraries"** folder if it does not exist in your application
   on root.
4. Now extract the downloaded zip file into the libraries folder on that
   path `web/libraries/bootstrap`.
5. Rename the extracted folder to bootstrap.
6. Click on [Save popperjs](https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js) and save into the `web/libraries/popper.js/dist` folder, if it does not exist create it.
7. Go to the Appearance `/admin/appearance`.
8. From Installed themes Click on **"Settings"** gear icons.
9. From the **Bootstrap settings** tab > Choose **Libraries** from the
   "Bootstrap from" select list.


## Maintainers

- Anoop Singh - [anoopsingh92](https://www.drupal.org/u/anoopsingh92)
