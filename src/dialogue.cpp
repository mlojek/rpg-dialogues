#include "dialogue.hpp"


Dialogue::Dialogue(Node headNode) {
    nodes_.push_back(headNode);
    head_ = & nodes_[0];
}