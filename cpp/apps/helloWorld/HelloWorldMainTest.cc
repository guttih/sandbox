// File: HelloWorldMainTest.cc

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST( HelloWorldTest, BasicAssertions ) {
// Expect two strings not to be equal.
    EXPECT_STRNE( "hello", "world" );
// Expect equality.
    EXPECT_EQ( 7 * 6, 42 );
}