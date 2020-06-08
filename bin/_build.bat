cd ..
cd thirdparty\protobuf\cmake\
cmake -Dprotobuf_MSVC_STATIC_RUNTIME=OFF %2 .
cmake --build . --config %1
cd ..\..\..\

cd thirdparty\tinyxml\cmake
cmake %2 ..\
cmake --build . --config %1
cd ..\..\..\

cd thirdparty\googletest\cmake
cmake -Dgtest_force_shared_crt=ON %2 ..\
cmake --build . --config %1
cd ..\..\..\

cd build
cmake %2 ..\src
cmake --build . --config %1
cd ..

cd tools\GenGFCCode\cmake
cmake %2 ..\
cmake --build . --config %1
cd ..\..\..\

cd bin
GenGFCCode.exe -h ..\include\GfcClasses -c ..\src\GfcClasses\Classes -n ..\src\Classes.net -e .\GFC3X0.exp ..\doc\GFC2Core.uml
copy .\GFC3X0.exp ..\src\GfcClasses\GFC3X0.exp /y
cd ..\build
cmake %2 ..\src
cmake --build . --config %1
cd ..

cd tests\cmake
cmake %2 ..\
cmake --build . --config %1
cd ..\..\

cd bin