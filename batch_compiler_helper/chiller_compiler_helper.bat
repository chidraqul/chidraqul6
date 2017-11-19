::ChillerDragon's compiler helper for chidraqul6
::WARNING! THIS BATCH FILE IS ONLY A SUPPORT FILE
:: THIS FILE HAS TO BE LOCATED IN THE VISUAL STUDIO DIRECTORY
:: C:\Program Files (x86)\Microsoft Visual Studio 14.0\chiller_compiler_helper.bat
@echo off
color 7c
title chidraqul6 compiler [ChillerDragon]
cd C:\Users\Chiller\Desktop\git\chidraqul6\src
:compile
cls
echo =====================
cl /EHsc chidraqul6.cpp
echo deleting obj file
del chidraqul6.obj
echo moving exe out of src folder
move C:\Users\Chiller\Desktop\git\chidraqul6\src\chidraqul6.exe C:\Users\Chiller\Desktop\git\chidraqul6\chidraqul6.exe
echo =====================
echo press any key to compile agian
pause >NUL
goto compile