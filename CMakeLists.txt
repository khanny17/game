cmake_minimum_required(VERSION 3.8)
project(Game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FindSDL2.cmake
find_package(SDL2PP REQUIRED)

include_directories(${SDL2PP_INCLUDE_DIRS})

find_program(
  CLANG_TIDY_EXE
  NAMES "clang-tidy"
  DOC "Path to clang-tidy executable"
  )
if(NOT CLANG_TIDY_EXE)
  message(STATUS "clang-tidy not found.")
else()
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
  set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-alpha.*")
endif()

# Export compile_commands.json (for clang-tidy)
SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )
SET( CMAKE_INCLUDE_HEADERS_IN_COMPILE_COMMANDS ON )
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()

# Setup our source/include files
include_directories("src")
file(GLOB SOURCE_FILES 
    "src/*.hpp"
    "src/*.cpp"
)

# Setup compile warnings
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game ${SDL2PP_LIBRARIES})

set_target_properties(
  Game PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_FLAGS "${WARNING_FLAGS}"
)

if(CLANG_TIDY_EXE)
  set_target_properties(
    Game PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()


#Setup testing stuff
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE "lib/Catch/single_include")

file(GLOB TEST_SOURCES "test/unit/*.cpp")

set(SOURCE_FILES_FOR_TEST ${SOURCE_FILES})
list(REMOVE_ITEM SOURCE_FILES_FOR_TEST ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(unit_tests ${TEST_SOURCES} ${SOURCE_FILES_FOR_TEST})
target_link_libraries(unit_tests Catch)
target_link_libraries(unit_tests ${SDL2PP_LIBRARIES})

enable_testing()
add_test(NAME UnitTests COMMAND unit_tests)
