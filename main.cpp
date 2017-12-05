#include "language.h"

int main(int argc, char**argv) {
    // check if 2 arguments are passed
    if(argc !=2) return 1;
    // create LANG object a and get its frequency profile
    LANG a(argv[1]);
    a.getText();
    std::vector<int> output = a.getFrequency();
    // output frequencies vector
    for(unsigned long i=0; i < 19683; i++){
      std::cout<<output[i]<<' ';
    }
    std::cout<<std::endl;
}
