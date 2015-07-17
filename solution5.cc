#include <iostream>

uint32_t numOnes(uint32_t m, uint32_t n)
{
    uint32_t x = m ^ n;
    int numBits = 0;
    while (x) {
        x = x & (x-1);
        ++numBits;
    }
    return numBits;
}

int main()
{
    std::cout<<numOnes(31,14)<<std::endl;
}
