#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include "../../include/dialogue.hpp"


using namespace rpgDialogue;


int main() {
    Dialogue merchantDialogue("Welcome to my humble shop, traveller!", "Merchant");
    int choice;

    merchantDialogue.addNode("How can I help you today?", "Merchant");
    merchantDialogue.addNode("What's the closest city?", "You");
    merchantDialogue.addNode("Show me your wares.", "You");
    merchantDialogue.addNode("What do you know about Count D'Monte?", "You");
    merchantDialogue.addNode("See you around.", "You");
    merchantDialogue.addNode("May the gods bless you in your journey", "Merchant");
    merchantDialogue.addNode("Konsk lies just a few hours west.", "Merchant");
    merchantDialogue.addNode("He's the local lord. Some think he was involved in the massacres on the elves, but that's just a rumour", "Merchant");
    merchantDialogue.addNode("I'm sadly out of stock. Come tomorrow, I'll have something special for you for sure.", "Merchant");

    merchantDialogue.linkNodes(0, 1);
    merchantDialogue.linkNodes(1, 2);
    merchantDialogue.linkNodes(2, 7);
    merchantDialogue.linkNodes(7, 1);
    merchantDialogue.linkNodes(1, 3);
    merchantDialogue.linkNodes(3, 9);
    merchantDialogue.linkNodes(9, 1);
    merchantDialogue.linkNodes(1, 4);
    merchantDialogue.linkNodes(4, 8);
    merchantDialogue.linkNodes(8, 1);
    merchantDialogue.linkNodes(1, 5);
    merchantDialogue.linkNodes(5, 6);

    merchantDialogue.addTerminalChoice(6);

    

    merchantDialogue.reset();
    std::string a("hello world");
    std::cout << a.max_size() << std::endl;
    std::cout << merchantDialogue.printMessage() << std::endl;

    // while (!merchantDialogue.isDone()) {
    //     std::cout << "checkpoint1" << std::endl;
    //     std::cout << merchantDialogue.getNodeCount() << std::endl;
    //     std::cout << merchantDialogue.getMessage() << std::endl;

    //     if (merchantDialogue.getChoiceCount() > 1) {
    //         for (auto line : merchantDialogue.getChoiceMessages()) {
    //             std::cout << line << std::endl;
    //         }

    //         std::cin >> choice;
    //         merchantDialogue.makeChoice(choice); 
    //     }
    //     else {
    //         merchantDialogue.makeChoice(0);
    //     }
    // }

    std::cout << "Hello world!" << std::endl;
    return 0;
}