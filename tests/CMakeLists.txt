cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/../bin)
#set(CMAKE_DEBUG_POSTFIX d)

project(UnitTest)

include_directories(
	${PROJECT_SOURCE_DIR}/../thirdparty/googletest/googletest/include
	${PROJECT_SOURCE_DIR}/../include
	${PROJECT_SOURCE_DIR}/../include/GfcClasses
	${PROJECT_SOURCE_DIR}/../src/GfcSchema
	${PROJECT_SOURCE_DIR}/../src/GfcTextSerializer
	${PROJECT_SOURCE_DIR}/../src/GfcCommon
	${PROJECT_SOURCE_DIR}/../src/GfcEngine
	${PROJECT_SOURCE_DIR}/../thirdparty/tinyxml
	)
link_directories(
	${CMAKE_SOURCE_DIR}/../lib
	${CMAKE_SOURCE_DIR}/../thirdparty/googletest/cmake/lib/$<CONFIG>
	)

FILE(GLOB SRC_FILES "./*.c*" 
	"../src/GfcEngine/ConverterImp.cpp" 
	"../src/GfcEngine/Parser.cpp" 
	"../src/GfcEngine/Scanner.cpp" 
	"../src/GfcEngine/WriterImp.cpp"
	"../src/GfcEngine/WriterTextImp.cpp"
	"../src/GfcEngine/ReaderImp.cpp"
	"../src/GfcEngine/ReaderFileMapImp.cpp"
	"../src/GfcEngine/ReaderTextImp.cpp"
	"../src/GfcEngine/FileMap.cpp"
	) 
FILE(GLOB HEAD_FILES "./*.h" 
	"../src/GfcEngine/ConverterImp.h"  
	"../src/GfcEngine/Parser.h" 
	"../src/GfcEngine/Scanner.h" 
	"../src/GfcEngine/WriterImp.h"
	"../src/GfcEngine/WriterTextImp.h"
	"../src/GfcEngine/ReaderImp.h"
	"../src/GfcEngine/ReaderFileMapImp.h"
	"../src/GfcEngine/ReaderTextImp.h"
	"../src/GfcEngine/FileMap.h"
	) 

add_compile_definitions(TIXML_USE_STL _CRT_SECURE_NO_WARNINGS UNICODE)

#创建工程文件
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX d)

target_link_libraries(${PROJECT_NAME} debug gtestd optimized gtest)
target_link_libraries(${PROJECT_NAME} debug GfcEngined optimized GfcEngine)
target_link_libraries(${PROJECT_NAME} debug GfcClasses3d optimized GfcClasses3)
target_link_libraries(${PROJECT_NAME} debug GfcSchemad optimized GfcSchema)
target_link_libraries(${PROJECT_NAME} debug GfcCommond optimized GfcCommon)
target_link_libraries(${PROJECT_NAME} debug tinyxmld optimized tinyxml)
target_link_libraries(${PROJECT_NAME} debug GfcUtilsd optimized GfcUtils)
