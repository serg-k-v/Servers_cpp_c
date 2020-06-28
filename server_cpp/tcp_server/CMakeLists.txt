cmake_minimum_required (VERSION 3.0)

project (TCP_Server)

aux_source_directory (${CMAKE_CURRENT_SOURCE_DIR}/src SOURCE_FILES)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library (${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)