#ifndef TEST_DIALOGUE_HPP
#define TEST_DIALOGUE_HPP

#include <gtest/gtest.h>
#include "../include/dialogue.hpp"


using namespace rpgDialogue;


TEST(testDialogue, testConstructor) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");

    ASSERT_EQ(testDialogue.getNodeCount(), 1);
    ASSERT_EQ(testDialogue.getMessage(), "Head message");
    ASSERT_EQ(testDialogue.getSpeaker(), "speaker");
    ASSERT_EQ(testDialogue.printMessage(), "speaker: Head message");
    ASSERT_EQ(testDialogue.getChoiceCount(), 0);
}

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

TEST(testDialogue, testLinkNodes) {
    Dialogue testDialogue = Dialogue("Head message", "speaker");
    testDialogue.addNode("New message", "new speaker");

    testDialogue.linkNodes(0, 1);

    ASSERT_EQ(testDialogue.getChoiceCount(), 1);
}


#endif