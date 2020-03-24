#include "parcerh.h"


void Begin() {
    std::cout << "start parse ";
}

void End() {
    std::cout << " finish parse\n";
}

void intdetect(int n) {
    std::cout << n << " ";
}

void strdetect(std::string n) {
    std::cout << n << " ";
}

int main() {
    intcallback(intdetect);
    strcallback(strdetect);
    startcallback(Begin);
    finishcallback(End);
    parse("ewrwef gerfer\n12343\tHwerwe");
    return 0;
}