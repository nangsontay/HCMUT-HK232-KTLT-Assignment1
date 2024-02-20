cmake_minimum_required(VERSION 3.27)
# Define the project name
project(Assignment1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(.)

add_executable(initial
        main.cpp
        main.h
        study_in_pink1.cpp
        study_in_pink1.h)
