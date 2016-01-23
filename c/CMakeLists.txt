cmake_minimum_required(VERSION 3.3)
project(practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES linkedlist.c BinaryTree.cpp BinaryTree.h main.cpp reverse_string.c)
add_executable(practice ${SOURCE_FILES})