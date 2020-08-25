cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcSchema)

include_directories(
    ${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/GfcCommon
)
link_directories(${PROJECT_SOURCE_DIR}/../lib)

file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/GfcSchema/*.h" "./*.h") 
aux_source_directory(. SRC_FILES)
#编译选项
add_compile_definitions(GFCSCHEMA_EXPORTS UNICODE)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES})
target_link_libraries(${PROJECT_NAME} debug GfcCommond optimized GfcCommon)