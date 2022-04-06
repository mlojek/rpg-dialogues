#include "node.hpp"


Node::Node(std::string message) : message_(message) {}

std::string Node::getMessage() {
    return message_;
}

void Node::setMessage(std::string newMessage) {
    message_ = newMessage;
}