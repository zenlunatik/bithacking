#include <iostream>
#include <stdint.h>

uint32_t
getMask(uint32_t i, uint32_t j)
{
    if (i > 31 || j > 31 || i > j) {
        return -1;
    }
    return ~(((1<<(j+1)) -1) - ((1<<(i+1)) -1));
}

uint32_t
replace(uint32_t M, uint32_t N, uint32_t i, uint32_t j)
{
    return (N & getMask(i,j)) | (M << i);
}

int main()
{
    uint32_t M = 0x13;
    uint32_t N = 0x400;
    uint32_t i = 2; 
    uint32_t j = 6;
    std::cout<<"result = "<<replace(M, N, i, j)<<std::endl;
}
