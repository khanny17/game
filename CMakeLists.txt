cmake_minimum_required(VERSION 3.5)
project(Game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FindSDL2.cmake
find_package(SDL2PP REQUIRED)

include_directories(${SDL2PP_INCLUDE_DIRS})

# Export compile_commands.json (for clang-tidy)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()

set(SOURCE_FILES src/main.cpp)

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game ${SDL2PP_LIBRARIES})
