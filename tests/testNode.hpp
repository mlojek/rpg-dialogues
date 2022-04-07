#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

#include <cstddef>
#include <gtest/gtest.h>
#include "../src/node.hpp"


TEST(testNode, testConstructor) {
    Node testNode = Node("Node message.", "Node speaker");

    ASSERT_EQ(testNode.getMessage(), "Node message.");
    ASSERT_EQ(testNode.getSpeaker(), "Node speaker");
    ASSERT_EQ(testNode.getChoiceCount(), 0);
}

TEST(testNode, testSetMessage) {
    Node testNode = Node("message", "speaker");

    testNode.setMessage("new message");

    ASSERT_EQ(testNode.getMessage(), "new message");
}

TEST(testNode, testSetSpeaker) {
    Node testNode = Node("message", "speaker");

    testNode.setSpeaker("new speaker");

    ASSERT_EQ(testNode.getSpeaker(), "new speaker");
}

TEST(testNode, testPrintMessage) {
    Node testNode = Node("message", "speaker");

    ASSERT_EQ(testNode.printMessage(), "speaker: message");
}

TEST(testNode, testAddChoice) {
    Node testNode = Node("message", "speaker");
    Node choiceNode = Node("message", "speaker");

    testNode.addChoice(&choiceNode);

    ASSERT_EQ(testNode.getChoiceCount(), 1);
}

TEST(testNode, testAddThreeChoices) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.getChoiceCount(), 3);
}

TEST(testNode, testResetChoices) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    testNode.resetChoices();

    ASSERT_EQ(testNode.getChoiceCount(), 0);
}

TEST(testNode, testGetNext) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.getNext(0), &choiceNode0);
}

TEST(testNode, testGetNextNoChoices) {
    Node testNode = Node("message", "speaker");

    ASSERT_EQ(testNode.getNext(0), nullptr);
}

TEST(testNode, testGetNextOutOfRange) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.getNext(3), nullptr);
}

TEST(testNode, testGetNextNegativeIndex) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.getNext(-1), nullptr);
}

#endif