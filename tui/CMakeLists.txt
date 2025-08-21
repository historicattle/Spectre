cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tui
    main.cpp
    # Add other source files here if needed
)

target_include_directories(tui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)