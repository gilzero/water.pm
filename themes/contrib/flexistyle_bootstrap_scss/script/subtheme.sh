#!/bin/bash
# Script to quickly create subtheme.

echo '
+----------------------------------------------------------------------------------+
| With this script you can quickly create a FlexiStyle Bootstrap SCSS Subtheme     |
| In order to use this:                                                            |
| - "FlexiStyle Bootstrap SCSS" theme should be in the contrib folder              |
+----------------------------------------------------------------------------------+
'
echo 'The machine name of your custom theme? [e.g. mytheme_flexistyle_bootstrap_scss]'
read CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS

echo 'The theme name of your custom theme ? [e.g. Mytheme FlexiStyle Bootstrap SCSS]'
read CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS_NAME

if [[ ! -e ../../custom ]]; then
    mkdir ../../custom
fi
cd ../../custom
cp -r ../contrib/flexistyle_bootstrap_scss $CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS
cd $CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS
for file in *flexistyle_bootstrap_scss.*; do mv $file ${file//flexistyle_bootstrap_scss/$CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS}; done
for file in config/*/*flexistyle_bootstrap_scss*.*; do mv $file ${file//flexistyle_bootstrap_scss/$CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS}; done

# Remove subtheme.sh file, we do not need it in customized subtheme.
rm -rf script
rm -rf composer.json

# mv {_,}$CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS.theme
grep -Rl flexistyle_bootstrap_scss .|xargs sed -i -e "s/flexistyle_bootstrap_scss/$CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS/"
sed -i -e "s/FlexiStyle Bootstrap SCSS/$CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS_NAME/" $CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS.info.yml
echo "# Check the themes/custom folder for your new subtheme $CUSTOM_FLEXISTYLE_BOOTSTRAP_SCSS_NAME."