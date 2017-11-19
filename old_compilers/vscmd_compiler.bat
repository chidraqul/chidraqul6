@echo off
title chidraqul6 compiler [ChillerDragon]
color 7c
cls
echo =====================
echo ChillerDragon
echo =====================
echo Warning this is an HARDCODET tool
echo if it isnt running you have to hardcode the PATH
echo WARNING this tool is developed for razer blade pro
echo and not made for cross platform compile
echo =====================
pause
cls
echo =====================
echo ChillerDragon
echo =====================
echo This tool has to be run with the Visual Studio commandline
echo if it drops an "cl" error u failed to run vs commandline
echo =====================
pause 
cls
cd C:\Users\Chill\Desktop\git\chidraqul6\src
echo %cd% 
pause
:compile
cls
echo =====================
cl /EHsc chidraqul6.cpp
echo deleting obj file
del chidraqul6.obj
echo moving exe out of src folder
move C:\Users\Chill\Desktop\git\chidraqul6\src\chidraqul6.exe C:\Users\Chill\Desktop\git\chidraqul6\chidraqul6.exe
echo =====================
echo press any key to compile agian
pause >NUL
goto compile