cd ..
del CMakeCache.txt /s
cd thirdparty\protobuf\cmake\
cmake -Dprotobuf_MSVC_STATIC_RUNTIME=OFF %1 .
cmake --build . --config %2
cd ..\..\..\

cd thirdparty\tinyxml\
cmake %1 .
cmake --build . --config %2
cd ..\..\

cd tools\GenGFCCode\
cmake %1 .
cmake --build . --config %2
cd ..\..\

cd bin
GenGFCCode.exe -h ..\include\Classes -c ..\src\Classes -n ..\src\Classes.net ..\doc\GFC2Core.uml
cd ..\src
cmake %1 .
cmake --build . --config %2
cd ..\bin

pause