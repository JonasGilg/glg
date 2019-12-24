cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

set(GLG_VERSION "0.0.1")
project(glg VERSION ${GLG_VERSION} LANGUAGES CXX)
enable_testing()

add_subdirectory(glg)
add_library(glg::glg ALIAS glg)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(test)
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})