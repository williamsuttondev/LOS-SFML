cmake_minimum_required(VERSION 3.10)
project(LOS-SFML)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Set build type to Debug by default if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Enable compile commands for use with language servers
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Optionally set the C++ compiler
# set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# Add source files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h" "src/*.hpp")

# Add executable
add_executable(cmake ${SRC_FILES})

# Link SFML libraries
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(cmake sfml-system sfml-window sfml-graphics)

# Find and link TinyXML2 using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(TINYXML2 REQUIRED tinyxml2)
target_include_directories(cmake PRIVATE ${TINYXML2_INCLUDE_DIRS})
target_link_libraries(cmake ${TINYXML2_LIBRARIES})

# Include directories
target_include_directories(cmake PRIVATE include)

# Add a custom command to copy the res folder to the build directory
add_custom_command(
    TARGET cmake POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/res"
    "$<TARGET_FILE_DIR:cmake>/res"
)
