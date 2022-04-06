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

    int getNodeCount();
    int getChoiceCount();
    std::string getMessage();
    std::vector<std::string> getChoiceMessages();
    bool isDone();
    
    int addNode(std::string message);

    void linkNodes(unsigned nodeIndex0, unsigned nodeIndex1);
    void addTerminalChoice(unsigned nodeIndex);

    void makeChoice(unsigned choiceNo);
    void reset();
};