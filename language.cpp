#include "language.h"
#include <algorithm> // std::find

// Default Constructor
LANG::LANG() {
  txt = ""; // Initialize global text variable to empty value

}

// Creates LANG object given the text string
LANG::LANG(std::string text) {
//    std::vector<char> abc = { ' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    for (unsigned long i = 0; i < text.size(); i++) {
        if (text[i] != '\n' && text[i] != ' ' && (text[i] < 'a' || text[i] > 'z')) {
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
std::vector<int> LANG::getFrequency() {
  std::vector<int> frequencies(19683);
      // Start at the first three characters
      for (unsigned long i = 0; i < txt.size()-2; i++) {
        char letter1 = txt[i];
        char letter2 = txt[i+1];
        char letter3 = txt[i+2];

        if (letter1 =='\n') {
          continue;
        }
        else if (letter2 =='\n') {
          letter2 = txt[i+2];
          letter3 = txt[i+3];
        }
        else if (letter3 =='\n') {
          letter3 = txt[i+3];
        }

        int a = letter1 - 'a' + 1;
        int b = letter2 - 'a' + 1;
        int c = letter3 - 'a' + 1;
        // check if trigram contains spaces
        if (letter1 == ' ') a = 0;
        if (letter2 == ' ') b = 0;
        if (letter3 == ' ') c = 0;

        //calculate frequencies with formula
        int index = ((a*(27*27))+(b*27)+c);
        frequencies[index]+=1;
        }
        for(unsigned long i=0;i < 19683;i++){
          std::cout<<frequencies[i]<< ' ';
        }
        return frequencies;

}
