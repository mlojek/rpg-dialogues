#ifndef TEST_DIALOGUE_ISVALID
#define TEST_DIALOGUE_ISVALID


#include <gtest/gtest.h>
#include "../include/dialogue.hpp"
#include "../include/dialogueFromFile.hpp"


using namespace rpgDialogue;


TEST(testDialogueIsValid, testMerchant) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/merchant");

    ASSERT_TRUE(testDialogue.isValid());
}

// Every node has to have at least one choice
TEST(testDialogueIsValid, testJustOneNode) {
    Dialogue testDialogue("Head message", "Head speaker");

    ASSERT_FALSE(testDialogue.isValid());
}

// There has to be a way to get to nullptr from head
TEST(testDialogueIsValid, testJustOneNodeAndEnd) {
    Dialogue testDialogue("Head message", "Head speaker");

    testDialogue.addTerminalChoice(0);

    ASSERT_TRUE(testDialogue.isValid());
}

// Every node has to be accessible from the head



TEST(testDialogueIsValid, testLoop) {
    Dialogue testDialogue("Head message", "Head speaker");
    testDialogue.addNode("Message1", "speaker1");
    testDialogue.addNode("Message2", "speaker2");
    
    testDialogue.linkNodes(0, 1);
    testDialogue.linkNodes(1, 2);
    testDialogue.linkNodes(2, 0);
    
    ASSERT_FALSE(testDialogue.isValid());
}

TEST(testDialogueIsValid, testOrphanedNode) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/merchant");

    ASSERT_TRUE(testDialogue.isValid());

    testDialogue.addNode("orphan message", "orphan speaker");

    ASSERT_FALSE(testDialogue.isValid());
}

TEST(testDialogueIsValid, testOrphanedNodeLinked) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/merchant");

    ASSERT_TRUE(testDialogue.isValid());

    unsigned orphanIndex = testDialogue.addNode("orphan message", "orphan speaker");
    testDialogue.linkNodes(orphanIndex, 2);

    ASSERT_FALSE(testDialogue.isValid());
}

TEST(testDialogueIsValid, testOrphanedNodeWithEnd) {
    Dialogue testDialogue = dialogueFromFile("tests/testFiles/merchant");

    ASSERT_TRUE(testDialogue.isValid());

    unsigned orphanIndex = testDialogue.addNode("orphan message", "orphan speaker");
    testDialogue.addTerminalChoice(orphanIndex);

    ASSERT_FALSE(testDialogue.isValid());
}

TEST(testDialogueIsValid, testEndUnreachable) {
    Dialogue testDialogue("Head message", "Head speaker");
    testDialogue.addNode("Message1", "speaker1");
    testDialogue.addNode("Message2", "speaker2");
    testDialogue.addNode("End node", "speaker 3");
    
    testDialogue.linkNodes(0, 1);
    testDialogue.linkNodes(1, 2);
    testDialogue.linkNodes(2, 0);

    testDialogue.addTerminalChoice(3);
    
    ASSERT_FALSE(testDialogue.isValid());
}




#endif