#include <gtest/gtest.h>

#include "testNode.hpp"
#include "testDialogue.hpp"
#include "testIsInRange.hpp"


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}