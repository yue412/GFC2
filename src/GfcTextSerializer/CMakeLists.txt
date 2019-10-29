cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcTextSerializer)
include_directories(
	${PROJECT_SOURCE_DIR}/../include/Classes
	${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/EntitySchema 
	${PROJECT_SOURCE_DIR}/GfcEngine
	${PROJECT_SOURCE_DIR}/../thirdparty/tinyxml	
)

file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/glodon/objectbuf/*.h") 
file(GLOB_RECURSE SRC_FILES  ${PROJECT_SOURCE_DIR}/${PROJECT_NAME} *.cpp *.h)
source_group(TREE ${PROJECT_SOURCE_DIR}/${PROJECT_NAME} PREFIX "Source Files" FILES ${SRC_FILES})

link_directories(${PROJECT_SOURCE_DIR}/../lib)
#编译选项
add_compile_definitions(UNICODE TIXML_USE_STL)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES})
target_link_libraries(${PROJECT_NAME} debug EntitySchemad optimized EntitySchema)
target_link_libraries(${PROJECT_NAME} debug GfcEngined optimized GfcEngine)
target_link_libraries(${PROJECT_NAME} debug tinyxmld optimized tinyxml)
