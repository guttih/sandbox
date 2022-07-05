
# Project name: helloWorld
# Make sure parent/root CMakeLists.txt adds next line above the line "gtest_discover_tests(${This})"
#   add_subdirectory(helloWorld)
cmake_minimum_required(VERSION 3.9)

add_executable(
    HelloWorldTests
    HelloWorldMainTest.cc
)
target_link_libraries(
    HelloWorldTests
    gtest_main
)

# Now, create a file called HelloWorldMainTest.cc and add the following content to it: 
#     // File: HelloWorldMainTest.cc
#
#     #include <gtest/gtest.h>
#
#     // Demonstrate some basic assertions.
#     TEST(HelloWorldTest, BasicAssertions) {
#     // Expect two strings not to be equal.
#     EXPECT_STRNE("hello", "world");
#     // Expect equality.
#     EXPECT_EQ(7 * 6, 42);
#     }
