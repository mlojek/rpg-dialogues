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


#endif