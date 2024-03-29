#include "../include/dialogue.hpp"
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>


namespace rpgDialogue {
    Dialogue::Dialogue(std::string headMessage, std::string speaker, int respectGain, int infoGain) : m_respect(0), m_info({}) {
        addNode(headMessage, speaker, respectGain, infoGain);
    }

    // Nodes manipulation:
    int Dialogue::addNode(std::string message, std::string speaker, int respectGain, int infoGain) {
        m_nodes.emplace_back(message, speaker, respectGain, infoGain);
        p_head = &m_nodes[0];           // nodes vector moved, move head pointer
        reset();                        // move current pointer for the same reason
        return m_nodes.size() - 1;      // return index of the added node
    }

    int Dialogue::getNodeCount() const {
        return m_nodes.size();
    }

    // Nodes linking:
    void Dialogue::linkNodes(unsigned nodeIndex0, unsigned nodeIndex1) {
        if (nodeIndex0 < 0 || nodeIndex0 >= m_nodes.size() || nodeIndex1 < 0 || nodeIndex1 >= m_nodes.size())
            throw std::out_of_range("One or more node indexes out of range");
        else if (nodeIndex0 == nodeIndex1)
            throw std::invalid_argument("Can't link node with itself");
        else
            m_nodes[nodeIndex0].choices.push_back(&m_nodes[nodeIndex1]);
    }

    void Dialogue::addTerminalChoice(unsigned nodeIndex) {
        if (nodeIndex < 0 || nodeIndex >= m_nodes.size())
            throw std::out_of_range("Node index out of range");
        else
            m_nodes[nodeIndex].choices.push_back(nullptr);
    }

    // Current message getters:
    std::string Dialogue::getMessage() const {
        if (p_current == nullptr)
            return END_MESSAGE;
        else
            return p_current->message;
    }

    std::string Dialogue::getSpeaker() const {
        if (p_current == nullptr)
            return END_MESSAGE;
        else
            return p_current->speaker;
    }

    std::string Dialogue::printMessage() const {
        if (p_current == nullptr)
            return END_MESSAGE;
        else
            return p_current->speaker + ": " + p_current->message;
    }

    // Current choices info:
    int Dialogue::getChoiceCount() const {
        if (p_current == nullptr)
            return 0;
        else
            return p_current->choices.size();
    }
    
    std::vector<bool> Dialogue::getChoicesSeen() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<bool> result;
            result.reserve(p_current->choices.size());

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    result.emplace_back(false);
                else
                    result.emplace_back(choice->seen);
            }

            return result;
        }
    }

    // Current choice messages getters:
    std::vector<std::string> Dialogue::getChoiceMessages() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<std::string> result;
            result.reserve(p_current->choices.size());

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    result.emplace_back(END_MESSAGE);
                else
                    result.emplace_back(choice->message);
            }

            return result;
        }
    }

    std::vector<std::string> Dialogue::getChoiceMessagesNumbered() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<std::string> result;
            result.reserve(p_current->choices.size());
            int i = 0;

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    result.emplace_back(std::to_string(i) + ") " + END_MESSAGE);
                else
                    result.emplace_back(std::to_string(i) + ") " + choice->message);

                i++;
            }

            return result;
        }
    }

    std::vector<std::string> Dialogue::printChoiceMessages() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<std::string> result;
            result.reserve(p_current->choices.size());

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    result.emplace_back(END_MESSAGE);
                else
                    result.emplace_back(choice->speaker + ": " + choice->message);
            }

            return result;
        }
    }

    std::vector<std::string> Dialogue::printChoiceMessagesNumbered() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<std::string> result;
            result.reserve(p_current->choices.size());
            int i = 0;

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    result.emplace_back(std::to_string(i) + ") " + END_MESSAGE);
                else
                    result.emplace_back(std::to_string(i) + ") " + choice->speaker + ": " + choice->message);

                i++;
            }

            return result;
        }
    }

    std::vector<std::tuple<std::string, bool>> Dialogue::getChoicesInfo() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<std::tuple<std::string, bool>> result;
            result.reserve(p_current->choices.size());
            int i = 0;

            // TODO temporary solution, fix imediately!!!
            std::tuple<std::string, bool> newElement;

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    newElement = {END_MESSAGE, false};
                else
                    newElement = {choice->message, choice->seen};

                result.push_back(newElement);
                i++;
            }

            return result;
        }
    }

    std::vector<std::tuple<std::string, bool>> Dialogue::printChoicesInfo() const {
        if (p_current == nullptr) {
            return {};
        }
        else {
            std::vector<std::tuple<std::string, bool>> result;
            result.reserve(p_current->choices.size());
            int i = 0;

            // TODO temporary solution, fix imediately!!!
            std::tuple<std::string, bool> newElement;

            for (Node* choice : p_current->choices) {
                if (choice == nullptr)
                    newElement = {END_MESSAGE, false};
                else
                    newElement = {choice->speaker + ": " + choice->message, choice->seen};

                result.push_back(newElement);
                i++;
            }

            return result;
        }
    }


    // Navigating/playing the dialogue:
    void Dialogue::makeChoice(unsigned choiceNo) {
        if (p_current != nullptr) {
            if (choiceNo < 0 || choiceNo >= p_current->choices.size())
                throw std::out_of_range("Choice number out of range");
            else
                p_current = p_current->choices[choiceNo];
        }
        else {
            throw std::logic_error("Cannot make choice when dialogue is done (current node pointer == nullptr)");
        }
        
        if (p_current != nullptr) {
            if (!p_current->seen) {
                m_respect += p_current->respectGain;
                m_info.insert(p_current->infoGain);
            }
            p_current->seen = true;
        }
    }

    bool Dialogue::isDone() const {
        return p_current == nullptr;
    }

    void Dialogue::reset() {
        p_current = p_head;

        for (Node& node : m_nodes) {
            node.seen = false;
        }

        m_respect = p_head->respectGain;
        m_info = {p_head->infoGain};
        p_head->seen = true;
    }

    // Respect:
    int Dialogue::getRespect() const {
        return m_respect;
    }

    // Info:
    std::set<int> Dialogue::getInfo() const {
        return m_info;
    }

    // Validaton:
    bool Dialogue::isValid() const {
        // Every node has to have at least one choice
        for (const Node& node : m_nodes)
            if (node.choices.size() == 0)
                return false;

        // There has to be a way to get to nullptr from head
        if (!seekEnd(p_head, m_nodes.size())) return false;

        // Every node has to be accessible from the head
        if (visitAll(p_head, m_nodes.size()).size() != m_nodes.size()) return false;

        return true;
    }

    // Private methods:
    bool Dialogue::seekEnd(Node* current, unsigned recursion_depth) const {
        if (recursion_depth == 0) return false;

        for (Node* choice : current->choices)
            if (choice == nullptr || seekEnd(choice, recursion_depth - 1))
                return true;

        return false;
    }

    std::set<Dialogue::Node*> Dialogue::visitAll(Node* current, unsigned recursion_depth) const {
        if (recursion_depth == 0 || current == nullptr)
            return {};

        std::set<Node*> result({current});

        for (Node* choice : current->choices)
            if (choice != nullptr)
                result.merge(visitAll(choice, recursion_depth - 1));

        return result;
    }
}