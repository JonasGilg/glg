cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(GLG_VERSION "0.0.1")
project(glg VERSION ${GLG_VERSION} LANGUAGES CXX)

add_subdirectory(glg)
add_library(glg::glg ALIAS glg)

add_subdirectory(test)