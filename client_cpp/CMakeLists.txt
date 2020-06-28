cmake_minimum_required (VERSION 3.0)

project (Sync_Client_ASIO)

if (${CMAKE_VERSION} VERSION_LESS "3.1")
    add_compile_options (-std=c++14)
else ()
    set (CMAKE_CXX_STANDARD 14)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)
endif ()

find_package (Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

include_directories (
    ${Boost_INCLUDE_DIRS}
    )

add_executable (Sync_Client sync_client.cpp)

target_link_libraries (Sync_Client ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS Sync_Client RUNTIME DESTINATION bin)
