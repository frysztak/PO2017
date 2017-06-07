cmake_minimum_required(VERSION 3.0)
project(po)

file(GLOB srcs "*.cpp")
list(FILTER srcs EXCLUDE REGEX "tests.cpp")
list(FILTER srcs EXCLUDE REGEX "main.cpp")

add_executable(po "main.cpp" ${srcs}) 
add_executable(po_tests "tests.cpp" ${srcs})
