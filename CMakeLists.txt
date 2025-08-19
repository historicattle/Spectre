cmake_minimum_required(VERSION 3.10)
project(Spectre LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(tracer)
add_subdirectory(tui)
