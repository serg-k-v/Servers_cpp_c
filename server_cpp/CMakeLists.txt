cmake_minimum_required (VERSION 3.0)

project (Async_Server_ASIO)

if (${CMAKE_VERSION} VERSION_LESS "3.1")
    add_compile_options (-std=c++14)
else ()
    set (CMAKE_CXX_STANDARD 14)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)
endif ()

find_package (Boost REQUIRED COMPONENTS system)

include_directories (
    "${CMAKE_CURRENT_SOURCE_DIR}/tcp_server"
    ${Boost_INCLUDE_DIRS}
    )

add_subdirectory (tcp_server)
set (TCP_SERVER_LIB ${TCP_SERVER_LIB} TCP_Server)

add_library(TCP_Server)
add_executable (Async_server async_server.cpp)

target_link_libraries (Async_server ${TCP_SERVER_LIB} ${Boost_LIBRARIES})

install(TARGETS Async_server
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )
