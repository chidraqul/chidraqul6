@echo off
title chidraqul6 g++ compiler [ChillerDragon]
::if not exist "boost_path.txt" echo add/path/to/boost/lib/here > boost_path.txt
::set /p boost_path=<boost_path.txt
if not exist "objs\" mkdir objs\
:compile
cls
::echo Compiling g++ chidraqul6 (boost: %boost_path%)
echo Compiling g++ chidraqul6
echo ============================

:: unused old stuff
::g++ -Wall -Wextra src/*.cpp -o chidraqul6
::g++ -I %boost_path% src/*.cpp -c
::g++ -Wall -Wextra src/server/*.cpp -o chidraqul6_srv -lws2_32


:: base
echo [BASE]
gcc src/base/*.c -c

:: client
echo [CLIENT]
g++ src/client/*.cpp -c
g++ *.o -o chidraqul6 -lws2_32
move *.o objs >NUL

:: base
echo [BASE]
gcc src/base/*.c -c

:: server
echo [SERVER]
gcc src/server/*.c -c
g++ src/server/*.cpp -c
g++ *.o -o chidraqul6_srv -lws2_32
move *.o objs >NUL

echo ============================
echo finished compile. press any key to compile agian
pause >NUL
goto compile