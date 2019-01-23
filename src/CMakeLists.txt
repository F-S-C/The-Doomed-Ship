cmake_minimum_required(VERSION 3.13.3)
project(test)

#Bring the headers, such as Student.h into the project
#include_directories(src)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp")

add_executable(test ${SOURCES})