cmake_minimum_required(VERSION 3.16)
project(intelligent_systems_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(map_coloring
    src/constraint_satisfaction/map_coloring/backtracking.cpp
)
