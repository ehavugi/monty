#!/bin/bash

#gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
#./monty
rm monty
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
./monty bytecodes/001.m
./monty bytecodes/000.m
./monty bytecodes/03.m
./monty byex
echo "monty bytecodes/04.m"
./monty bytecodes/04.m
echo "./monty bytecodes/06.m"
./monty bytecodes/06.m
echo "./monty bytecodes/061.m"
./monty bytecodes/061.m
