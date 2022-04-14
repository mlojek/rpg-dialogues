#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
#include "../src/node.hpp"


using namespace rpgDialogue;


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

TEST(testNode, testGetChoiceMessages) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "speaker");
    Node choiceNode1 = Node("no", "speaker");
    Node choiceNode2 = Node("maybe", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    std::vector<std::string> expected = {"yes", "no", "maybe"};

    ASSERT_EQ(testNode.getChoiceMessages(), expected);
}

TEST(testNode, testGetChoiceMessagesNumbered) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "speaker");
    Node choiceNode1 = Node("no", "speaker");
    Node choiceNode2 = Node("maybe", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    std::vector<std::string> expected = {"0) yes", "1) no", "2) maybe"};

    ASSERT_EQ(testNode.getChoiceMessagesNumbered(), expected);
}

TEST(testNode, testGetChoiceMessagesEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.getChoiceMessages(), expected);
}

TEST(testNode, testGetChoiceMessagesNumberedEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.getChoiceMessagesNumbered(), expected);
}

TEST(testNode, testGetChoiceMessagesEnd) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "speaker");
    Node choiceNode1 = Node("no", "speaker");
    Node choiceNode2 = Node("maybe", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<std::string> expected = {"yes", "no", "maybe", "[END]"};

    ASSERT_EQ(testNode.getChoiceMessages(), expected);
}

TEST(testNode, testGetChoiceMessagesNumberedEnd) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "speaker");
    Node choiceNode1 = Node("no", "speaker");
    Node choiceNode2 = Node("maybe", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<std::string> expected = {"0) yes", "1) no", "2) maybe", "3) [END]"};

    ASSERT_EQ(testNode.getChoiceMessagesNumbered(), expected);
}

TEST(testNode, testPrintChoiceMessages) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "sneaker");
    Node choiceNode1 = Node("no", "you");
    Node choiceNode2 = Node("maybe", "idk");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    std::vector<std::string> expected = {"sneaker: yes", "you: no", "idk: maybe"};

    ASSERT_EQ(testNode.printChoiceMessages(), expected);
}

TEST(testNode, testPrintChoiceMessagesNumbered) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "sneaker");
    Node choiceNode1 = Node("no", "you");
    Node choiceNode2 = Node("maybe", "idk");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    std::vector<std::string> expected = {"0) sneaker: yes", "1) you: no", "2) idk: maybe"};

    ASSERT_EQ(testNode.printChoiceMessagesNumbered(), expected);
}

TEST(testNode, testPrintChoiceMessagesEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.printChoiceMessages(), expected);
}

TEST(testNode, testPrintChoiceMessagesNumberedEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.printChoiceMessagesNumbered(), expected);
}

TEST(testNode, testPrintChoiceMessagesEnd) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "sneaker");
    Node choiceNode1 = Node("no", "you");
    Node choiceNode2 = Node("maybe", "idk");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<std::string> expected = {"sneaker: yes", "you: no", "idk: maybe", "[END]"};

    ASSERT_EQ(testNode.printChoiceMessages(), expected);
}

TEST(testNode, testPrintChoiceMessagesNumberedEnd) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "sneaker");
    Node choiceNode1 = Node("no", "you");
    Node choiceNode2 = Node("maybe", "idk");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<std::string> expected = {"0) sneaker: yes", "1) you: no", "2) idk: maybe", "3) [END]"};

    ASSERT_EQ(testNode.printChoiceMessagesNumbered(), expected);
}

#endif