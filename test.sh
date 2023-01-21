#!/bin/bash

#gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
#./monty
rm monty
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
./monty bytecodes/001.m
./monty bytecodes/000.m
./monty bytecodes/03.m
./monty byex
