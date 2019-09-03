cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../../bin)
set(CMAKE_DEBUG_POSTFIX d)

project(GenGFCCode)
SET(CMAKE_PREFIX_PATH D:/SDK/Qt/Qt5.6.3/5.6.3/msvc2015)
find_package(Qt5Core)
find_package(Qt5Widgets)

#include_directories(SYSTEM D:/SDK/Qt/Qt5.6.3/5.6.3/msvc2015/include/QtCore D:/SDK/Qt/Qt5.6.3/5.6.3/msvc2015/include D:/SDK/Qt/Qt5.6.3/5.6.3/msvc2015/include/QtWidgets)
#aux_source_directory(. DIR_SRCS)
#add_executable(GenGFCCode2 ${DIR_SRCS})

FILE(GLOB SRC_FILES "./*.c*") 
FILE(GLOB HEAD_FILES "./*.h") 

add_compile_definitions("UNICODE")

#创建工程文件
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES})

#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core)