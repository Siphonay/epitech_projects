#!/bin/bash

if [[ $# -ne 3 ]]
then
    echo "program x y density"
    exit 1
fi

CNT_I=0
DENSITY=$(($2 * 2))

echo $2

while [[ $CNT_I -lt $2 ]]
do
    CNT_J=0
    while [[ $CNT_J -lt $1 ]]
    do
	RAND_VAR=`shuf -i 0-$DENSITY -n 1`
	if [[ $RAND_VAR -lt $3 ]]
	then
	    echo -n "o"
	else
	    echo -n "."
	fi
	((CNT_J++))
    done
    printf "\n"
    ((CNT_I++))
done

exit 0
