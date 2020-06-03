cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME GfcClasses)
include_directories(
	${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME}
	${PROJECT_SOURCE_DIR}/GfcEngine
	${PROJECT_SOURCE_DIR}/GfcSchema
	${PROJECT_SOURCE_DIR}/${PROJECT_NAME}
)

file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/GfcClasses/*.h") 
file(GLOB_RECURSE SRC_FILES  ${PROJECT_SOURCE_DIR}/${PROJECT_NAME} *.cpp *.h *.rc)

#set_source_files_properties(Gfc2.rc PROPERTIES LANGUAGE RC)

link_directories(${PROJECT_SOURCE_DIR}/../lib)
#编译选项
add_compile_definitions(UNICODE GFCCLASSES_EXPORTS TIXML_USE_STL _CRT_SECURE_NO_WARNINGS)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES} ${RESOURCE_FILE})
target_link_libraries(${PROJECT_NAME} debug GfcSchemad optimized GfcSchema)
target_link_libraries(${PROJECT_NAME} debug GfcEngined optimized GfcEngine)