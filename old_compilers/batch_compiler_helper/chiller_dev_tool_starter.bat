::ChillerDragon's Visual Studio Compiler Helper Dev tool starter helper
::made for chidraqul6 cpp compiling
:: WARNING! THIS IS ONLY AN SUPPORT FILE AND HAS TO BE LOCATED IN 
:: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2015\Visual Studio Tools\chiller_dev_tool_starter.bat
echo Execute [chiller_compiler_helper.bat] to go on compiling chidraqul6
for /f "tokens=2 delims=:." %%x in ('chcp') do set cp=%%x
chcp 1252>nul
"Developer-Eingabeaufforderung für VS2015.lnk"
pause
chcp %cp%>nul