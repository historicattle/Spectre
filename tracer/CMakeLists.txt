cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(tracer
	src/Compilation.cpp
	src/main.cpp
	src/spy.cpp)

target_include_directories(tracer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )
file(COPY ${CMAKE_SOURCE_DIR}/tui/config/Compilation.txt DESTINATION ${PROJECT_BINARY_DIR})