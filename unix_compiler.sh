#!/bin/bash
mkdir -p obj
while :
do
    clear
    echo "compiling chidraqul6 (using clan++ & clang with ncurses)"
    echo "========================================="
    #g++ src/*.cpp -o chidraqul6
    clang src/*.c -c
    clang++ src/*.cpp -c
    clang++ *.o -lcurses -o chidraqul6
    mv *.o obj
    echo "========================================="
    echo "finished press any key to compile agian."
    read -n1
done
