cmake_minimum_required(VERSION 3.18)

project(zmq-demo LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(zmq_rep_server main.cpp)

target_link_libraries(zmq_rep_server zmq)
