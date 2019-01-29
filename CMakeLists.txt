cmake_minimum_required(VERSION 3.13.3)
project(Condemned_Ship)
set(CMAKE_CXX_STANDARD 11)

#Bring the headers, such as Student.h into the project
include_directories(include)

set(SOURCES
   src/main.cpp
   src/game.cpp
   src/utilities/string_utilities.cpp
   src/utilities/cryptography.cpp
)

add_executable(ship ${SOURCES})