#ifndef TEST_ISINRANGE
#define TEST_ISINRANGE


#include <gtest/gtest.h>
#include "../src/node.hpp"


using namespace rpgDialogue;


TEST(testIsInRange, testBelowRange) {
    ASSERT_FALSE(isInRange(2, 5, 7));
}

TEST(testIsInRange, testEqualRangeStart) {
    ASSERT_TRUE(isInRange(-4, -4, 5));
}

TEST(testIsInRange, testInRange) {
    ASSERT_TRUE(isInRange(3, 1, 7));
}

TEST(testIsInRange, testEqualRangeStop) {
    ASSERT_TRUE(isInRange(5, -2, 5));
}

TEST(testIsInRange, testAboveRange) {
    ASSERT_FALSE(isInRange(10, 5, 7));
}

TEST(testIsInRange, testBelowRangeBoundsEqual) {
    ASSERT_FALSE(isInRange(2, 5, 5));
}

TEST(testIsInRange, testInRangeBoundsEqual) {
    ASSERT_TRUE(isInRange(-2, -2, -2));
}

TEST(testIsInRange, testOverRangeBoudsEqual) {
    ASSERT_FALSE(isInRange(40, 7, 7));
}


#endif