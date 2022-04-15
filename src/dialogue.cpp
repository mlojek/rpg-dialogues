#include "../include/dialogue.hpp"


namespace rpgDialogue {
    Dialogue::Dialogue(std::string headMessage, std::string speaker) {
        nodes_.push_back(Node(headMessage, speaker));
        head_ = &nodes_[0];
        reset();
    }

    int Dialogue::getNodeCount() const {
        return nodes_.size();
    }

    int Dialogue::getChoiceCount() const {
        return current_->getChoiceCount();
    }

    std::string Dialogue::getMessage() const {
        return current_->getMessage();
    }

    std::string Dialogue::getSpeaker() const {
        return current_->getSpeaker();
    }

    std::string Dialogue::printMessage() const {
        return current_->printMessage();
    }

    std::vector<std::string> Dialogue::getChoiceMessages() const {
        return current_->getChoiceMessages();
    }

    std::vector<std::string> Dialogue::getChoiceMessagesNumbered() const {
        return current_->getChoiceMessagesNumbered();
    }

    std::vector<std::string> Dialogue::printChoiceMessages() const {
        return current_->printChoiceMessages();
    }

    std::vector<std::string> Dialogue::printChoiceMessagesNumbered() const {
        return current_->printChoiceMessagesNumbered();
    }

    bool Dialogue::isDone() const {
        return current_ == nullptr;
    }

    int Dialogue::addNode(std::string message, std::string speaker) {
        nodes_.push_back(Node(message, speaker));
        head_ = &nodes_[0];     //nodes_ vector moved, change head pointer
        reset();
        return nodes_.size() - 1;
    }

    void Dialogue::linkNodes(unsigned nodeIndex0, unsigned nodeIndex1) {
        nodes_[nodeIndex0].addChoice(&nodes_[nodeIndex1]);
    }

    void Dialogue::addTerminalChoice(unsigned nodeIndex) {
        nodes_[nodeIndex].addChoice(nullptr);
    }

    void Dialogue::makeChoice(unsigned choiceNo) {
        current_ = current_->getNext(choiceNo);
    }

    void Dialogue::reset() {
        current_ = head_;
    }
}