#!/bin/bash

echo "Enter the URL of the webpage to download (or 'q' to quit): "
read url

if [ "$url" == "q" ]; then
    exit 0
fi

# Check if wget is installed
if ! command -v wget &> /dev/null; then
    echo "wget could not be found. Please install it first."
    exit 1
fi

# Download the webpage
echo "Downloading webpage from $url..."
wget "$url"

if [ $? -eq 0 ]; then
    echo "Webpage downloaded successfully!"
else
    echo "Failed to download the webpage."
fi