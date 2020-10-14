#include <iostream>
#include "factorial.h"

int main()
{
    if (factorial(0) != 1){
        std::cerr << "ERROR : facctorial(0) != 1\n";
    }
    else if (factorial(1) != 1){
        std::cerr << "ERROR : facctorial(0) != 1\n";
    }
    else{
        std::cout << "All tests passed";
    }

    return 0;
}
