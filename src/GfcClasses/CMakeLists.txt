cmake_minimum_required(VERSION 2.9)

set(PROJECT_NAME GfcClasses)
include_directories(
	${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/GfcEngine
	${PROJECT_SOURCE_DIR}/GfcSchema
	${PROJECT_SOURCE_DIR}/${PROJECT_NAME}
)

file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/GfcClasses/x3/*.h") 
file(GLOB_RECURSE SRC_FILES  ${PROJECT_SOURCE_DIR}/${PROJECT_NAME} *.cpp *.h *.rc)
source_group(TREE ${PROJECT_SOURCE_DIR}/${PROJECT_NAME} PREFIX "Source Files" FILES ${SRC_FILES})

#set_source_files_properties(Gfc2.rc PROPERTIES LANGUAGE RC)

link_directories(${PROJECT_SOURCE_DIR}/../lib)
#编译选项
add_compile_definitions(UNICODE GFCCLASSES_EXPORTS TIXML_USE_STL _CRT_SECURE_NO_WARNINGS)
set(PROJECT_ALIAS_NAME ${PROJECT_NAME}3)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

if(UNIX)
	add_compile_options(-std=c++11 -fPIC -g)
	#add_compile_options(-std=c++11 -fPIC -g  -fvisibility=hidden)
	set(RESOURCE_FILE ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/gfc_exp.o)
	set(COMD1 objcopy -I binary -O elf64-x86-64 -B i386 GFC.exp gfc_exp.o)
	add_custom_target(gfc_exp.o ALL COMMAND ${COMD1} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/)
endif()
add_library(${PROJECT_ALIAS_NAME} SHARED ${SRC_FILES} ${HEAD_FILES} ${RESOURCE_FILE})

target_link_libraries(${PROJECT_ALIAS_NAME} debug GfcSchemad optimized GfcSchema)
target_link_libraries(${PROJECT_ALIAS_NAME} debug GfcEngined optimized GfcEngine)