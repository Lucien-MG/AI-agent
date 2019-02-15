cmake_minimum_required(VERSION 3.10)

# Project's declaration:

project(AI-agent)

# Folder Declaration:



# Header include:

include_directories(inc/)

#Folder Creation:

file(MAKE_DIRECTORY build)

# Executable's declaration:


# Matrix test program:
add_executable(

    matrix_test

    src/test/matrix_unit_test.cpp

    src/test/libtest.cpp

    src/matrix/matrix.cpp
)

# Matrix benchmark program:
add_executable(
    
    matrix_bench

    src/benchmark/matrix_bench.cpp #Main

    src/benchmark/libbench.cpp

    src/matrix/matrix.cpp
)

