#include "language.h"

// Default Constructor
LANG::LANG() {
  txt = ""; // Initialize global text variable to empty value
}

// Loads a LANG text data to 'txt', given a file 'infile'
LANG::LANG(std::ifstream &infile) {

  std::string line;
  std::string text;

  // Check if the file is accessible
  if (infile.fail()) {
    std::runtime_error("ERROR: File could not be opened");
  } else {
    while (getline(infile, line)){
      //adds line to full sequence
      text+=line;
    }
  }
  infile.close();
}

  //tests to see if file text is valid format
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
  std::vector<int> tempFreq(19683);
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
        tempFreq[index]+=1;
      }
      frequencies = tempFreq;
      return frequencies;
}

double LANG::compFreq(LANG trainingFile, LANG testFile) {
  std::vector<int> trFile = trainingFile.getFrequency();
  std::vector<int> teFile = testFile.getFrequency();
  double similarity = 0;
  double numerator = 0;
  double denom1 = 0;
  double denom2 = 0;
  for(i=0; i<=19682; i++) {
    numerator += (trFile[i]*teFile[i]);
    denom1 += std::pow(trFile[i],2);
    denom2 += std::pow(teFile[i].2);
  }
  double denom = std::sqrt(denom1)*std::sqrt(denom2);
  similarity = numerator/denom;
  return similarity;
}
