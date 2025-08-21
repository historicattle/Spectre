cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tracer
	src/Compilation.cpp
	src/CpuInfo.cpp
	src/Memcheck.cpp
	src/main.cpp
)

target_include_directories(tracer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )