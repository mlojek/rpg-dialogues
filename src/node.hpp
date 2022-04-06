#include <vector>
#include <string>


class Node {
private:
    std::string message_;
    std::vector<Node*> nextNodes_;

public:
    Node(std::string message);

    std::string getMessage();
    int getChoiceCount();
    Node* getNext(int choiceNo);

    void setMessage(std::string newMessage);
    void addChoice(Node* nextNode);
};