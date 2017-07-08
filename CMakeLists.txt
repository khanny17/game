cmake_minimum_required(VERSION 3.5)
project(Game)

# Include FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/util)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp)

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game ${SDL2_LIBRARY})
