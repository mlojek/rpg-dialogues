#include "node.hpp"
#include <cstddef>
#include <string>
#include <tuple>
#include <vector>


namespace rpgDialogue {
    bool isInRange(int number, int rangeStart, int rangeEnd) {
        return rangeEnd >= rangeStart && number >= rangeStart && number <= rangeEnd;
    }

    // Node::Node(std::string message, std::string speaker, int respectGain, int infoGain)
    //     : m_message(message), m_speaker(speaker), m_respectGain(respectGain), m_seen(false), m_infoGain(infoGain) {}

    // // Message getters:
    // std::string Node::getMessage() const {
    //     return m_message;
    // }

    // std::string Node::getSpeaker() const {
    //     return m_speaker;
    // }

    // std::string Node::printMessage() const {
    //     return m_speaker + ": " + m_message;
    // }

    // // Message setters:
    // void Node::setMessage(std::string newMessage) {
    //     m_message = newMessage;
    // }

    // void Node::setSpeaker(std::string newSpeaker) {
    //     m_speaker = newSpeaker;
    // }

    // // Choices manipulation:
    // void Node::addChoice(Node* nextNode) {
    //     if (nextNode != this)
    //         m_choices.push_back(nextNode);
    // }

    // int Node::getChoiceCount() const {
    //     return m_choices.size();
    // }

    // Node* Node::makeChoice(int choiceNo) {
    //     if (isInRange(choiceNo, 0, m_choices.size() - 1))
    //         return m_choices[choiceNo];
    //     else
    //         return this;
    // }

    // void Node::clearChoices() {
    //     m_choices.clear();
    // }

    // // Choice messages getters:
    // std::vector<std::string> Node::getChoiceMessages() const {
    //     std::vector<std::string> result;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr)
    //             result.push_back(END_MESSAGE);
    //         else
    //             result.push_back(choice->getMessage());
    //     }

    //     return result;
    // }

    // std::vector<std::string> Node::getChoiceMessagesNumbered() const {
    //     std::vector<std::string> result;
    //     int index = 0;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr)
    //             result.push_back(std::to_string(index) + ") " + END_MESSAGE);
    //         else
    //             result.push_back(std::to_string(index) + ") " + choice->getMessage());

    //         index++;
    //     }

    //     return result;
    // }

    // std::vector<std::string> Node::printChoiceMessages() const {
    //     std::vector<std::string> result;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr)
    //             result.push_back(END_MESSAGE);
    //         else
    //             result.push_back(choice->printMessage());
    //     }

    //     return result;
    // }

    // std::vector<std::string> Node::printChoiceMessagesNumbered() const {
    //     std::vector<std::string> result;
    //     int index = 0;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr)
    //             result.push_back(std::to_string(index) + ") " + END_MESSAGE);
    //         else
    //             result.push_back(std::to_string(index) + ") " + choice->printMessage());

    //         index++;
    //     }

    //     return result;
    // }

    // std::vector<std::tuple<std::string, bool>> Node::getChoicesInfo() const {
    //     std::vector<std::tuple<std::string, bool>> result;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr) {
    //             result.push_back({END_MESSAGE, false});
    //         }
    //         else {
    //             result.push_back({choice->getMessage(), choice->isSeen()});
    //         }
    //     }

    //     return result;
    // }

    // std::vector<std::tuple<std::string, bool>> Node::printChoicesInfo() const {
    //     std::vector<std::tuple<std::string, bool>> result;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr) {
    //             result.push_back({END_MESSAGE, false});
    //         }
    //         else {
    //             result.push_back({choice->printMessage(), choice->isSeen()});
    //         }
    //     }

    //     return result;
    // }

    // // Seen info:
    // bool Node::isSeen() const {
    //     return m_seen;
    // }

    // void Node::setSeen(bool newVal) {
    //     m_seen = newVal;
    // }

    // std::vector<bool> Node::getChoicesSeen() const {
    //     std::vector<bool> result;

    //     for (Node* choice : m_choices) {
    //         if (choice == nullptr) {
    //             result.push_back(false);
    //         }
    //         else {
    //             result.push_back(choice->isSeen());
    //         }
    //     }

    //     return result;
    // }

    // // Respect gain:
    // void Node::setRespectGain(int newVal) {
    //     m_respectGain = newVal;
    // }

    // int Node::getRespectGain() const {
    //     return m_respectGain;
    // }

    // // Info gain:
    // void Node::setInfoGain(int newVal) {
    //     m_infoGain = newVal;
    // }

    // int Node::getInfoGain() const {
    //     return m_infoGain;
    // }
}