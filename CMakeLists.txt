cmake_minimum_required(VERSION 3.10)
project(ChainOfResponsibility)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} worker.cpp)
