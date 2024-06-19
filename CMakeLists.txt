cmake_minimum_required(VERSION 3.10)
project(cmake)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES
	main.cpp
	test1.cpp	
)

set(HEADERS
	test1.h
)

add_executable(cmake ${SOURCES} ${HEADERS})

target_link_libraries(cmake sfml-system sfml-window sfml-graphics)
