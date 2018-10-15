#!/bin/bash
set -e
mkdir -p obj
while :
do
    clear
    echo "compiling chidraqul6 (using clang++ & clang with ncurses)"
    echo "========================================="

    #old unused
    #g++ src/*.cpp -o chidraqul6

    #base
    echo "[BASE]"
    clang src/base/*.c -c
    clang++ src/base/*.cpp -c -std=c++11

    #client
    echo "[CLIENT]"
    clang src/client/*.c -c
    clang++ src/client/*.cpp -c -std=c++11
    clang++ *.o -lcurses -o chidraqul6
    mv *.o obj

    #test client
    #echo "[TEST-CLIENT]"
    #clang `find src/client -name "*.c" -not -name "networking*"` -c
    #clang++ `find src/client -name "*.cpp" -not -name "networking*"` -c -std=c++11
    #clang src/base/*.c -c
    #clang++ src/base/*.cpp -c -std=c++11
    #clang++ src/client/*.cpp -c -std=c++11
    #clang src/client/test/*.c
    #clang++ *.o -lcurses -o chidraqul6_test
    #mv *.o obj

    #test client (external)
    echo "[TEST-CLIENT]"
    clang src/base/*.c -c
    clang++ src/base/*.cpp -c -std=c++11
    clang++ src/test_client/*.cpp -c -std=c++11
    clang++ *.o -lcurses -o chidraqul6_test
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

    #test server
    echo "[TEST-SERVER]"
    clang src/base/*.c -c
    clang src/server/test/*.c src/server/server.c -c
    clang *.o -o chidraqul6_test_srv
    mv *.o obj
    echo "========================================="
    [[ $1 != "--no-repeate" ]] || break
    echo "finished press any key to compile agian."
    read -n1
done
