#ifndef NODE_HPP
#define NODE_HPP


#include <vector>
#include <string>
#include <tuple>


namespace rpgDialogue {
    const std::string END_MESSAGE = "[END]";

    bool isInRange(int number, int rangeStart, int rangeEnd);

    class Node {
    private:
        std::string message_;
        std::string speaker_;
        std::vector<Node*> choices_;
        bool seen_;
        int respect_gain_;

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
        std::vector<std::tuple<std::string, bool>> getChoicesInfo() const;
        std::vector<std::tuple<std::string, bool>> printChoicesInfo() const;

        // Seen info:
        bool isSeen() const;
        void setSeen(bool newVal);
        std::vector<bool> getChoicesSeen() const;
    };
}


#endif