cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)

add_library(tui
    src/main.cpp
)

target_include_directories(tui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG v6.1.9
)
 
FetchContent_MakeAvailable(ftxui)
 
add_executable(main src/main.cpp)
target_link_libraries(main
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
