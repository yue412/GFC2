del ..\src\GfcClasses\Classes\*.cpp
del ..\include\GfcClasses\x3\Gfc*.h
GenGFCCode.exe -h ..\include\GfcClasses\x3 -r GfcClasses/x3  -c ..\src\GfcClasses\Classes -n ..\src\Classes.net ..\doc\GFC2Core.uml
pause