#include "language.h"

int main(int argc, char**argv) {
    if(argc !=2)return 1;
    LANG a(argv[1]);
    a.getText();
    std::vector<int> output = a.getFrequency();

}
