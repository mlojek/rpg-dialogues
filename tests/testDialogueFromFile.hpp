#ifndef TEST_DIALOGUE_FF_HPP
#define TEST_DIALOGUE_FF_HPP


#include <gtest/gtest.h>
#include <stdexcept>
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

TEST(testDialogueFromFile, testCorrectTrailingLines) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/correctTrailingLines");

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

TEST(testDialogueFromFile, testCorrectSingleIndexInLink) {
    ASSERT_THROW(dialogueFromFile("tests/testFiles/correctSingleIndexInLink"), DialogueFileException);
}


TEST(testDialogueFromFile, testMerchant) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/merchant");

    ASSERT_EQ(testDialogue.getNodeCount(), 10);
    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getChoiceCount(), 4);

    testDialogue.makeChoice(3);
    testDialogue.makeChoice(0);
    testDialogue.makeChoice(0);

    ASSERT_TRUE(testDialogue.isDone());
}

TEST(testDialogueFromFile, testEmptyFile) {
    ASSERT_THROW(dialogueFromFile("tests/testFiles/empty"), DialogueFileException);
}

TEST(testDialogueFromFile, testNonexistentFile) {
    ASSERT_THROW(dialogueFromFile("tests/testFiles/thisFileDoesNotExist"), DialogueFileException);
}

TEST(testDialogueFromFile, testJustHeadNode) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/justHeadNode");

    ASSERT_EQ(testDialogue.getNodeCount(), 1);
    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

TEST(testDialogueFromFile, testJustTerminalChoice) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/justTerminalChoice");

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_TRUE(testDialogue.isDone());
}

TEST(testDialogueFromFile, testJustNodes) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/justNodes");

    ASSERT_EQ(testDialogue.getNodeCount(), 3);
    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

TEST(testDialogueFromFile, testNoTerminal) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/noTerminal");
}

TEST(testDialogueFromFile, testNoTerminalAndNewline) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/noTerminalAndNewline");
}

// Just head node and spaces
// No terminal choice
// No terminal choice and space


#endif
