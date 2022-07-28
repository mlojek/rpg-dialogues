#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP


#include <string>
#include <vector>
#include <set>


namespace rpgDialogue {
    const std::string END_MESSAGE = "[END]";

    class Dialogue {
    private:
        struct Node {
            std::string message, speaker;
            std::vector<Node*> choices;
            bool seen;
            int respectGain, infoGain;

            Node(std::string message, std::string speaker, int respectGain = 0, int infoGain = 0) : message(message), speaker(speaker), respectGain(respectGain), infoGain(infoGain) {};
        };


        Node* p_head;
        Node* p_current;
        std::vector<Node> m_nodes;
        int m_respect;
        std::set<int> m_info;


        bool seekEnd(Node* current, unsigned recursion_depth) const;
        std::set<Node*> visitAll(Node* current, unsigned recursion_depth) const;

    public:
        Dialogue(std::string headMessage, std::string speaker, int respectGain = 0, int infoGain = 0);

        // Nodes manipulation:
        int addNode(std::string message, std::string speaker, int respectGain = 0, int infoGain = 0);
        int getNodeCount() const;

        // Nodes linking:
        void linkNodes(unsigned nodeIndex0, unsigned nodeIndex1);
        void addTerminalChoice(unsigned nodeIndex);

        // Current message getters:
        std::string getMessage() const;
        std::string getSpeaker() const;
        std::string printMessage() const;

        // Current choices info:
        int getChoiceCount() const;
        std::vector<bool> getChoicesSeen() const;

        // Current choice messages getters:
        std::vector<std::string> getChoiceMessages() const;
        std::vector<std::string> getChoiceMessagesNumbered() const;
        std::vector<std::string> printChoiceMessages() const;
        std::vector<std::string> printChoiceMessagesNumbered() const;
        std::vector<std::tuple<std::string, bool>> getChoicesInfo() const;
        std::vector<std::tuple<std::string, bool>> printChoicesInfo() const;

        // Navigating/playing the dialogue:
        void makeChoice(unsigned choiceNo);
        bool isDone() const;
        void reset();

        // Respect:
        int getRespect() const;

        // Info:
        std::set<int> getInfo() const;

        // Validation:
        bool isValid() const;
    };
}


#endif