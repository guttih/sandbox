cmake_minimum_required(VERSION 3.9)
project(apps VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(${PROJECT_NAME} "${PROJECT_NAME}.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(classer)
add_subdirectory(helloWorld)
