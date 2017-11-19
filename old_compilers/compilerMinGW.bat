@echo off
title chidraqul6 MinGW compiler
echo =====================
echo made by ChillerDragon
echo made for chidraqul6
echo =====================
:error
echo choose between "compile" and "compile_debug"
set inp=compile
set /p inp=""
if %inp%==compile (
	title chidraqul6 MinGW compiler [normal]
	goto compile
) else if %inp%==compile_debug (
	title chidraqul6 MinGW compiler [debug]
	goto compile_debug
) 
goto error

:compile_debug
call :pre_compile
g++ -Wall -Wextra -Werror -o chidraqul6 chidraqul6.cpp
call :compile_clearup
pause >NUL
goto compile_debug

:compile
call :pre_compile
g++ -Wall -Wextra -o chidraqul6 chidraqul6.cpp
call :compile_clearup
pause >NUL
goto compile

:pre_compile
cls
if EXIST src (
echo ==============================
cd src
) else (
echo ERROR: src folder not found
pause >NUL
exit
)
exit /b 0

:compile_clearup
echo ==============================
cd ..
if NOT EXIST src (
echo ERROR: source folder not found
echo %cd%
) else if NOT EXIST src\chidraqul6.exe (
echo ERROR: a build step failed
) else ( 
echo linking and moving
move src\chidraqul6.exe chidraqul6.exe
)
echo -------------------------------------
echo finished. press any key to compile agian.
exit /b 0
