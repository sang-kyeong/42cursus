#!/bin/bash


COLOR_RED='\033]1;31m'


# ex00
printf "${COLOR_RED}make -C ./ex00\n"
make -C ./ex00

printf "\nNo argument\n"
./ex00/megaphone

printf "\n< Hello \"My name\" is sangkkim\n"
./ex00/megaphone Hello "My name" is sangkkim

printf "\n<  Damnit \" ! \" \"Sorry students, I thought this thing was off.\"\n"
./ex00/megaphone  Damnit " ! " "Sorry students, I thought this thing was off."

# ex01


# ex02
