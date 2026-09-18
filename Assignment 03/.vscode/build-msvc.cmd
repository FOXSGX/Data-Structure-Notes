@echo off
setlocal

call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 >nul
if errorlevel 1 exit /b %errorlevel%

if not exist "%~2" mkdir "%~2"

cl.exe /nologo /EHsc /std:c++17 /W4 /Zi /Od ^
  /Fo"%~2\%~n1.obj" ^
  /Fd"%~2\%~n1-compiler.pdb" ^
  /Fe"%~2\%~n1.exe" ^
  "%~1" ^
  /link /DEBUG ^
  /PDB:"%~2\%~n1.pdb" ^
  /ILK:"%~2\%~n1.ilk"

exit /b %errorlevel%
