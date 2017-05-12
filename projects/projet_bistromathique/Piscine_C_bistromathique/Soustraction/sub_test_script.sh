#!/bin/bash

gcc *.c -I../include -L../lib -lmy -o sub_inf_test
echo "Test Sub Inf : nombres de mêmes longueur avec le nombre 1 plus grand que le nombre 2 : 42 - 21 ="
./sub_inf_test 42 21
echo "Test Sub Inf : nombres de mêmes longueur avec le nombre 2 plus grand que le nombre 1 : 21 - 42 ="
./sub_inf_test 21 42
echo "Test Sub Inf : premier nombre plus long que le deuxième : 424 - 6"
./sub_inf_test 424 6
echo "Test Sub Inf : deuxième nombre plus long que le premier : 4 - 686"
./sub_inf_test 4 686
echo "Terminé."
rm -r sub_inf_test
