#ifndef NODE_HPP
#define NODE_HPP


#include <vector>
#include <string>


namespace rpgDialogue {
    class Node {
    private:
        std::string message_;
        std::string speaker_;
        std::vector<Node*> nextNodes_;

    public:
        Node(std::string message, std::string speaker);

        std::string getMessage() const;
        std::string getSpeaker() const;
        int getChoiceCount() const;
        Node* getNext(int choiceNo);
        std::vector<std::string> getChoiceMessages() const;
        std::vector<std::string> getChoiceMessagesNumbered() const;

        std::string printMessage() const;
        std::vector<std::string> printChoiceMessages() const;
        std::vector<std::string> printChoiceMessagesNumbered() const;

        void setMessage(std::string newMessage);
        void setSpeaker(std::string newSpeaker);
        void addChoice(Node* nextNode);

        void resetChoices();
    };
}


#endif