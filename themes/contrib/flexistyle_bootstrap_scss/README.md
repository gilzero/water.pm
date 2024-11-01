## Table of contents

- Introduction
- Requirements
- Installation
- Configuration
- Live Demo on SimplyTest.me
- Features
- Maintainers


## Introduction

FlexiStyle Bootstrap SCSS is a cutting-edge theme designed for Drupal, offering
a seamless blend of modern design principles and advanced styling capabilities.
Building on the solid foundation of the FlexiStyle Bootstrap base theme,
FlexiStyle Bootstrap SCSS incorporates SCSS (Sass), a powerful CSS preprocessor
that enhances the development process with features like variables, nesting,
and mixins. The theme also utilizes the Gulp compiler, which is instrumental in
compiling all the SCSS files into CSS, streamlining the workflow by automating
this crucial task along with other processes such as asset optimization.

In addition to its rich styling capabilities, FlexiStyle Bootstrap SCSS
functions as a base theme itself, enabling developers to create custom
sub-themes. This flexibility allows for a tailored approach to design while
retaining the powerful features and structure of the base theme.

Fully compatible with Drupal 10, FlexiStyle Bootstrap SCSS ensures that users
benefit from the latest Drupal features and security updates. It offers a broad
range of customization options, from simple design tweaks to complete
overhauls, making it an ideal choice for developing unique, responsive websites
. Whether you're building a corporate site, a personal blog, or an e-commerce
platform, FlexiStyle Bootstrap SCSS provides the tools and flexibility to bring
your vision to life.


## Requirements

- **Drupal 10**: Ensure your Drupal site is running on version 10.
- **Node.js**: Needed for compiling SCSS files.
- **Gulp CLI**: Used to automate the compilation process of SCSS files into CSS.
- **Composer**: For installing the FlexiStyle Bootstrap SCSS theme.
- **Command Line Access**: To run the subtheme creation script and other CLI tools.


## Installation

#### Install Node.js and Gulp CLI
   - Ensure you have Node.js installed. Download it from [Node.js official website](https://nodejs.org/en).
   - Install Gulp CLI globally by running the command: `npm install -g gulp-cli`

#### Download and Install the FlexiStyle Bootstrap SCSS Theme
  - Download and Install Theme as you would normally install a contributed Drupal
  theme.
  - Download the **FlexiStyle Bootstrap SCSS** theme from [Drupal.org](https://www.drupal.org/project/flexistyle_bootstrap_scss).
  - Install with composer `composer require drupal/flexistyle_bootstrap_scss`
  - Place the theme in your Drupal installation's `themes` directory.

#### Navigate to the Theme Directory
   - Navigate to the contrib theme directory
   - Change to the theme directory using: `cd web/themes/contrib/flexistyle_bootstrap_scss`

#### Make the Subtheme Script Executable
   - Run this command to make the script executable: `chmod +x script/subtheme.sh` or `chmod +x ./script/subtheme.sh`

#### Create the Subtheme
   - Execute the subtheme script: `sh script/subtheme.sh` or `./script/subtheme.sh`
   - Follow the prompts to input your subtheme’s machine name and theme name.
   - Navigate to the created custom subtheme directory

#### Compile SCSS to CSS
   - Install the necessary npm packages: `npm install` or `npm i`
   - Run Gulp to compile the SCSS files: `gulp`


## Configuration

 - Log in to your Drupal site’s administrative dashboard.
 - Navigate to **Administration » Appearance**.
 - Locate your subtheme (**Mytheme FlexiStyle Bootstrap SCSS**) in the list of
 - installed themes.
 - Install and set as Default.
 - Click on the Settings link next to your subtheme’s name. This will bring
 - up a page where you can configure various aspects of your theme.


## Live Demo on SimplyTest.me
   - Go to [SimplyTest.me](https://simplytest.me/) in your web browser.
   - On the homepage, you will see an option to select a Drupal version. Choose Drupal 10 from the dropdown menu since your subtheme is designed for Drupal 10.
   - In the Add **Modules/Themes/Distributions** field, type `flexistyle_bootstrap_scss`.
   - As you type, SimplyTest.me will display matching results. Select the **FlexiStyle Bootstrap SCSS** theme from the list.
   - Click on the **Options** tab to adjust your testing environment settings such as **PHP version**, server resources, and more.
   - You can leave the default options as they are or adjust them according to your needs.
   - Click the **Launch Sandbox** button to start the demo environment.
   - It may take a few minutes for SimplyTest.me to prepare your testing environment.
   - Once the sandbox is ready, you will see a link to access your Drupal site. Click on the link to open the Drupal site in a new tab.
   - Log in to your Drupal site using the provided admin credentials (usually prefilled).
   - Navigate to Appearance in the admin toolbar.
   - Find and enable the FlexiStyle Bootstrap SCSS theme.
   - If you have your custom subtheme, you would typically upload it to the SimplyTest.me environment, but that may not be supported directly without additional configuration.


## Features
   - All the features are the same as those of [FlexiStyle Bootstrap](https://www.drupal.org/project/flexistyle_bootstrap#features).


## Maintainers

- Anoop Singh - [anoopsingh92](https://www.drupal.org/u/anoopsingh92)
