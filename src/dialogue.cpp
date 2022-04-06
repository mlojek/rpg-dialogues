#include "dialogue.hpp"


Dialogue::Dialogue(std::string headMessage) {
    nodes_.push_back(Node(headMessage));
    head_ = &nodes_[0];
    reset();
}

void Dialogue::reset() {
    current_ = head_;
}