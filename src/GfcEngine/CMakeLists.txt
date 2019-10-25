cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcEngine)
#aux_source_directory(. SRC_FILES)
#aux_source_directory(./Classes SRC_FILES)
include_directories(
	${PROJECT_SOURCE_DIR}/../include/Classes
	${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/${PROJECT_NAME}
)
file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/glodon/objectbuf/*.h") 
file(GLOB_RECURSE SRC_FILES  ${PROJECT_SOURCE_DIR}/GfcEngine *.cpp *.h)
source_group(TREE ${PROJECT_SOURCE_DIR}/GfcEngine PREFIX "Source Files" FILES ${SRC_FILES})

#编译选项
add_compile_definitions(OBJECTBUF_EXPORTS GFCCLASSES_EXPORTS UNICODE)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES})