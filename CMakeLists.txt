cmake_minimum_required(VERSION 3.16)
project(nest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(nest)

target_include_directories(nest PUBLIC
        source/ui/menu
        source/ui/menuOption
        )

target_sources(nest PUBLIC
        source/main.cpp
        source/ui/menu/Menu.cpp
        source/ui/menuOption/MenuOption.cpp
        )

