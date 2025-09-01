cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

add_library(tui
    src/main.cpp
)

target_link_libraries(tui
  PUBLIC ftxui::screen
  PUBLIC ftxui::dom
  PUBLIC ftxui::component
)

target_include_directories(tui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)