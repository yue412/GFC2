@echo off
set platform=
if "%2"=="64" (set platform= Win64)
set generator=
if "%1"=="" (set generator=)
if "%1"=="10" (set generator=-G"Visual Studio 10 2010%platform%")
if "%1"=="11" (set generator=-G"Visual Studio 11 2012%platform%")
if "%1"=="12" (set generator=-G"Visual Studio 12 2013%platform%")
if "%1"=="14" (set generator=-G"Visual Studio 14 2015%platform%")
if "%1"=="15" (set generator=-G"Visual Studio 15 2017%platform%")
if "%1"=="16" (set generator=-G"Visual Studio 16 2019%platform%")
echo %generator%
set build_type=Debug
if "%3"=="release" (set build_type=Release) 
echo %build_type%
echo on
_build.bat %generator% %build_type%
