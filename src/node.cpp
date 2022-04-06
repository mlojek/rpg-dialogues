#include "node.hpp"
#include <cstddef>


Node::Node(std::string message) : message_(message) {}

std::string Node::getMessage() {
    return message_;
}

int Node::getChoiceCount() {
    return nextNodes_.size();
}

Node* Node::getNext(int choiceNo) {
    if (choiceNo > nextNodes_.size())
        return nullptr;
    else
        return nextNodes_[choiceNo];
}

void Node::setMessage(std::string newMessage) {
    message_ = newMessage;
}

void Node::addChoice(Node* nextNode) {
    nextNodes_.push_back(nextNode);
}