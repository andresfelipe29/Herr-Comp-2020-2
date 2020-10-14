#include "factorial.h"

long factorial(long n)
{
    if (n < 0){
        std::cerr << "ERROR:compute factorial for negative numbers. Recieved n=" << n << "\n";
    }
    return n <= 1 ? 1 : n*factorial(n-1);
}
