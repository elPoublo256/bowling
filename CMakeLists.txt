cmake_minimum_required(VERSION 2.8.3)

project(bowling)

SET(CMAKE_CXX_STANDART 11)
SET(CMAKE_CXX_COMPILER g++-8)
SET(COMPILE_OPTIONS -Wpedantic -Wall -Wextra)

add_executable(bowling main.cpp)

add_library(bow-dev  bowlib/frame.h 
	bowlib/frame.cpp 
	bowlib/game.h
	bowlib/game.cpp
	bowlib/player.h
	bowlib/player.cpp)

target_link_libraries(bowling bow-dev)

