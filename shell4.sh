#!/bin/bash

if [ "$#" -ne 2 ]
then
	echo "Usage: $0 <number1> <number2>"
	exit 1
fi

num1="$1"
num2="$2"

sum=$((num1+num2))
echo "Sum: $sum"
difference=$((num1-num2))
echo "Difference: $difference"
product=$((num1*num2))
echo "Product: $product"

if [ "$num2" -eq 0 ]
then
	echo "Division by zero not possible"
	exit 1
fi

quotient=$(bc<<<"scale=2;$num1/$num2")
echo "Quotient: $quotient"
