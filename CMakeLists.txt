cmake_minimum_required(VERSION 3.0)
project(po)

file(GLOB srcs "*.h" "*.cpp")
add_executable(po ${srcs}) 
