#include "node.hpp"
#include <cstddef>
#include <vector>


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

std::vector<std::string> Node::getChoiceMessages() {
    std::vector<std::string> result;

    for (auto choice : nextNodes_) {
        result.push_back(choice->getMessage());
    }

    return result;
}

void Node::setMessage(std::string newMessage) {
    message_ = newMessage;
}

void Node::addChoice(Node* nextNode) {
    nextNodes_.push_back(nextNode);
}