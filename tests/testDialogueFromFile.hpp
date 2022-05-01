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
    ASSERT_EQ(testDialogue.getRespect(), 11);
    ASSERT_EQ(testDialogue.getInfo(), std::set<int>({1, 2}));
}

TEST(testDialogueFromFile, testMerchant) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/merchant");

    ASSERT_EQ(testDialogue.getNodeCount(), 10);

    // TODO more assertions
}

TEST(testDialogueFromFile, testEmpty) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/empty");
}

TEST(testDialogueFromFile, testJustTerminal) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/justTerminal");
}

// Just head node and terminal choice
// Just head node and space
// Just head node and eof
// No links (2 spaces)
// No terminal choice
// No terminal choice and space


#endif
