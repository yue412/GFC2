cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcCommon)

include_directories(
    ${PROJECT_SOURCE_DIR}/../include 
)

aux_source_directory(. SRC_FILES)
file(GLOB HEAD_FILES "./*.h") 
#编译选项
add_compile_definitions(_CRT_SECURE_NO_WARNINGS UNICODE)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${HEAD_FILES})