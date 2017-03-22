cmake_minimum_required(VERSION 3.6)
project(trabalho_idj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Game.cpp
        Game.h
        main.cpp
        Sprite.cpp
        Sprite.h
        State.cpp
        State.h)

add_executable(trabalho_idj ${SOURCE_FILES})