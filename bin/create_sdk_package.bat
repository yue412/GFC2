:: 先编译源代码，再收集文件生成sdk，sdk保存目录是repo/build/gfc2
cd /d %~dp0

goto copy

build.bat 15 64

@echo off
echo ****************************************
if "%errorlevel%"=="0" (
    echo               SUCCESS
) else (
    echo               FAIL
    goto stop
)
echo ****************************************

:copy

set OUTDIR=..\build\gfc2
set INCDIR=..\include
set LIBDIR=..\lib
set BINDIR=..\bin

if exist %OUTDIR% (		
    rmdir /S /Q  %OUTDIR% 
)
mkdir %OUTDIR%

echo Copying files to %OUTDIR%...

xcopy "%INCDIR%" "%OUTDIR%\include" /e /y /i /s
xcopy "%LIBDIR%\*.lib" "%OUTDIR%\lib"  /y /i /s
xcopy "%BINDIR%\*.dll" "%OUTDIR%\bin"  /y /i /s

:stop