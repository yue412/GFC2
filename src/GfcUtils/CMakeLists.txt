cmake_minimum_required(VERSION 2.9)

set(PROJECT_NAME GfcUtils)

if(NOT DEFINED ENV{GGPDIR})
    message(FATAL_ERROR "not defined environment variable:GGPDIR")  
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/../include 
    ${PROJECT_SOURCE_DIR}/../include/GfcClasses
	${PROJECT_SOURCE_DIR}/GfcCommon
	$ENV{GGPDIR}/include
)

file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME}/*.h" "./*.h") 
aux_source_directory(. SRC_FILES)
#编译选项
add_compile_definitions(UNICODE)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${HEAD_FILES})
