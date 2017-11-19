@echo off
title chidraqul6 g++ compiler [ChillerDragon]
:compile
cls
echo Compiling g++ chidraqul6
echo ========================
g++ -Wall -Wextra src/*.cpp -o chidraqul6
echo ========================
echo finished compile. press any key to compile agian
pause >NUL
goto compile