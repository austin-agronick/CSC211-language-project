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
  std::vector<int> frequencies(19683);
  std::vector<char> abc = { ' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
      // Start at the first three characters
      for (int i = 0; i < txt.size()-2; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        char letter1 = txt[i];
        char letter2 = txt[i+1];
        char letter3 = txt[i+2];

        if (letter1 =='\n'){
          i+=1;
        }
        else if (letter2 =='\n'){
          letter2=txt[i+2];
          letter3=txt[i+3];
          while j < abc.length() {
            if (letter1 == abc[j]) a=j;
            else if (letter2 == abc[j]) b=j;
            else if (letter3 == abc[j]) c=j;
          }
        }
        else if (letter3 =='\n'){
          letter3=txt[i+3];
          while j < abc.length() {
            if (letter1 == abc[j]) a=j;
            else if (letter2 == abc[j]) b=j;
            else if (letter3 == abc[j]) c=j;
          }
        }
        else {
          while j < abc.length() {
            if (letter1 == abc[j]) a=j;
            else if (letter2 == abc[j]) b=j;
            else if (letter3 == abc[j]) c=j;
          }
        }
        //calculate frequencies with formula
        int index = ((a*(27*27))+(b*27)+c;
        frequencies[index]+=1;

    }
      return frequencies;
}
