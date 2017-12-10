#include "language.h"
#include <fstream>
#include <ostream>

int main(int argc, char**argv) {
    // check if 2 arguments are passed
    if(argc<3) return 1;
    //create LANG object for test data and fits its frequency profile
    std::ifstream testFile(argv[argc-1]);
    LANG testLang(testFile);
    double mostSimiliar = 0;
    int mostSimiliarIndex = 0;
    for(int i=1; i<argc; i++){
      // create LANG object a and get its frequency profile
      std::ifstream fileX(argv[i]);
      LANG file(fileX);
      double similarity = file.calcSimilarity(testLang);
      if (similarity > mostSimiliar){
        mostSimiliar = similarity;
        mostSimiliarIndex = i;
      }
    }
    std::cout<<argv[mostSimiliarIndex]<<std::endl;
    return 0;
}
