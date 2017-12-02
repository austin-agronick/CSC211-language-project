#include "language.h"

int main(){
    LANG a("test text");
    for (int output : a.getFrequency()) {
        std::cout << output << std::endl;
    }
}
