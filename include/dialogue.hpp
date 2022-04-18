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

        int getNodeCount() const;
        int getChoiceCount() const;
        std::string getMessage() const;
        std::string getSpeaker() const;
        std::string printMessage() const;
        std::vector<std::string> getChoiceMessages() const;
        std::vector<std::string> getChoiceMessagesNumbered() const;
        std::vector<std::string> printChoiceMessages() const;
        std::vector<std::string> printChoiceMessagesNumbered() const;

        std::vector<std::tuple<std::string, bool>> getChoiceMessagesAndVisited() const;
        std::vector<std::tuple<std::string, bool>> printChoiceMessagesAndVisited() const;

        bool isDone() const;

        std::vector<bool> getNextVisited() const;
        
        int addNode(std::string message, std::string speaker);

        void linkNodes(unsigned nodeIndex0, unsigned nodeIndex1);
        void addTerminalChoice(unsigned nodeIndex);

        void makeChoice(unsigned choiceNo);
        void reset();
    };
}


#endif