cmake_minimum_required(VERSION 3.10)

# Project's declaration:

project(AI-agent)

# Folder Declaration:


# Header include:

include_directories(include/)

#Folder Creation:

file(MAKE_DIRECTORY build)

# Executable's declaration:

add_executable(

    matrix_test

    src/matrix/matrix_unit_test.cpp

    src/matrix/matrix.cpp
    include/matrix/matrix.hpp
)
