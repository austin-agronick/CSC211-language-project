#include "language.h"

int main(int argc, char**argv) {
    // check if 2 arguments are passed
    if(argc<3) return 1;
    std::ifstream testFile(argv[argc-1]);
    /*//create LANG obect for test data and fets its frequency profile
    LANG testFile(argv[argc-1]);
    double mostSimiliar = 100;
    int mostSimiliarIndex = 0;
    for(int i=1; i<argc; i++){
      // create LANG object a and get its frequency profile
      LANG fileX(argv[i]);
      double similarity = fileX.calcSimilarity(testFile);
      if (similarity < mostSimiliar){
        mostSimiliar = similarity;
        mostSimiliarIndex = i;
      }
    }
    std::cout<<argv[mostSimiliarIndex]<<std::endl; */
    return 0;
}
