#include "../include/dialogueFromFile.hpp"
#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>




namespace rpgDialogue {
    Dialogue dialogueFromFile(std::string filePath) {
        try {
            // Buffer variables
            std::string strBuf[3];
            int intBuf[2];

            // Open file
            std::ifstream inputFile;
            inputFile.open(filePath);

            // Read in head message and speaker
            std::getline(inputFile, strBuf[0]);
            std::getline(inputFile, strBuf[1]);

            // Read in head respectGain and infoGain
            std::getline(inputFile, strBuf[2]);
            intBuf[0] = stoi(strBuf[2]);
            std::getline(inputFile, strBuf[2]);
            intBuf[1] = stoi(strBuf[2]);

            // Initialize result
            Dialogue result(strBuf[0], strBuf[1], intBuf[0], intBuf[1]);

            // Add node loop
            while (!inputFile.eof()) {
                // Read message line, if empty break
                std::getline(inputFile, strBuf[0]);
                if (strBuf[0].empty())
                    break;
                
                // Read speaker
                std::getline(inputFile, strBuf[1]);

                // Read respectGain and infoGain
                std::getline(inputFile, strBuf[2]);
                intBuf[0] = stoi(strBuf[2]);
                std::getline(inputFile, strBuf[2]);
                intBuf[1] = stoi(strBuf[2]);

                // Add node to the result
                result.addNode(strBuf[0], strBuf[1], intBuf[0], intBuf[1]);
            }

            // Link nodes loop
            while (!inputFile.eof()) {
                // Read line, if empty break
                std::getline(inputFile, strBuf[0]);
                if (strBuf[0].empty())
                    break;

                // Get int values
                intBuf[1] = strBuf[0].find(' ');
                intBuf[0] = stoi(strBuf[0].substr(0, intBuf[1]));
                intBuf[1] = stoi(strBuf[0].substr(intBuf[1] + 1));

                // Link nodes
                result.linkNodes(intBuf[0], intBuf[1]);
            }

            // Add terminal choice loop
            while (!inputFile.eof()) {
                // Get the node index, if empty break
                getline(inputFile, strBuf[0]);
                if (strBuf[0].empty())
                    break;
                
                intBuf[0] = stoi(strBuf[0]);

                // Add terminal choice
                result.addTerminalChoice(intBuf[0]);
            }

            // Close file
            inputFile.close();

            return result;
        }
        catch (std::exception& e) {
            throw DialogueFileException();
        }
    }
}