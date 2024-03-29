cmake_minimum_required(VERSION 3.14)

project(cppTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    ${PROJECT_NAME}
    ${PROJECT_NAME}.cc
)

target_link_libraries(
  ${PROJECT_NAME}
  gtest_main
)

include(GoogleTest)

add_subdirectory(apps)

gtest_discover_tests(${PROJECT_NAME})