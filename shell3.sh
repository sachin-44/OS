#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "Usage:$0 <file name>"
	exit 1
fi

filename="$1"

if [ ! -e "$filename" ] 
then
	echo "File not found!"
	exit 1
fi

echo "Contents of the file:"
cat "$filename"
