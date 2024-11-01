#!/bin/bash
# Script to quickly download Bootstrap and popper.js libraries.

# Script for move bootstrap library from vender to libraries folder.
echo 'Do you want to move your bootstrap library from vendor to libraries: [Yes]?'
read BOOTSTRAP_LIBRARIES

if [[ ! -e ../../../../libraries/bootstrap ]]; then
    mkdir ../../../libraries
    mkdir ../../../libraries/bootstrap
fi
cp -r ../../../../vendor/twbs/bootstrap/dist ../../../../web/libraries/bootstrap

echo "# bootstrap libraries files are moved successfully from the vender to the libraries on that path 'web/libraries/bootstrap'."

# Script for move bootstrap library from vender to libraries folder.
echo 'Do you want to download popper.js libraries: [Yes]?'

read POPPER_JS

cdn_urls=(
    "https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js"
    "https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js.map"
)
download_folder="../../../libraries/popper.js/dist"

if [ ! -d "$download_folder" ]; then
    mkdir ../../../libraries/popper.js
    mkdir -p "$download_folder" || { echo "Error creating download folder."; exit 1; }
fi

# Check if curl is available
if ! command -v curl &> /dev/null; then
    echo "Error: curl command not found. Please install curl."
    exit 1
fi

# Loop through the CDN URLs and download each file
for url in "${cdn_urls[@]}"; do
    filename=$(basename "$url")
    echo "Downloading $filename..."
    curl -o "$download_folder/$filename" "$url" || { echo "Error downloading $filename."; continue; }
done

echo "# Download completed. Please check the popper.js library on that path 'web/libraries/popper.js'."
