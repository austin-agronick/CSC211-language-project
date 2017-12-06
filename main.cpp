#include "language.h"

int main(int argc, char**argv) {
    // check if 2 arguments are passed
    if(argc <3) return 1;
    //create LANG obect for test data and fets its frequency profile
    /*
    LANG test(argv[argc]);
    test.getText();
    std::vector<int> testFreq = test.getFrequency();
    double smallest = 100;
    int smallestIndex = 100;
    for(i=1; i<argc; i++){
      // create LANG object a and get its frequency profile
      LANG a(argv[i]);
      a.getText();
      double similarity = a.getFrequency().compFreq(a, testFreq);
      if (abs(similarity) < smallest){
        smallest = similarity;
        smallestIndex = i;
      }
    }
    return argv[smallestIndex]
    LANG trainingFile()
    LANG testData()
    trainingFile.compFreq(trainingFile, testData)
    // output frequencies vector
    for(unsigned long i=0; i < 19683; i++){
      std::cout<<output[i]<<' ';
    }
    std::cout<<std::endl;
    */
}
