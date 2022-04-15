#include "node.hpp"
#include <cstddef>
#include <vector>


namespace rpgDialogue {
    Node::Node(std::string message, std::string speaker) : message_(message), speaker_(speaker) {}

    std::string Node::getMessage() {
        return message_;
    }

    std::string Node::getSpeaker() {
        return speaker_;
    }

    int Node::getChoiceCount() {
        return nextNodes_.size();
    }

    Node* Node::getNext(int choiceNo) {
        if (choiceNo >= nextNodes_.size() || choiceNo < 0)
            return this;
        else
            return nextNodes_[choiceNo];
    }

    std::vector<std::string> Node::getChoiceMessages() {
        std::vector<std::string> result;

        for (auto choice : nextNodes_) {
            if (choice == nullptr)
                result.push_back("[END]");
            else
                result.push_back(choice->getMessage());
        }

        return result;
    }

    std::vector<std::string> Node::getChoiceMessagesNumbered() {
        std::vector<std::string> result;
        int iter = 0;

        for (auto choice : nextNodes_) {
            if (choice == nullptr)
                result.push_back(std::to_string(iter) + ") [END]");
            else
                result.push_back(std::to_string(iter) + ") " + choice->getMessage());

            iter++;
        }

        return result;
    }

    std::string Node::printMessage() {
        return speaker_ + ": " + message_;
    }

    std::vector<std::string> Node::printChoiceMessages() {
        std::vector<std::string> result;

        for (auto choice : nextNodes_) {
            if (choice == nullptr)
                result.push_back("[END]");
            else
                result.push_back(choice->printMessage());
        }

        return result;
    }

    std::vector<std::string> Node::printChoiceMessagesNumbered() {
        std::vector<std::string> result;
        int iter = 0;

        for (auto choice : nextNodes_) {
            if (choice == nullptr)
                result.push_back(std::to_string(iter) + ") [END]");
            else
                result.push_back(std::to_string(iter) + ") " + choice->printMessage());

            iter++;
        }

        return result;
    }

    void Node::setMessage(std::string newMessage) {
        message_ = newMessage;
    }

    void Node::setSpeaker(std::string newSpeaker) {
        speaker_ = newSpeaker;
    }

    void Node::addChoice(Node* nextNode) {
        nextNodes_.push_back(nextNode);
    }

    void Node::resetChoices() {
        nextNodes_.clear();
    }
}