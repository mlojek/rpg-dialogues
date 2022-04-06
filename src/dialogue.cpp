#include "dialogue.hpp"


Dialogue::Dialogue(std::string headMessage) {
    nodes_.push_back(Node(headMessage));
    head_ = &nodes_[0];
    reset();
}

int Dialogue::getNodeCount() {
    return nodes_.size();
}

int Dialogue::getChoiceCount() {
    return current_->getChoiceCount();
}

std::string Dialogue::getMessage() {
    return current_->getMessage();
}

std::vector<std::string> Dialogue::getChoiceMessages() {
    return current_->getChoiceMessages();
}

bool Dialogue::isDone() {
    return current_ == nullptr;
}

int Dialogue::addNode(std::string message) {
    nodes_.push_back(Node(message));
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