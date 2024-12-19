#!/usr/bin/env bash

gcc -Wall -Wextra -Werror -pedantic main.c substring.c
./a.out barfoothefoobarman foo bar
./a.out wordgoodgoodgoodbestword word good best word
./a.out wordgoodgoodgoodbestword word good best good
