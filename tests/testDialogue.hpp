#ifndef TEST_DIALOGUE_HPP
#define TEST_DIALOGUE_HPP

#include <gtest/gtest.h>
#include "../src/dialogue.hpp"


using namespace rpgDialogue;


TEST(testDialogue, testConstructor) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    ASSERT_EQ(testDialogue.getNodeCount(), 1);
    ASSERT_EQ(testDialogue.getMessage(), "Head message");
    ASSERT_EQ(testDialogue.getSpeaker(), "speaker");
}


#endif