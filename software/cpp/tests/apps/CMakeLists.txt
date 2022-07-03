
# Project name: apps
# Make sure parent CMakeLists.txt adds next line above the line "gtest_discover_tests(${PROJECT_NAME})"
#   add_subdirectory(apps)

cmake_minimum_required(VERSION 3.20)

add_executable(
    AppsTests
    AppsMainTest.cc
)
target_link_libraries(
    AppsTests
    gtest_main
)

add_subdirectory(classer)
gtest_discover_tests(
    AppsTests
)