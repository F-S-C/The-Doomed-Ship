cmake_minimum_required(VERSION 3.14)
project(The_Doomed_Ship)

set(CMAKE_CXX_STANDARD 14)

add_executable(The_Doomed_Ship src/main.cpp src/game.cpp src/game.h src/utilities.h src/utilities/cryptography.cpp src/utilities/cryptography.h src/utilities/string_utilities.cpp src/utilities/string_utilities.h)