#!/bin/bash

if [ "$#" -ne 1 ]
then 
	echo "Usage: $0 <directory>"
	exit 1
fi

directory="$1"

if [ ! -d "$directory" ]
then
	echo "Invalid directory"
	exit 1
fi

zip -r "$directory.zip" "$directory"
echo "Directory '$directory' compressed into '$directory.zip' "
