#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

#include "../../include/dialogue.hpp"
#include "../../include/dialogueFromFile.hpp"


using namespace rpgDialogue;


int main() {
    Dialogue merchantDialogue = dialogueFromFile("merchant");
    int choice;

    while (!merchantDialogue.isDone()) {
        std::cout << merchantDialogue.printMessage() << std::endl;

        if (merchantDialogue.getChoiceCount() > 1) {
            auto choices = merchantDialogue.printChoiceMessages();
            for (int i = 0; i < choices.size(); i++) {
                std::cout << i << ") " << choices[i] << std::endl;
            }

            std::cin >> choice;
            merchantDialogue.makeChoice(choice); 
        }
        else {
            merchantDialogue.makeChoice(0);
        }
    }

    return 0;
}