cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
project(natureofcode)

#add_subdirectory(ch01)

include_directories(include)

add_library(vector src/vector/vector.cpp)
add_library(mover src/mover/mover.cpp)
add_library(moversfml src/graphics/moversfml.cpp)

# Chapter 1
add_executable(bouncing-ball-no-vectors ch01/bouncing-ball-no-vectors.cpp)
target_link_libraries(bouncing-ball-no-vectors sfml-graphics sfml-window sfml-system)

add_executable(bouncing-ball-vectors ch01/bouncing-ball-vectors.cpp)
target_link_libraries(bouncing-ball-vectors sfml-graphics sfml-window sfml-system vector)

add_executable(ball-mover ch01/ball-mover.cpp)
target_link_libraries(ball-mover sfml-graphics sfml-window sfml-system moversfml vector)

add_executable(ball-mouse-follower ch01/ball-mouse-follower.cpp)
target_link_libraries(ball-mouse-follower sfml-graphics sfml-window sfml-system moversfml vector)
