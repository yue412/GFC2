del ..\src\GfcClasses\Classes\*.cpp
del ..\include\GfcClasses\Gfc2*.h
GenGFCCode.exe -h ..\include\GfcClasses -c ..\src\GfcClasses\Classes -n ..\src\Classes.net ..\doc\GFC2Core.uml
pause