#include <calculate/add.h>
#include "gtest/gtest.h"

TEST( CalculateTests, TestAddIntegerOne_One )
{
    const auto expected = 2;
    const auto actual = add( 1, 1 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestAddIntegerZero_Zero )
{
    const auto expected = 0;
    const auto actual = add( 0, 0 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestAddIntegerZero_One )
{
    const auto expected = 1;
    const auto actual = add( 0, 1 );
    ASSERT_EQ( actual, expected );
}

