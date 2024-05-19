cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(worker)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR})

if (BUILD_TESTS)
  add_subdirectory(third-party/gtest)
  enable_testing()
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  file(GLOB WORKER_TEST_SOURCES tests/*.cpp)
  add_executable(check ${WORKER_TEST_SOURCES})
  target_link_libraries(check gtest)
  add_test(NAME check COMMAND check)
endif ()
