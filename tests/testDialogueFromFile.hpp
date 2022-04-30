#ifndef TEST_DIALOGUE_FF_HPP
#define TEST_DIALOGUE_FF_HPP


#include <gtest/gtest.h>
#include "../include/dialogueFromFile.hpp"


using namespace rpgDialogue;


TEST(testDialogueFromFile, testCorrect) {
    Dialogue testDialogue = dialogueFromFile("testFiles/correct");

    ASSERT_EQ(testDialogue.getNodeCount(), 2);
}


#endif
