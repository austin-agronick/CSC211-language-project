Design Document for CSC 211 Final Project: Language Detection
Daniel Aleksa
Daleksa@my.uri.edu
Austin Agronick


Problems to Solve:
  Milestone 1:
    -Given a string of text, create a vector of integers that stores the frequency of each trigram

  Milestone 2:
    -Create a compile script
    -Implement file IO
    -Implement the similarity formula
    -Distinguish which file's frequency profile is most similar to test file's

Classes Needed:
  Milestone 2:
    -LANG class that represents the language data
        -private instance variable for language data of type std::string
        -Need a constructor method to create an object from a Language filename
        -Needs accessors for the instance variables on which frequency evaluations need to be done

Other Functions:
    Milestone 1:
    -getFrequency() to get a frequency profile
        -takes string of language data and starting at first index, incrementing by one and finding the trigram value for every 3 characters
        -add one to the frequency counter vector at that trigram value index


    Milestone 2:
    -getData() to convert the language file to a string
        -Increment through language file adding each character to a string with the exception of newline characters
    -compareFrequencies() to compare language object's trigram frequencies
        -Implement the cosine similarity formula to determine which training file's frequency profile is most similar to the given test file's

Files Needed:
    -language.h and language.cpp for LANG
    -main.cpp to test for language detection

Libraries Needed:
    -vector
    -string
    -iostream
    -ifstream
    -cmath

Compile Script
    -Will need to compile language.cpp and main.cpp
    -Will need to make sure not to optimize code before debugging by using the flag -g and not -02
