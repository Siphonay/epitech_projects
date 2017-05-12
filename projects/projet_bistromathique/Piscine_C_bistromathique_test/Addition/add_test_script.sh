#!/bin/bash

gcc *.c -I../include -L../lib -lmy -o add_inf_test
echo "Test Add Inf : nombres de mêmes longueur : 42 + 21 ="
./add_inf_test 42 21
echo "Test Add Inf : premier nombre plus long que le deuxième : 424 + 6 ="
./add_inf_test 424 6
echo "Test Add Inf : deuxième nombre plus long que le premier : 4 + 686 ="
./add_inf_test 4 686
echo "Terminé."
rm -r add_inf_test
