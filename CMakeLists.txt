cmake_minimum_required(VERSION 3.5)

project(game_of_life LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL2 REQUIRED)
add_executable(game_of_life main.cpp)
target_link_libraries(game_of_life SDL2::SDL2)
