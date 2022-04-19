#ifndef TEST_DIALOGUE_HPP
#define TEST_DIALOGUE_HPP

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../include/dialogue.hpp"


using namespace rpgDialogue;


TEST(testDialogue, testConstructorDefaults) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    ASSERT_EQ(testDialogue.getNodeCount(), 1);
    ASSERT_EQ(testDialogue.getMessage(), "Head message");
    ASSERT_EQ(testDialogue.getSpeaker(), "speaker");
    ASSERT_EQ(testDialogue.printMessage(), "speaker: Head message");
    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

// Nodes manipulation:
TEST(testDialogue, testAddNodeAndGetNodeCount) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");
    testDialogue.addNode("New message", "new speaker");
    testDialogue.addNode("Other message", "other speaker");

    ASSERT_EQ(testDialogue.getNodeCount(), 3);
}

TEST(testDialogue, testAddNodeAndGetIndex) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");
    ASSERT_EQ(testDialogue.addNode("New message", "new speaker"), 1);
    ASSERT_EQ(testDialogue.addNode("Other message", "other speaker"), 2);
}

// Nodes linking:
TEST(testDialogue, testLinkNodes) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");
    testDialogue.addNode("New message", "new speaker");

    testDialogue.linkNodes(0, 1);

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
}

TEST(testDialogue, testAddTerminalChoice) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    std::vector<std::string> expectedChoiceMessages = {END_MESSAGE};

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
    ASSERT_EQ(testDialogue.getChoiceMessages(), expectedChoiceMessages);
}

// Current message getters:
TEST(testDialogue, testGetMessageCurrentNullptr) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getMessage(), END_MESSAGE);
}

TEST(testDialogue, testGetSpeakerCurrentNullptr) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getSpeaker(), END_MESSAGE);
}

TEST(testDialogue, testPrintMessageCurrentNullptr) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.printMessage(), END_MESSAGE);
}

// Current choices info:
TEST(testDialogue, testGetChoiceCountCurrentNullptr) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

TEST(testDialogue, testGetChoicesSeenCurrentNullptr) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    testDialogue.makeChoice(0);

    std::vector<bool> expected = {};

    ASSERT_EQ(testDialogue.getChoicesSeen(), expected);
}

// Navigating and playing the dialogue:
TEST(testDialogue, testMakeChoice) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");
    testDialogue.addNode("New message", "new speaker");

    testDialogue.linkNodes(0, 1);
    testDialogue.makeChoice(0);

    ASSERT_EQ(testDialogue.getMessage(), "New message");
    ASSERT_EQ(testDialogue.getSpeaker(), "new speaker");
}

TEST(testDialogue, testReset) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");
    testDialogue.addNode("New message", "new speaker");

    testDialogue.linkNodes(0, 1);
    testDialogue.makeChoice(0);     // Current node is now Node 1
    testDialogue.reset();           // Current node is now Node 0 (head)

    ASSERT_EQ(testDialogue.getMessage(), "Head message");
    ASSERT_EQ(testDialogue.getSpeaker(), "speaker");
}

TEST(testDialogue, testIsDone) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    testDialogue.addTerminalChoice(0);
    testDialogue.makeChoice(0);

    ASSERT_TRUE(testDialogue.isDone());
}

TEST(testDialogue, testIsDoneFalse) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    ASSERT_FALSE(testDialogue.isDone());
}


#endif