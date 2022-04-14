#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP


#include "../src/node.hpp"
#include <string>
#include <vector>


namespace rpgDialogue {
    class Dialogue {
    private:
        Node* head_;
        Node* current_;
        std::vector<Node> nodes_;

    public:
        Dialogue(std::string headMessage, std::string speaker);

        int getNodeCount();
        int getChoiceCount();
        std::string getMessage();
        std::string getSpeaker();
        std::string printMessage();
        std::vector<std::string> getChoiceMessages();
        std::vector<std::string> printChoiceMessages();
        bool isDone();
        
        int addNode(std::string message, std::string speaker);

        void linkNodes(unsigned nodeIndex0, unsigned nodeIndex1);
        void addTerminalChoice(unsigned nodeIndex);

        void makeChoice(unsigned choiceNo);
        void reset();
    };
}


#endif