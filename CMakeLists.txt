cmake_minimum_required(VERSION 3.30)
project(last C)

set(CMAKE_C_STANDARD 11)

add_executable(last main.c
        grid.h
        "player movement.h"
        asteroid.h
        fuel.h
        oxegen.h
        "scavanger ships.h"
        junk.h)
