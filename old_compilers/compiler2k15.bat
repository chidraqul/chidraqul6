:: ChillerDragon's c++ compiler helper for VS 15
:: made by ChillerDragon
:: made for chidraqul6.cpp
::
:: INFO:
:: this batch file needs two support file in the visual studio directorys (the support files can be found in "chidraqul6/batch_compiler_helper"):
:: you can manually add them or use the batch configuration file "chidraqul6\batch_compiler_helper\init_vs15_compiler.bat"
:: [1]
:: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\chiller_dev_tool_starter.bat
:: [2]
:: C:\Program Files (x86)\Microsoft Visual Studio 14.0\chiller_compiler_helper.bat

@echo off
cls
echo =========================================
echo ChillerDragon's c++ compiler helper for VS 15
echo designed for chidraqul6
echo =========================================
echo %cd% 
::works check dir but gets broken if batch file is executed by admin
echo %~dp0 
::also can check paths with admin
set /a path_error=0
set /a null_var=0
if EXIST "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\chiller_dev_tool_starter.bat" (
echo chiller_dev_tool_starter.bat found...
) else (
echo WARNING chiller_dev_tool_starter.bat not found 
set /a path_error=1
)
if EXIST "C:\Program Files (x86)\Microsoft Visual Studio 14.0\chiller_compiler_helper.bat" (
echo chiller_compiler_helper.bat found...
) else (
echo WARNING chiller_compiler_help.bat not found 
set /a path_error=1
)

if %path_error% gtr %null_var% goto handle_error

:: =================== MAIN CODE ==================
::start "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\Developer-Eingabeaufforderung für VS2015"
cd "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools"
chiller_dev_tool_starter.bat
::===============================================

:handle_error
	echo =========================================
	echo ERROR couldn't start chidraqul6 compiler
	echo Do you want to try a fix with the init_vs15_compiler.bat installer
	echo yes/no
	set /p inp=""
	if %inp%==yes (
	goto fix_with_installer
	) else if %inp%==YES (
	goto fix_with_installer
	) else if %inp%==Yes (
	goto fix_with_installer
	) else if %inp%==y (
	goto fix_with_installer
	) else if %inp%==Y (
	goto fix_with_installer
	) else (exit)
exit /b 0

:fix_with_installer
echo init fixxing -- %~dp0
if EXIST "%~dp0\batch_compiler_helper\init_vs15_compiler.bat" (
cd "%~dp0\batch_compiler_helper"
init_vs15_compiler.bat
) else (
echo ERROR "%~dp0\batch_compiler_helper\init_vs15_compiler.bat" not found!
pause >NUL
)
exit /b 0
