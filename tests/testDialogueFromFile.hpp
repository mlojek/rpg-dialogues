#ifndef TEST_DIALOGUE_FF_HPP
#define TEST_DIALOGUE_FF_HPP


#include <gtest/gtest.h>
#include "../include/dialogueFromFile.hpp"


using namespace rpgDialogue;


TEST(testDialogueFromFile, testCorrect) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/correct");

    ASSERT_EQ(testDialogue.getNodeCount(), 2);
    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
    ASSERT_EQ(testDialogue.printMessage(), "Head speaker: This is the head node");

    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_TRUE(testDialogue.isDone());
}


#endif
