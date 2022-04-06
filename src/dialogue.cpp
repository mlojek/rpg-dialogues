#include "dialogue.hpp"


Dialogue::Dialogue(std::string headMessage) {
    nodes_.push_back(Node(headMessage));
    head_ = &nodes_[0];
    reset();
}

int Dialogue::addNode(std::string message) {
    nodes_.push_back(Node(message));
    return nodes_.size() - 1;
}

void Dialogue::reset() {
    current_ = head_;
}