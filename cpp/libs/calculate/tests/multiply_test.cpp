#include <calculate/multiply.h>
#include "gtest/gtest.h"

TEST( CalculateTests, TestMultiplyIntegerThree_Four )
{
    const auto expected = 12;
    const auto actual = multiply( 3, 4 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestMultiplyIntegerOne_One )
{
    const auto expected = 1;
    const auto actual = multiply( 1, 1 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestMultiplyIntegerZero_Zero )
{
    const auto expected = 0;
    const auto actual = multiply( 0, 0 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestMultiplyIntegerZero_One )
{
    const auto expected = 0;
    const auto actual = multiply( 0, 1 );
    ASSERT_EQ( actual, expected );
}
