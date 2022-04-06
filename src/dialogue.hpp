#include "node.cpp"
#include <vector>


class Dialogue {
private:
    Node* head_;
    std::vector<Node> nodes_;

public:
    Dialogue(Node headNode);
};