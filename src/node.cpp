#include "node.hpp"
#include <cstddef>
#include <string>
#include <tuple>
#include <vector>


namespace rpgDialogue {
    Node::Node(std::string message, std::string speaker) : message_(message), speaker_(speaker), seen_(false) {}

    // Message getters:
    std::string Node::getMessage() const {
        return message_;
    }

    std::string Node::getSpeaker() const {
        return speaker_;
    }

    std::string Node::printMessage() const {
        return speaker_ + ": " + message_;
    }

    // Message setters:
    void Node::setMessage(std::string newMessage) {
        message_ = newMessage;
    }

    void Node::setSpeaker(std::string newSpeaker) {
        speaker_ = newSpeaker;
    }

    // Choices manipulation:
    void Node::addChoice(Node* nextNode) {
        choices_.push_back(nextNode);
    }

    int Node::getChoiceCount() const {
        return choices_.size();
    }

    Node* Node::makeChoice(int choiceNo) {
        if (choiceNo >= choices_.size() || choiceNo < 0)
            return this;
        else
            return choices_[choiceNo];
    }

    void Node::clearChoices() {
        choices_.clear();
    }

    // Choice messages getters:
    std::vector<std::string> Node::getChoiceMessages() const {
        std::vector<std::string> result;

        for (auto choice : choices_) {
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

        for (auto choice : choices_) {
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

        for (auto choice : choices_) {
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

        for (auto choice : choices_) {
            if (choice == nullptr)
                result.push_back(std::to_string(iter) + ") [END]");
            else
                result.push_back(std::to_string(iter) + ") " + choice->printMessage());

            iter++;
        }

        return result;
    }

    std::vector<std::tuple<std::string, bool>> Node::getChoicesInfo() const {
        std::vector<std::tuple<std::string, bool>> result;

        for (Node* nextNode : choices_) {
            if (nextNode == nullptr) {
                result.push_back({"[END]", false});
            }
            else {
                result.push_back({nextNode->getMessage(), nextNode->isSeen()});
            }
        }

        return result;
    }

    std::vector<std::tuple<std::string, bool>> Node::printChoicesInfo() const {
        std::vector<std::tuple<std::string, bool>> result;

        for (Node* nextNode : choices_) {
            if (nextNode == nullptr) {
                result.push_back({"[END]", false});
            }
            else {
                result.push_back({nextNode->printMessage(), nextNode->isSeen()});
            }
        }

        return result;
    }

    // Seen info:
    bool Node::isSeen() const {
        return seen_;
    }

    void Node::setSeen(bool newVal) {
        seen_ = newVal;
    }

    std::vector<bool> Node::getChoicesSeen() const {
        std::vector<bool> result;

        for (Node* nextNode : choices_) {
            result.push_back(nextNode->isSeen());
        }

        return result;
    }
}