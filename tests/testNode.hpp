#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

#include <cstddef>
#include <gtest/gtest.h>
#include <vector>
#include "../src/node.hpp"


using namespace rpgDialogue;

TEST(testNode, testConstructorDefaults) {       
    Node testNode = Node("Node message.", "Node speaker");

    ASSERT_EQ(testNode.getMessage(), "Node message.");
    ASSERT_EQ(testNode.getSpeaker(), "Node speaker");
    ASSERT_EQ(testNode.getChoiceCount(), 0);
    ASSERT_EQ(testNode.isSeen(), false);
}

// Message getters:
TEST(testNode, testPrintMessage) {
    Node testNode = Node("message", "speaker");

    ASSERT_EQ(testNode.printMessage(), "speaker: message");
}

// Message setters:
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

// Choices manipulation:
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

TEST(testNode, testAddChoiceItself) {
    Node testNode = Node("message", "speaker");

    testNode.addChoice(&testNode);

    ASSERT_EQ(testNode.getChoiceCount(), 0);
}

TEST(testNode, testMakeChoice) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.makeChoice(1), &choiceNode1);
}

TEST(testNode, testMakeChoiceNoChoices) {
    Node testNode = Node("message", "speaker");

    ASSERT_EQ(testNode.makeChoice(0), &testNode);
}

TEST(testNode, testMakeChoiceOutOfRange) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.makeChoice(3), &testNode);
}

TEST(testNode, testMakeChoiceNegativeIndex) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    ASSERT_EQ(testNode.makeChoice(-4), &testNode);
}

TEST(testNode, testMakeChoiceTerminalChoice) {
    Node testNode = Node("message", "speaker");

    testNode.addChoice(nullptr);

    ASSERT_EQ(testNode.makeChoice(0), nullptr);
}

TEST(testNode, testClearChoices) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    testNode.clearChoices();

    ASSERT_EQ(testNode.getChoiceCount(), 0);
}

// Choice messages getters:
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

TEST(testNode, testGetChoiceMessagesEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.getChoiceMessages(), expected);
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

    std::vector<std::string> expected = {"yes", "no", "maybe", END_MESSAGE};

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

TEST(testNode, testGetChoiceMessagesNumberedEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.getChoiceMessagesNumbered(), expected);
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

    std::vector<std::string> expected = {"0) yes", "1) no", "2) maybe", "3) " + END_MESSAGE};

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

TEST(testNode, testPrintChoiceMessagesEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.printChoiceMessages(), expected);
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

    std::vector<std::string> expected = {"sneaker: yes", "you: no", "idk: maybe", END_MESSAGE};

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

TEST(testNode, testPrintChoiceMessagesNumberedEmpty) {
    Node testNode = Node("message", "speaker");

    std::vector<std::string> expected = {};

    ASSERT_EQ(testNode.printChoiceMessagesNumbered(), expected);
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

    std::vector<std::string> expected = {"0) sneaker: yes", "1) you: no", "2) idk: maybe", "3) " + END_MESSAGE};

    ASSERT_EQ(testNode.printChoiceMessagesNumbered(), expected);
}

TEST(testNode, testGetChoicesInfo) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "sneaker");
    Node choiceNode1 = Node("no", "you");
    Node choiceNode2 = Node("maybe", "idk");

    choiceNode1.setSeen(true);

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<std::tuple<std::string, bool>> expected = {{"yes", false}, 
                                                           {"no", true},
                                                           {"maybe", false},
                                                           {END_MESSAGE, false}};

    ASSERT_EQ(testNode.getChoicesInfo(), expected);
}

TEST(testNode, testPrintChoicesInfo) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("yes", "sneaker");
    Node choiceNode1 = Node("no", "you");
    Node choiceNode2 = Node("maybe", "idk");

    choiceNode1.setSeen(true);

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<std::tuple<std::string, bool>> expected = {{"sneaker: yes", false}, 
                                                           {"you: no", true},
                                                           {"idk: maybe", false},
                                                           {END_MESSAGE, false}};

    ASSERT_EQ(testNode.printChoicesInfo(), expected);
}

// Seen info:
TEST(testNode, testSetVisited) {
    Node testNode = Node("message", "speaker");

    testNode.setSeen(true);

    ASSERT_EQ(testNode.isSeen(), true);
}

TEST(testNode, testGetChoicesSeen) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);

    choiceNode1.setSeen(true);
    choiceNode2.setSeen(true);

    std::vector<bool> expected = {false, true, true};

    ASSERT_EQ(testNode.getChoicesSeen(), expected);
}

TEST(testNode, testGetChoicesSeenDefault) {
    Node testNode = Node("message", "speaker");
    Node choiceNode0 = Node("message", "speaker");
    Node choiceNode1 = Node("message", "speaker");
    Node choiceNode2 = Node("message", "speaker");

    testNode.addChoice(&choiceNode0);
    testNode.addChoice(&choiceNode1);
    testNode.addChoice(&choiceNode2);
    testNode.addChoice(nullptr);

    std::vector<bool> expected = {false, false, false, false};

    ASSERT_EQ(testNode.getChoicesSeen(), expected);
}


#endif