#include "node.hpp"


Node::Node(std::string message) : message_(message) {}

std::string Node::getMessage() {
    return message_;
}

int Node::getChoiceNo() {
    return nextNodes_.size();
}

void Node::setMessage(std::string newMessage) {
    message_ = newMessage;
}