#include "../include/dialogueFromFile.hpp"
#include <fstream>
#include <string>


namespace rpgDialogue {
    Dialogue dialogueFromFile(std::string filePath) {
        // Open file
        std::ifstream inputFile;
        inputFile.open(filePath);

        // Buffer variables
        std::string message, speaker;
        int respectGain, infoGain;

        // Initialize result
        std::getline(inputFile, message);
        std::getline(inputFile, speaker);
        inputFile >> respectGain >> infoGain;
        Dialogue result(message, speaker, respectGain, infoGain);

        // Add node loop
        while (!inputFile.eof()) {
            std::getline(inputFile, message);
            std::getline(inputFile, speaker);
            inputFile >> respectGain >> infoGain;
            result.addNode(message, speaker, respectGain, infoGain);
        }

        // Close file
        inputFile.close();

        return result;
    }
}