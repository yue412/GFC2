cmake -Dprotobuf_MSVC_STATIC_RUNTIME=OFF %2  -B ..\build\protobuf -S ..\thirdparty\protobuf\cmake\
cmake --build ..\build\protobuf --config %1

cmake %2 -B ..\build\tinyxml -S ..\thirdparty\tinyxml\
cmake --build ..\build\tinyxml --config %1

cmake -Dgtest_force_shared_crt=ON %2 -B ..\build\googletest -S ..\thirdparty\googletest\
cmake --build ..\build\googletest --config %1

cmake %2 -B ..\build -S ..\src
cmake --build ..\build --config %1

cmake %2 -B ..\build\GenGFCCode -S ..\tools\GenGFCCode\
cmake --build ..\build\GenGFCCode  --config %1

cd bin
GenGFCCode.exe -h ..\include\GfcClasses\x3 -r GfcClasses/x3 -c ..\src\GfcClasses\Classes -n ..\src\Classes.net -e .\GFC3X0.exp ..\doc\GFC2Core.uml
copy .\GFC3X0.exp ..\src\GfcClasses\GFC3X0.exp /y

cmake %2 -B ..\build -S ..\src
cmake --build ..\build --config %1

REM cmake %2  -B ..\build\tests -S ..\tests\
REM cmake --build ..\build\tests --config %1
