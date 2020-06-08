cd ..
cd thirdparty\protobuf\cmake\
cmake -Dprotobuf_MSVC_STATIC_RUNTIME=OFF %1 .
cmake --build . --config %2
cd ..\..\..\

cd thirdparty\tinyxml\cmake
cmake %1 ..\
cmake --build . --config %2
cd ..\..\..\

cd thirdparty\googletest\cmake
cmake -Dgtest_force_shared_crt=ON %1 ..\
cmake --build . --config %2
cd ..\..\..\

cd build
cmake %1 ..\src
cmake --build . --config %2
cd ..

cd tools\GenGFCCode\cmake
cmake %1 ..\
cmake --build . --config %2
cd ..\..\..\

cd bin
GenGFCCode.exe -h ..\include\GfcClasses -c ..\src\GfcClasses -n ..\src\Classes.net -e ..\src\GfcTextSerializer\GFC2X1.exp ..\doc\GFC2Core.uml
cd ..\build
cmake %1 ..\src
cmake --build . --config %2
cd ..

cd tests\cmake
cmake %1 ..\
cmake --build . --config %2
cd ..\..\

cd bin