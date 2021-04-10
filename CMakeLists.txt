cmake_minimum_required(VERSION 3.17)
project(clib)

set(CMAKE_CXX_STANDARD 11)

add_executable(clib main.cpp src/core/bstree.c src/core/bstree.h src/core/fibonacci.c src/core/fibonacci.h src/core/rbtree.c src/core/rbtree.h)