Design Document for CSC 211 Final Project: Language Detection
Daniel Aleksa
Austin Agronick

Problems to Solve:
  Milestone 1:
    -Create a vector of strings with all trigrams from the given string
    -Create a vector of integers that stores the frequency of each trigram

  Milestone 2:
    -Create a compile script
    -Implement file IO
    -Implement the similarity formula
    -Distinguish which file's frequency profile is most similar to test file's

Classes Needed:
    -Language class that represents the language data
        -private instance variable for language data of type std::string
        -Need a constructor method to create an object from a Language filename
        -Needs accessors for the instance variables on which frequency evaluations need to be done 
