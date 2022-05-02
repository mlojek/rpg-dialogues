#ifndef DIALGOUE_FROM_FILE_HPP
#define DIALGOUE_FROM_FILE_HPP


#include <exception>
#include <string>
#include <fstream>
#include "dialogue.hpp"


namespace rpgDialogue {
    class DialogueFileException : public std::exception {
        const char * what () const throw () {
            return "Invalid dialogue file";
        }
    };

    Dialogue dialogueFromFile(std::string filePath);
}


#endif