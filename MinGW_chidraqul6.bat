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
::g++ -Wall -Wextra src/*.cpp -o chidraqul6
gcc src/*.c -c
g++ src/*.cpp -c
::g++ -I %boost_path% src/*.cpp -c
g++ *.o -o chidraqul6
move *.o objs >NUL
echo ============================
echo finished compile. press any key to compile agian
pause >NUL
goto compile