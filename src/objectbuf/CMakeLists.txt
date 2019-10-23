cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME objectbuf)
aux_source_directory(. SRC_FILES)
include_directories(
	${PROJECT_SOURCE_DIR}/../include 
	${PROJECT_SOURCE_DIR}/../thirdparty/protobuf/src
	${PROJECT_SOURCE_DIR}/EntitySchema 
)
#link_directories(${PROJECT_BINARY_DIR}/../thirdparty/protobuf/cmake/$<$<CONFIG:Debug>:Debug>$<$<NOT:$<CONFIG:Debug>>:Release>)
link_directories(${PROJECT_BINARY_DIR}/../thirdparty/protobuf/cmake/$<CONFIG>)
file(GLOB HEAD_FILES "${PROJECT_SOURCE_DIR}/../include/glodon/objectbuf/*.h") 
#编译选项
add_compile_definitions(OBJECTBUF_EXPORTS UNICODE)
add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEAD_FILES})
target_link_libraries(${PROJECT_NAME} debug libprotobufd optimized libprotobuf)
target_link_libraries(${PROJECT_NAME} debug EntitySchemad optimized EntitySchema)
