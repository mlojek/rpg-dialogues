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

        std::string getMessage();
        std::string getSpeaker();
        int getChoiceCount();
        Node* getNext(int choiceNo);
        std::vector<std::string> getChoiceMessages();

        std::string printMessage();
        std::vector<std::string> printChoiceMessages();

        void setMessage(std::string newMessage);
        void setSpeaker(std::string newSpeaker);
        void addChoice(Node* nextNode);

        void resetChoices();
    };
}


#endif