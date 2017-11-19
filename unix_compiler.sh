#!/bin/bash
while :
do
    clear
    echo "compiling chidraqul6 (using clan++ with ncurses)"
    echo "========================================="
    #g++ src/*.cpp -o chidraqul6
    clang++ src/*.cpp -c
    clang++ *.o -lcurses -o chidraqul6
    mv *.o obj
    echo "========================================="
    echo "finished press any key to compile agian."
    read -n1
done
