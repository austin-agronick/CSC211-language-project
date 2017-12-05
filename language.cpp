#include "language.h"

// Default Constructor
LANG::LANG() {
  txt = ""; // Initialize global text variable to empty value
}

// Creates LANG object given the text string
LANG::LANG(std::string text) {
    // Checks if given input is valid
    for (unsigned long i = 0; i < text.size(); i++) {
        if (text[i] != '\n' && text[i] != ' ' && (text[i] < 'a' || text[i] > 'z')) {
            throw std::runtime_error("ERROR: Invalid text input, must only contain lowercase letters and spaces");
        }
    }
    txt = text; // Initialize global text variable
}

// getter for language text data
std::string LANG::getText() {
    return txt;
}

/*
get a frequency profile
    - takes string of language data from a LANG object and starting at first index, increments by one while finding the trigram value for every 3 characters
    - add one to the frequency counter vector at that trigram value index
*/
std::vector<int> LANG::getFrequency() {
  // initialize frequencies vector to 19683 zeroes
  std::vector<int> frequencies(19683);
      // iterate through text input,
      for (unsigned long i = 0; i < txt.size()-2; i++)
      {
        // initialize variables for letters in the trigram
        char letter1 = txt[i];
        char letter2 = txt[i+1];
        char letter3 = txt[i+2];

        // check if the trigram contains a newline character, and if so skip over it
        if (letter1 =='\n') continue;
        else if (letter2 =='\n') {
          letter2 = txt[i+2];
          letter3 = txt[i+3];
        }
        else if (letter3 =='\n') {
          letter3 = txt[i+3];
        }

        // get the value of each letter
        int a = letter1 - 'a' + 1;
        int b = letter2 - 'a' + 1;
        int c = letter3 - 'a' + 1;

        // check if trigram contains spaces
        if (letter1 == ' ') a = 0;
        if (letter2 == ' ') b = 0;
        if (letter3 == ' ') c = 0;

        // find the index of the trigram by using the formula and add 1 to its index
        int index = ((a*(27*27)) + (b*27) + c);
        frequencies[index]+=1;
      }
      return frequencies;
}
