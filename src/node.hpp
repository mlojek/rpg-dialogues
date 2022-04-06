#include <vector>
#include <string>


class Node {
private:
    std::string message_;
    std::vector<Node*> nextNodes_;

public:
    Node(std::string message);

    std::string getMessage();
    int getChoiceNo();

    void setMessage(std::string newMessage);
};