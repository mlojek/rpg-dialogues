#include "../include/dialogueFromFile.hpp"
#include <cstdlib>
#include <fstream>
#include <string>


namespace rpgDialogue {
    Dialogue dialogueFromFile(std::string filePath) {
        // Buffer variables
        std::string strBuf[2];
        int intBuf[2];

        // Open file
        std::ifstream inputFile;
        inputFile.open(filePath);

        // Initialize result
        std::getline(inputFile, strBuf[0]);
        std::getline(inputFile, strBuf[1]);
        inputFile >> intBuf[0] >> intBuf[1];
        Dialogue result(strBuf[0], strBuf[1], intBuf[0], intBuf[1]);

        // Add node loop
        while (!inputFile.eof()) {
            std::getline(inputFile, strBuf[0]);
            if (strBuf[0].empty())    // gap between nodes and links
                break;
            std::getline(inputFile, strBuf[1]);
            inputFile >> intBuf[0] >> intBuf[1];
            result.addNode(strBuf[0], strBuf[1], intBuf[0], intBuf[1]);
        }

        // Link nodes loop
        while (!inputFile.eof()) {
            std::getline(inputFile, strBuf[0]);
            if (strBuf[0].empty())    // gap between nodes and links
                break;

            intBuf[1] = strBuf[0].find(' ');
            intBuf[0] = stoi(strBuf[0].substr(0, intBuf[1]));
            intBuf[1] = stoi(strBuf[0].substr(intBuf[1] + 1));

            result.linkNodes(intBuf[0], intBuf[1]);
        }

        // Add terminal choice loop
        while (!inputFile.eof()) {
            inputFile >> intBuf[0];

            result.addTerminalChoice(intBuf[0]);
        }

        // Close file
        inputFile.close();

        return result;
    }
}