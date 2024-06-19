cmake_minimum_required(VERSION 3.10)
project(cmake)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h" "src/*.hpp")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(cmake ${SRC_FILES})

target_link_libraries(cmake sfml-system sfml-window sfml-graphics)
target_include_directories(cmake PRIVATE include)
