#include "node.cpp"
#include <vector>


class Dialogue {
private:
    Node* head_;
    Node* current_;
    std::vector<Node> nodes_;

public:
    Dialogue(std::string headMessage);

    void reset();
};