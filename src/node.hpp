#ifndef NODE_HPP
#define NODE_HPP


#include <vector>
#include <string>
#include <tuple>


namespace rpgDialogue {
    // class Node {
    // private:
    //     std::string m_message;
    //     std::string m_speaker;
    //     std::vector<Node*> m_choices;
    //     bool m_seen;
    //     int m_respectGain;
    //     int m_infoGain;

    // public:
    //     Node(std::string message, std::string speaker, int respectGain = 0, int infoGain = 0);

    //     // Message getters:
    //     std::string getMessage() const;
    //     std::string getSpeaker() const;
    //     std::string printMessage() const;

    //     // Message setters:
    //     void setMessage(std::string newMessage);
    //     void setSpeaker(std::string newSpeaker);

    //     // Choices manipulation:
    //     void addChoice(Node* nextNode);
    //     int getChoiceCount() const;
    //     Node* makeChoice(int choiceNo);
    //     void clearChoices();

    //     // Choice messages getters:
    //     std::vector<std::string> getChoiceMessages() const;
    //     std::vector<std::string> getChoiceMessagesNumbered() const;
    //     std::vector<std::string> printChoiceMessages() const;
    //     std::vector<std::string> printChoiceMessagesNumbered() const;
    //     std::vector<std::tuple<std::string, bool>> getChoicesInfo() const;
    //     std::vector<std::tuple<std::string, bool>> printChoicesInfo() const;

    //     // Seen info:
    //     bool isSeen() const;
    //     void setSeen(bool newVal);
    //     std::vector<bool> getChoicesSeen() const;

    //     // Respect gain:
    //     void setRespectGain(int newVal);
    //     int getRespectGain() const;

    //     // Info gain:
    //     void setInfoGain(int newVal);
    //     int getInfoGain() const;
    // };
}


#endif