#include "node.hpp"
#include <cstddef>
#include <string>
#include <tuple>
#include <vector>


namespace rpgDialogue {
    bool isInRange(int number, int rangeStart, int rangeEnd) {
        return rangeEnd >= rangeStart && number >= rangeStart && number <= rangeEnd;
    }

    Node::Node(std::string message, std::string speaker, int respectGain) : message_(message), speaker_(speaker), respectGain_(respectGain), seen_(false) {}

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
        if (nextNode != this)
            choices_.push_back(nextNode);
    }

    int Node::getChoiceCount() const {
        return choices_.size();
    }

    Node* Node::makeChoice(int choiceNo) {
        if (isInRange(choiceNo, 0, choices_.size() - 1))
            return choices_[choiceNo];
        else
            return this;
    }

    void Node::clearChoices() {
        choices_.clear();
    }

    // Choice messages getters:
    std::vector<std::string> Node::getChoiceMessages() const {
        std::vector<std::string> result;

        for (auto choice : choices_) {
            if (choice == nullptr)
                result.push_back(END_MESSAGE);
            else
                result.push_back(choice->getMessage());
        }

        return result;
    }

    std::vector<std::string> Node::getChoiceMessagesNumbered() const {
        std::vector<std::string> result;
        int index = 0;

        for (auto choice : choices_) {
            if (choice == nullptr)
                result.push_back(std::to_string(index) + ") " + END_MESSAGE);
            else
                result.push_back(std::to_string(index) + ") " + choice->getMessage());

            index++;
        }

        return result;
    }

    std::vector<std::string> Node::printChoiceMessages() const {
        std::vector<std::string> result;

        for (auto choice : choices_) {
            if (choice == nullptr)
                result.push_back(END_MESSAGE);
            else
                result.push_back(choice->printMessage());
        }

        return result;
    }

    std::vector<std::string> Node::printChoiceMessagesNumbered() const {
        std::vector<std::string> result;
        int index = 0;

        for (auto choice : choices_) {
            if (choice == nullptr)
                result.push_back(std::to_string(index) + ") " + END_MESSAGE);
            else
                result.push_back(std::to_string(index) + ") " + choice->printMessage());

            index++;
        }

        return result;
    }

    std::vector<std::tuple<std::string, bool>> Node::getChoicesInfo() const {
        std::vector<std::tuple<std::string, bool>> result;

        for (auto choice : choices_) {
            if (choice == nullptr) {
                result.push_back({END_MESSAGE, false});
            }
            else {
                result.push_back({choice->getMessage(), choice->isSeen()});
            }
        }

        return result;
    }

    std::vector<std::tuple<std::string, bool>> Node::printChoicesInfo() const {
        std::vector<std::tuple<std::string, bool>> result;

        for (auto choice : choices_) {
            if (choice == nullptr) {
                result.push_back({END_MESSAGE, false});
            }
            else {
                result.push_back({choice->printMessage(), choice->isSeen()});
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

        for (auto choice : choices_) {
            if (choice == nullptr) {
                result.push_back(false);
            }
            else {
                result.push_back(choice->isSeen());
            }
        }

        return result;
    }
}