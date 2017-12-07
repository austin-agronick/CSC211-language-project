#include "language.h"

int main(int argc, char**argv) {
    // check if 2 arguments are passed
    if(argc<3) return 1;
    //create LANG obect for test data and fets its frequency profile
    // std::ifstream
    std::ifstream lang(argv[argc]);
    LANG testFile(lang);
    double mostSimiliar = 100;
    int mostSimiliarIndex = 0;
    for(int i=1; i<argc; i++){
      // create LANG object a and get its frequency profile
      std::ifstream fileX(argv[i]);
      LANG file(fileX);
      double similarity = file.calcSimilarity(testFile);
      if (similarity < mostSimiliar){
        mostSimiliar = similarity;
        mostSimiliarIndex = i;
      }
    }
    std::cout<<argv[mostSimiliarIndex]<<std::endl;
    return 0;
}
