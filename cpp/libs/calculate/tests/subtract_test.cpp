#include <calculate/subtract.h>
#include "gtest/gtest.h"

TEST( CalculateTests, TestSubtractIntegerOne_One )
{
    const auto expected = 0;
    const auto actual = subtract( 1, 1 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestSubtractIntegerZero_Zero )
{
    //todo:Change expected value to 0 to make test pass instead of fail
    const auto expected = 0;
    const auto actual = subtract( 0, 0 );
    ASSERT_EQ( expected, actual );
}

TEST( CalculateTests, TestSubtractIntegerZero_One )
{
    const auto expected = -1;
    const auto actual = subtract( 0, 1 );
    ASSERT_EQ( actual, expected );
}

