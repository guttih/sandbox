cmake_minimum_required(VERSION 3.9)
project(libs VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(libs libs.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(calculate)


