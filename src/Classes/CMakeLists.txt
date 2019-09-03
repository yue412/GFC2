cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcClasses)
aux_source_directory(. SRC_FILES)
include_directories(${PROJECT_SOURCE_DIR}/../include/Classes)
#link_directories(${PROJECT_BINARY_DIR}/../../externals/GlodonResource/ThirdPart/VLD/lib/Win32)
file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/Classes/*.h") 
#编译选项
#add_compile_definitions("GFCENGINE_EXPORTS")
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES})
#target_link_libraries(${PROJECT_NAME} debug vld)
