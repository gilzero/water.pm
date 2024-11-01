#!/bin/bash
# Script to quickly create sub-theme.

echo '
+-----------------------------------------------------------------------------+
| With this script you can quickly create a FlexiStyle Bootstrap Subtheme     |
| In order to use this:                                                       |
| - "FlexiStyle Bootstrap" theme should be in the contrib folder              |
+-----------------------------------------------------------------------------+
'
echo 'The machine name of your custom theme? [e.g. mytheme_flexistyle_bootstrap]'
read CUSTOM_FLEXISTYLE_BOOTSTRAP

echo 'The theme name of your custom theme? [e.g. Mytheme FlexiStyle Bootstrap]'
read CUSTOM_FLEXISTYLE_BOOTSTRAP_NAME

if [[ ! -e ../../custom ]]; then
    mkdir ../../custom
fi
cp -r subtheme ../../custom/$CUSTOM_FLEXISTYLE_BOOTSTRAP
cd ../../custom/$CUSTOM_FLEXISTYLE_BOOTSTRAP

for file in *flexistyle_bootstrap_subtheme.*; do mv $file ${file//flexistyle_bootstrap_subtheme/$CUSTOM_FLEXISTYLE_BOOTSTRAP}; done
for file in config/*/*flexistyle_bootstrap_subtheme*.*; do mv $file ${file//flexistyle_bootstrap_subtheme/$CUSTOM_FLEXISTYLE_BOOTSTRAP}; done

mv {_,}$CUSTOM_FLEXISTYLE_BOOTSTRAP.theme
if [[ "$OSTYPE" == "darwin"* ]]; then
  grep -Rl flexistyle_bootstrap_subtheme .|xargs sed -i '' -e "s/flexistyle_bootstrap_subtheme/$CUSTOM_FLEXISTYLE_BOOTSTRAP/"
else
  grep -Rl flexistyle_bootstrap_subtheme .|xargs sed -i -e "s/flexistyle_bootstrap_subtheme/$CUSTOM_FLEXISTYLE_BOOTSTRAP/"
fi
sed -i -e "s/FlexiStyle Bootstrap Subtheme/$CUSTOM_FLEXISTYLE_BOOTSTRAP_NAME/" $CUSTOM_FLEXISTYLE_BOOTSTRAP.info.yml
echo "# Check the themes/custom folder for your new subtheme."
