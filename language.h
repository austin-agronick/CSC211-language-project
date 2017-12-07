#ifndef _language_h
#define _language_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
A class to represent the the language data.
A LANG object has one member field: the text, which is a string of characters.
*/

class LANG {

public:

	/*
	Default constructor
	*/
	LANG();

	/*
	*/
	LANG(std::ifstream &infile);

	/*
	Getter methods
	*/
  std::string getText();
	std::vector<int> getFrequency();

  /*
  Calculates trigrm frequency
  */
	void calcFrequency();

	/*
	Compares frequency vectors and calculates similarity
	*/
	double calcSimilarity(LANG testFile);

private:

	/* instance variables */
	std::string txt;
	std::vector<int> frequencies;

};


#endif
