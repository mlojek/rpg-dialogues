#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

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

#endif