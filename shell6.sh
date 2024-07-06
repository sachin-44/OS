#!/bin/bash

function fibonacci()
{
	num=$1
	limit=$((num-2))
	a=0
	b=1
	
	echo "Fibonacci series: "
	echo -n "$a, $b"
	for((i=0;i<$limit;i++))
	do
		
		c=$((a+b))
		echo -n ", $c"
		a=$b
		b=$c
		
	done
	echo ""
}

echo "Limit? "
read n
fibonacci $n
