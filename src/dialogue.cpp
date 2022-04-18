#include "../include/dialogue.hpp"


namespace rpgDialogue {
    Dialogue::Dialogue(std::string headMessage, std::string speaker) {
        addNode(headMessage, speaker);
    }

    // Nodes manipulation:
    int Dialogue::addNode(std::string message, std::string speaker) {
        nodes_.push_back(Node(message, speaker));
        head_ = &nodes_[0];     // nodes vector moved, move head pointer
        reset();                // move current too for the same reason
        return nodes_.size() - 1;
    }

    int Dialogue::getNodeCount() const {
        return nodes_.size();
    }

    // Nodes linking:
    void Dialogue::linkNodes(unsigned nodeIndex0, unsigned nodeIndex1) {
        nodes_[nodeIndex0].addChoice(&nodes_[nodeIndex1]);
    }

    void Dialogue::addTerminalChoice(unsigned nodeIndex) {
        nodes_[nodeIndex].addChoice(nullptr);
    }

    // Current message getters:
    std::string Dialogue::getMessage() const {
        return current_->getMessage();
    }

    std::string Dialogue::getSpeaker() const {
        return current_->getSpeaker();
    }

    std::string Dialogue::printMessage() const {
        return current_->printMessage();
    }

    // Current choices info:
    int Dialogue::getChoiceCount() const {
        return current_->getChoiceCount();
    }
    
    std::vector<bool> Dialogue::getChoicesSeen() const {
        return current_->getChoicesSeen();
    }

    // Current choice messages getters:
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

    std::vector<std::tuple<std::string, bool>> Dialogue::getChoicesInfo() const {
        return current_->getChoicesInfo();
    }

    std::vector<std::tuple<std::string, bool>> Dialogue::printChoicesInfo() const {
        return current_->printChoicesInfo();
    }

    // Navigating/playing the dialogue:
    void Dialogue::makeChoice(unsigned choiceNo) {
        current_ = current_->makeChoice(choiceNo);
        current_->setSeen(true);
    }

    bool Dialogue::isDone() const {
        return current_ == nullptr;
    }

    void Dialogue::reset() {
        current_ = head_;

        for (auto node : nodes_) {
            node.setSeen(false);
        }

        head_->setSeen(true);
    }
}