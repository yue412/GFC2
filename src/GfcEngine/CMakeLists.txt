cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcEngine)

include_directories(
	${PROJECT_SOURCE_DIR}/../include/Classes
	${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/../thirdparty/tinyxml
	${PROJECT_SOURCE_DIR}/GfcCommon
	${PROJECT_SOURCE_DIR}/EntitySchema
	${PROJECT_SOURCE_DIR}/${PROJECT_NAME}
)
link_directories(${PROJECT_SOURCE_DIR}/../lib)

file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/GfcEngine/*.h") 
file(GLOB_RECURSE SRC_FILES  ${PROJECT_SOURCE_DIR}/GfcEngine *.cpp *.h)
source_group(TREE ${PROJECT_SOURCE_DIR}/GfcEngine PREFIX "Source Files" FILES ${SRC_FILES})

#编译选项
add_compile_definitions(GFCENGINE_EXPORTS TIXML_USE_STL UNICODE)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES})

target_link_libraries(${PROJECT_NAME} debug EntitySchemad optimized EntitySchema)
target_link_libraries(${PROJECT_NAME} debug GfcCommond optimized GfcCommon)
target_link_libraries(${PROJECT_NAME} debug tinyxmld optimized tinyxml)