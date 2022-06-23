#ifndef TEST_DIALOGUE_FF_HPP
#define TEST_DIALOGUE_FF_HPP


#include <gtest/gtest.h>
#include <stdexcept>
#include "../include/dialogueFromFile.hpp"


using namespace rpgDialogue;


TEST(testDialogueFromFile, testCorrect) {
    Dialogue testDialogue = dialogueFromFile("testFiles/correct");

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
    Dialogue testDialogue = dialogueFromFile("testFiles/correctTrailingLines");

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
    ASSERT_THROW(dialogueFromFile("testFiles/correctSingleIndexInLink"), DialogueFileException);
}

TEST(testDialogueFromFile, testCorrectEmptyFirstLine) {
    ASSERT_THROW(dialogueFromFile("testFiles/correctEmptyFirstLine"), DialogueFileException);
}

TEST(testDialogueFromFile, testCorrectSpaceAfterInt) {
    Dialogue testDialogue = dialogueFromFile("testFiles/correctSpaceAfterInt");

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

TEST(testDialogueFromFile, testCorrectLinkDoubleSpace) {
    Dialogue testDialogue = dialogueFromFile("testFiles/correctLinkDoubleSpace");

    ASSERT_EQ(testDialogue.getNodeCount(), 2);
    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
}

TEST(testDialogueFromFile, testCorrectNegativeNumbers) {
    Dialogue testDialogue = dialogueFromFile("testFiles/correctNegativeNumbers");

    ASSERT_EQ(testDialogue.getNodeCount(), 2);
    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
    ASSERT_EQ(testDialogue.printMessage(), "Head speaker: This is the head node");

    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_TRUE(testDialogue.isDone());
    ASSERT_EQ(testDialogue.getRespect(), -9);
    ASSERT_EQ(testDialogue.getInfo(), std::set<int>({1, -2}));
}

TEST(testDialogueFromFile, testMerchant) {
    Dialogue testDialogue = dialogueFromFile("testFiles/merchant");

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
    ASSERT_THROW(dialogueFromFile("testFiles/empty"), DialogueFileException);
}

TEST(testDialogueFromFile, testNonexistentFile) {
    ASSERT_THROW(dialogueFromFile("testFiles/thisFileDoesNotExist"), DialogueFileException);
}

TEST(testDialogueFromFile, testJustHeadNode) {
    Dialogue testDialogue = dialogueFromFile("testFiles/justHeadNode");

    ASSERT_EQ(testDialogue.getNodeCount(), 1);
    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

TEST(testDialogueFromFile, testJustTerminalChoice) {
    Dialogue testDialogue = dialogueFromFile("testFiles/justTerminalChoice");

    ASSERT_EQ(testDialogue.getNodeCount(), 1);
    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_TRUE(testDialogue.isDone());
}

TEST(testDialogueFromFile, testJustNodes) {
    Dialogue testDialogue = dialogueFromFile("testFiles/justNodes");

    ASSERT_EQ(testDialogue.getNodeCount(), 3);
    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

TEST(testDialogueFromFile, testNoTerminal) {
    Dialogue testDialogue = dialogueFromFile("testFiles/noTerminal");

    ASSERT_EQ(testDialogue.getNodeCount(), 2);
    ASSERT_EQ(testDialogue.getChoiceCount(), 1);

    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
}


#endif
