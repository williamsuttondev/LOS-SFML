cmake_minimum_required(VERSION 3.10)

include(FetchContent)

project(LOS-SFML)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable compile_commands.json for use with language servers
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add source files
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h" "src/*.hpp")

# Add executable
add_executable(LOS-SFML ${SRC_FILES})

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_Declare(
    tinyxml2
    GIT_REPOSITORY https://github.com/leethomason/tinyxml2
    GIT_TAG        10.0.0
)
FetchContent_MakeAvailable(SFML json tinyxml2)

target_include_directories (LOS-SFML PUBLIC ${nlohmann_json_SOURCE_DIR}/include)
target_link_libraries(LOS-SFML sfml-system sfml-window sfml-graphics tinyxml2)

# Add a custom command to copy the res folder to the build directory
add_custom_command(
    TARGET LOS-SFML PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
    "${CMAKE_SOURCE_DIR}/res"
    "$<TARGET_FILE_DIR:LOS-SFML>/res"
)
