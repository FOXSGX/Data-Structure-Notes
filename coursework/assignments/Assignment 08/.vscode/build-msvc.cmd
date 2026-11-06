@echo off
setlocal

call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 >nul
if errorlevel 1 exit /b %errorlevel%

cl.exe /nologo /EHsc /std:c++17 /W4 /Zi /Od "%~1" /link /DEBUG
exit /b %errorlevel%
