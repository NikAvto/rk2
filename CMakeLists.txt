cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_TESTS "Build tests" OFF)

project (worker)

add_library(worker STATIC ${CMAKE_CURRENT_SOURCE_DIR}/worker.cpp)
target_link_libraries(worker gcov)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB WORKER_TEST_SOURCES tests/test.cpp)
  add_executable(check ${WORKER_TEST_SOURCES})
  target_link_libraries(check worker gtest_main)
  add_test(NAME check COMMAND check)
endif()
