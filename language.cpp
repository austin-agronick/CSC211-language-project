#include "language.h"
#include <locale>


// Default Constructor
LANG::LANG() {

}


// Creates LANG object given the text string
LANG::LANG(std::string text) {
    for (char c : text) {
        if (c != ' ' && c != '/n' && std::islower(c); != true) {
            throw std::runtime_error("ERROR: Invalid text input, must only contain lowercase letters and spaces");
        }
    }

    txt = text; // Initialize global text variable
}


std::string LANG::getText() {
    return txt;
}

/*
get a frequency profile
    -takes string of language data and starting at first index, incrementing by one and finding the trigram value for every 3 characters
    -add one to the frequency counter vector at that trigram value index
*/
std::vector<int>; LANG::getFrequency() {


}
