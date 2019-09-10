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
GenGFCCoded.exe -h D:\GFC2\include\Classes -c D:\GFC2\src\Classes -n D:\GFC2\src\Classes.net D:\GFC2\doc\GFC2Core.uml
cd ..\src
cmake %1 .
cmake --build . --config %2
cd ..\bin

pause