#include "language.h"
#include <fstream>
#include <ostream>

// main takes 1 or more training files and file to test
int main(int argc, char**argv) {
    // check if 2 arguments are passed
    if(argc<3) return 1;
    //create LANG object for test data and get its frequency profile
    std::ifstream testFile(argv[argc-1]);
    LANG testLang(testFile);
    testLang.calcFrequency();
    std::vector<int> testFile = testLang.getFrequency();
    // find which training file is most similiar to the test file
    double mostSimiliar = 0;
    int mostSimiliarIndex = 0;
    // iterate through training files, getting their similarity value
    for(int i=1; i<argc-1; i++) {
      std::ifstream fileX(argv[i]);
      LANG file(fileX);
      double similarity = file.calcSimilarity(testFile);
      if (similarity > mostSimiliar) {
        mostSimiliar = similarity;
        mostSimiliarIndex = i;
      }
    }
    // output training file with most similar frequency profile to test file
    std::cout<<argv[mostSimiliarIndex]<<std::endl;
    return 0;
}
