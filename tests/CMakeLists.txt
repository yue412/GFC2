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
	${PROJECT_SOURCE_DIR}/../src/EntitySchema
	${PROJECT_SOURCE_DIR}/../src/ExpEngine
	${PROJECT_SOURCE_DIR}/../src/GfcTextSerializer
	${PROJECT_SOURCE_DIR}/../src/GfcCommon
	${PROJECT_SOURCE_DIR}/../src/GfcEngine
	${PROJECT_SOURCE_DIR}/../thirdparty/tinyxml
	)
link_directories(
	${CMAKE_SOURCE_DIR}/../lib
	${CMAKE_SOURCE_DIR}/../thirdparty/googletest/cmake/lib/$<CONFIG>
	)

FILE(GLOB SRC_FILES "./*.c*" "../src/GfcTextSerializer/EntityParser/*.cpp" "../src/GfcTextSerializer/TextUpdater.cpp" "../src/GfcTextSerializer/Parser.cpp" "../src/GfcTextSerializer/Scanner.cpp" "../src/GfcTextSerializer/dllmain.cpp") 
FILE(GLOB HEAD_FILES "./*.h" "../src/GfcTextSerializer/EntityParser/*.h" "../src/GfcTextSerializer/TextUpdater.h" "../src/GfcTextSerializer/Parser.h" "../src/GfcTextSerializer/Scanner.h") 

add_compile_definitions(TIXML_USE_STL _CRT_SECURE_NO_DEPRECATE UNICODE)

#创建工程文件
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX d)

target_link_libraries(${PROJECT_NAME} debug ExpEngined optimized ExpEngine)
target_link_libraries(${PROJECT_NAME} debug gtestd optimized gtest)
target_link_libraries(${PROJECT_NAME} debug GfcEngined optimized GfcEngine)
target_link_libraries(${PROJECT_NAME} debug EntitySchemad optimized EntitySchema)
target_link_libraries(${PROJECT_NAME} debug GfcCommond optimized GfcCommon)
target_link_libraries(${PROJECT_NAME} debug tinyxmld optimized tinyxml)
