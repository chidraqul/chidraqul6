:: ==== chidraqul6 ======== by ChillerDragon ===========
::chidraqul6 compiler helper installer and configurator.
::Made by ChillerDragon all rights (c) copyright reserved
::------------------------------------------------------------
::How to use?
::you need Visual Studio 2014 and 2015 to compile chidraqul6.cpp with this script
::then execute this batch file with admin rights
::follow the steps given by the batch file
::then the helper batch files should be configurated
::now u can use "ChillerDragon's c++ compiler helper for VS 15"
::which should be in the chidraqul6/compiler2k15.bat directory



@echo off
title chidraqul6 compiler helper installer [ChillerDragon]
call :print_header
call :check_admin
call :check_vs_paths
echo ------------------------------
call :set_src_dir
call :create_compiler_helper
call :create_tool_starter
echo Finished creating compiler helpers...
pause >NUL
exit 





:check_vs_paths
if EXIST "C:\Program Files (x86)\Microsoft Visual Studio 14.0" (
echo VS 14.0 directory found...
) else (
echo ERROR VS 14.0 directory not found!
pause >NUL
exit
)
if EXIST "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\" (
echo VS 15 tools directory found...
) else (
echo ERROR VS 15 tools directory not found!
pause >NUL
exit
)
exit /b 0

:set_src_dir
:dir1
echo please enter the path to the directory 
echo where your chidraqul6.cpp source is located
echo example "C:\Users\Chiller\Desktop\git\chidraqul6\src"
set /p chidraqul6_src_dir="Path: "
if EXIST %chidraqul6_src_dir% (
	cls
	call :print_header
	goto dir2
) else (
	echo [ERROR] invalid directory. Press any key to try agian.
	pause >NUL
	cls
	call :print_header
	goto dir1
)
:dir2
echo please enter the path to the directory 
echo where your chidraqul6.exe should be moved after compile
echo example "C:\Users\Chiller\Desktop\git\chidraqul6"
set /p chidraqul6_exe_dir="Path: "
if EXIST %chidraqul6_exe_dir% (
	goto dir_end
) else (
	echo [ERROR] invalid directory. Press any key to try agian.
	pause >NUL
	cls
	call :print_header
	goto dir2
)
:dir_end
exit /b 0

:print_header
cls
echo ==============================
echo    ChillerDragon
echo               chidraqul6
echo ------------------------------
echo BATCH compiler helper supporter
echo ==============================
exit /b 0

:create_compiler_helper
(
echo ::ChillerDragon's compiler helper for chidraqul6
echo ::WARNING! THIS BATCH FILE IS ONLY A SUPPORT FILE
echo :: THIS FILE HAS TO BE LOCATED IN THE VISUAL STUDIO DIRECTORY
echo :: C:\Program Files ^(x86^)\Microsoft Visual Studio 14.0\chiller_compiler_helper.bat
echo @echo off
echo color 7c
echo title chidraqul6 compiler [ChillerDragon]
echo cd %chidraqul6_src_dir%
echo :compile
echo cls
echo echo =====================
echo cl /EHsc chidraqul6.cpp
echo echo deleting obj file
echo del chidraqul6.obj
echo echo moving exe out of src folder
echo move %chidraqul6_src_dir%\chidraqul6.exe %chidraqul6_exe_dir%\chidraqul6.exe
echo echo =====================
echo echo press any key to compile agian
echo pause ^>NUL
echo goto compile
) >  "C:\Program Files (x86)\Microsoft Visual Studio 14.0\chiller_compiler_helper.bat"
exit /b 0

:create_tool_starter
(
echo ::ChillerDragon's Visual Studio Compiler Helper Dev tool starter helper
echo ::made for chidraqul6 cpp compiling
echo :: WARNING! THIS IS ONLY AN SUPPORT FILE AND HAS TO BE LOCATED IN 
echo :: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\chiller_dev_tool_starter.bat
echo echo Execute [chiller_compiler_helper.bat] to go on compiling chidraqul6
echo for /f "tokens=2 delims=:." %%%%x in ^('chcp'^) do set cp=%%%%x
echo chcp 1252^>nul
echo "Developer-Eingabeaufforderung für VS2015.lnk"
echo pause
echo chcp %%cp%%^>nul					
) > "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\chiller_dev_tool_starter.bat"
exit /b 0

:check_admin
	net session >nul 2>&1
	if %errorLevel% == 0 (
       		echo Admin rights found...
    	) else (
      		echo error... admin rights needed.
		pause >NUL
		exit
    	)	