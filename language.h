#ifndef _language_h
#define _language_h

#include <iostream>
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
	Constructor with argument for text of langauge data.
	If `text` contains invalid characters, throws a std::runtime_error
	*/
	LANG(std::string text);

	/*
	Getter methods
	*/
  std::string getText();

  /*
  Gets trigrm frequency
  */
	std::vector<int> getFrequency();

private:

	/* instance variables */
	std::string txt;

};


#endif
