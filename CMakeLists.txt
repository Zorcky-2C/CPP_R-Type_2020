cmake_minimum_required(VERSION 3.16)

project(B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()
conan_basic_setup()

include_directories(client/src)
include_directories(client/src/Engine)
include_directories(client/src/Event)
include_directories(client/src/Network)
include_directories(client/src/Sprite)
include_directories(client/src/States)
include_directories(client/src/Text)
include_directories(client/src/Window)
include_directories(server)

set(SRC_SERVER ${CMAKE_SOURCE_DIR}/server/)
set(INC_SERVER ${CMAKE_SOURCE_DIR}/server/)

set(SRC_CLIENT ${CMAKE_SOURCE_DIR}/client/)
set(INC_CLIENT ${CMAKE_SOURCE_DIR}/client/)

FILE(GLOB_RECURSE SRC_SERVER_FILE ${SRC_SERVER}/*.cpp)
FILE(GLOB_RECURSE INC_SERVER_FILE ${INC_SERVER}/*.hpp)

FILE(GLOB_RECURSE SRC_CLIENT_FILE ${SRC_CLIENT}/*.cpp)
FILE(GLOB_RECURSE INC_CLIENT_FILE ${INC_CLIENT}/*.hpp)

add_executable(r-type_server ${SRC_SERVER_FILE} ${INC_SERVER})
add_executable(r-type_client ${SRC_CLIENT_FILE} ${INC_CLIENT})
target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})