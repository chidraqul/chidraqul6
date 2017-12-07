#!/bin/bash
mkdir -p obj
while :
do
    clear
    echo "compiling chidraqul6 (using clan++ & clang with ncurses)"
    echo "========================================="

    #old unused
    #g++ src/*.cpp -o chidraqul6

    #base
    echo "[BASE]"
    clang src/base/*.c -c

    #client
    echo "[CLIENT]"
    clang src/client/*.c -c
    clang++ src/client/*.cpp -c
    clang++ *.o -lcurses -o chidraqul6
    mv *.o obj

    #base
    echo "[BASE]"
    clang src/base/*.c -c

    #server
    echo "[SERVER]"
    clang++ src/server/*.cpp -c
    clang src/server/*.c -c
    clang *.o -o chidraqul6_srv
    mv *.o obj
    echo "========================================="
    echo "finished press any key to compile agian."
    read -n1
done
