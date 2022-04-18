#ifndef NODE_HPP
#define NODE_HPP


#include <vector>
#include <string>
#include <tuple>


namespace rpgDialogue {
    class Node {
    private:
        std::string message_;
        std::string speaker_;
        std::vector<Node*> choices_;
        bool seen_;

    public:
        Node(std::string message, std::string speaker);

        // Message getters:
        std::string getMessage() const;
        std::string getSpeaker() const;
        std::string printMessage() const;

        // Message setters:
        void setMessage(std::string newMessage);
        void setSpeaker(std::string newSpeaker);

        // Choices manipulation:
        void addChoice(Node* nextNode);
        int getChoiceCount() const;
        Node* makeChoice(int choiceNo);
        void clearChoices();

        // Choice messages getters:
        std::vector<std::string> getChoiceMessages() const;
        std::vector<std::string> getChoiceMessagesNumbered() const;
        std::vector<std::string> printChoiceMessages() const;
        std::vector<std::string> printChoiceMessagesNumbered() const;
        // These two are just grabage names
        std::vector<std::tuple<std::string, bool>> getChoiceMessagesAndVisited() const;
        std::vector<std::tuple<std::string, bool>> printChoiceMessagesAndVisited() const;

        // Visited info:
        bool isSeen() const;
        void setSeen(bool newVal);
        std::vector<bool> getNextVisited() const;       // rename asap
    };
}


#endif