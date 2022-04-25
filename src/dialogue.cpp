#include "../include/dialogue.hpp"
#include "node.hpp"
#include <cstddef>


namespace rpgDialogue {
    Dialogue::Dialogue(std::string headMessage, std::string speaker, int respectGain, int infoGain) : m_respect(0), m_info({}) {
        addNode(headMessage, speaker, respectGain, infoGain);
    }

    // Nodes manipulation:
    int Dialogue::addNode(std::string message, std::string speaker, int respectGain, int infoGain) {
        m_nodes.push_back(Node(message, speaker, respectGain, infoGain));
        p_head = &m_nodes[0];         // nodes vector moved, move head pointer
        reset();                    // move current pointer for the same reason
        return m_nodes.size() - 1;   // return index of the added node
    }

    int Dialogue::getNodeCount() const {
        return m_nodes.size();
    }

    // Nodes linking:
    void Dialogue::linkNodes(unsigned nodeIndex0, unsigned nodeIndex1) {
        if (isInRange(nodeIndex0, 0, m_nodes.size() - 1) && isInRange(nodeIndex1, 0, m_nodes.size() - 1))
            m_nodes[nodeIndex0].addChoice(&m_nodes[nodeIndex1]);
    }

    void Dialogue::addTerminalChoice(unsigned nodeIndex) {
        if (isInRange(nodeIndex, 0, m_nodes.size() - 1))
            m_nodes[nodeIndex].addChoice(nullptr);
    }

    // Current message getters:
    std::string Dialogue::getMessage() const {
        if (p_current == nullptr)
            return END_MESSAGE;
        else
            return p_current->getMessage();
    }

    std::string Dialogue::getSpeaker() const {
        if (p_current == nullptr)
            return END_MESSAGE;
        else
            return p_current->getSpeaker();
    }

    std::string Dialogue::printMessage() const {
        if (p_current == nullptr)
            return END_MESSAGE;
        else
            return p_current->printMessage();
    }

    // Current choices info:
    int Dialogue::getChoiceCount() const {
        if (p_current == nullptr)
            return 0;
        else
            return p_current->getChoiceCount();
    }
    
    std::vector<bool> Dialogue::getChoicesSeen() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->getChoicesSeen();
    }

    // Current choice messages getters:
    std::vector<std::string> Dialogue::getChoiceMessages() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->getChoiceMessages();
    }

    std::vector<std::string> Dialogue::getChoiceMessagesNumbered() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->getChoiceMessagesNumbered();
    }

    std::vector<std::string> Dialogue::printChoiceMessages() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->printChoiceMessages();
    }

    std::vector<std::string> Dialogue::printChoiceMessagesNumbered() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->printChoiceMessagesNumbered();
    }

    std::vector<std::tuple<std::string, bool>> Dialogue::getChoicesInfo() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->getChoicesInfo();
    }

    std::vector<std::tuple<std::string, bool>> Dialogue::printChoicesInfo() const {
        if (p_current == nullptr)
            return {};
        else
            return p_current->printChoicesInfo();
    }

    // Navigating/playing the dialogue:
    void Dialogue::makeChoice(unsigned choiceNo) {
        if (p_current != nullptr)
            p_current = p_current->makeChoice(choiceNo);
        
        if (p_current != nullptr) {
            if (!p_current->isSeen())
                m_respect += p_current->getRespectGain();
            p_current->setSeen(true);
        }
    }

    bool Dialogue::isDone() const {
        return p_current == nullptr;
    }

    void Dialogue::reset() {
        p_current = p_head;

        for (auto node : m_nodes) {
            node.setSeen(false);
        }

        m_respect = p_head->getRespectGain();
        p_head->setSeen(true);
    }

    int Dialogue::getRespect() const {
        return m_respect;
    }
}