# Project settings
cmake_minimum_required(VERSION 2.6)
project(pong)

set(pong_VERSION_MAJOR 0)
set(pong_VERSION_MINOR 5)
set(pong_VERSION_REVISION 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/pong/config.hpp.in"
    "${PROJECT_BINARY_DIR}/config.hpp"
)

# Compiler settings
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
endif()
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
endif()

# Includes and libraries settings
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

include(FindPkgConfig)

find_package(SFML 2 REQUIRED graphics system window )
if (SFML_FOUND)
    set(EXTRA_INCLUDES ${EXTRA_INCLUDES} ${SFML_INCLUDE_DIR})
    set(EXTRA_LIBS ${EXTRA_LIBS} ${SFML_LIBRARIES})
endif()

find_package(Box2D REQUIRED)
if (BOX2D_FOUND)
    set(EXTRA_INCLUDES ${EXTRA_INCLUDES} ${BOX2D_INCLUDE_DIR})
    set(EXTRA_LIBS ${EXTRA_LIBS} ${BOX2D_LIBRARIES})
endif()

# Executable settings
include_directories(${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
    ${EXTRA_INCLUDES}
)

add_executable(${PROJECT_NAME}
    pong/main.cpp
    pong/game.cpp
    pong/state.cpp
    pong/game_state.cpp
    pong/game_world.cpp
    pong/input_handler.cpp
    pong/factories.cpp
    mxg/sfml_debug_draw.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${EXTRA_LIBS}
)
