@echo off
title chidraqul6 g++ compiler (boost) [ChillerDragon]
if not exist "objs\" mkdir objs\
:compile
cls
echo Compiling g++ chidraqul6
echo ============================
::g++ -Wall -Wextra src/*.cpp -o chidraqul6
gcc src/*.c -c
::g++ src/*.cpp -c
g++ -I C:\Boost\boost_1_65_1 src/*.cpp -c
g++ *.o -o chidraqul6
echo ========= clean up =========
move *.o objs
echo ============================
echo finished compile. press any key to compile agian
pause >NUL
goto compile