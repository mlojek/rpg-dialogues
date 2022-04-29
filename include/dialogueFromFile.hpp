#ifndef DIALGOUE_FROM_FILE_HPP
#define DIALGOUE_FROM_FILE_HPP


#include <string>
#include <fstream>
#include "dialogue.hpp"


namespace rpgDialogue {
    Dialogue dialogueFromFile(std::string filePath);
}


#endif