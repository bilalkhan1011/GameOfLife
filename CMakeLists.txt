cmake_minimum_required(VERSION 2.8)

project(game)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-std=c99")

add_executable(game Main.c Logic.c)