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

        // Nodes manipulation:
        int addNode(std::string message, std::string speaker);
        int getNodeCount() const;

        // Nodes linking:
        void linkNodes(unsigned nodeIndex0, unsigned nodeIndex1);
        void addTerminalChoice(unsigned nodeIndex);

        // Current message getters:
        std::string getMessage() const;
        std::string getSpeaker() const;
        std::string printMessage() const;

        // Current choices info:
        int getChoiceCount() const;
        std::vector<bool> getChoicesSeen() const;

        // Current choice messages getters:
        std::vector<std::string> getChoiceMessages() const;
        std::vector<std::string> getChoiceMessagesNumbered() const;
        std::vector<std::string> printChoiceMessages() const;
        std::vector<std::string> printChoiceMessagesNumbered() const;
        std::vector<std::tuple<std::string, bool>> getChoicesInfo() const;
        std::vector<std::tuple<std::string, bool>> printChoicesInfo() const;

        // Navigating/playing the dialogue:
        void makeChoice(unsigned choiceNo);
        bool isDone() const;
        void reset();
    };
}


#endif