# !/bin/bash

printf "Enter a number: "
read num

temp=$num
sum=0

while [ $temp -gt 0 ]
do
	d=$(( $temp % 10 )) 
	temp=$(( $temp / 10 ))

	sum=$(( $sum + $d )) 
done

echo "sum of digits of $num is: $sum"

