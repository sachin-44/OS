#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "Usage:$0 <directory>"
	exit 1
fi

directory="$1"

if [ ! -d "$directory" ]
then
	echo "Not a directory"
	exit 1
fi

find "$directory" -type f
