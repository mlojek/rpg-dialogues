#include "node.hpp"
#include <cstddef>
#include <string>
#include <tuple>
#include <vector>


namespace rpgDialogue {
    Node::Node(std::string message, std::string speaker) : message_(message), speaker_(speaker), visited_(false) {}

    std::string Node::getMessage() const {
        return message_;
    }

    std::string Node::getSpeaker() const {
        return speaker_;
    }

    std::string Node::printMessage() const {
        return speaker_ + ": " + message_;
    }

    int Node::getChoiceCount() const {
        return nextNodes_.size();
    }

    Node* Node::getNext(int choiceNo) {
        if (choiceNo >= nextNodes_.size() || choiceNo < 0)
            return this;
        else
            return nextNodes_[choiceNo];
    }

    bool Node::isVisited() const {
        return visited_;
    }

    std::vector<bool> Node::getNextVisited() const {
        std::vector<bool> result;

        for (Node* nextNode : nextNodes_) {
            result.push_back(nextNode->isVisited());
        }

        return result;
    }

    std::vector<std::string> Node::getChoiceMessages() const {
        std::vector<std::string> result;

        for (auto choice : nextNodes_) {
            if (choice == nullptr)
                result.push_back("[END]");
            else
                result.push_back(choice->getMessage());
        }

        return result;
    }

    std::vector<std::string> Node::getChoiceMessagesNumbered() const {
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

    std::vector<std::string> Node::printChoiceMessages() const {
        std::vector<std::string> result;

        for (auto choice : nextNodes_) {
            if (choice == nullptr)
                result.push_back("[END]");
            else
                result.push_back(choice->printMessage());
        }

        return result;
    }

    std::vector<std::string> Node::printChoiceMessagesNumbered() const {
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

    std::vector<std::tuple<std::string, bool>> Node::getChoiceMessagesAndVisited() const {
        std::vector<std::tuple<std::string, bool>> result;

        for (Node* nextNode : nextNodes_) {
            result.push_back({nextNode->getMessage(), nextNode->isVisited()});
        }

        return result;
    }

    std::vector<std::tuple<std::string, bool>> Node::printChoiceMessagesAndVisited() const {
        std::vector<std::tuple<std::string, bool>> result;

        for (Node* nextNode : nextNodes_) {
            result.push_back({nextNode->printMessage(), nextNode->isVisited()});
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

    void Node::setVisited(bool newVal) {
        visited_ = newVal;
    }

    void Node::resetChoices() {
        nextNodes_.clear();
    }
}