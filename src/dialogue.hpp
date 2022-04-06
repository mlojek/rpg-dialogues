#include "node.cpp"
#include <string>
#include <vector>


class Dialogue {
private:
    Node* head_;
    Node* current_;
    std::vector<Node> nodes_;

public:
    Dialogue(std::string headMessage);

    int addNode(std::string message);

    void reset();
};