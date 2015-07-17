#include <iostream>

uint32_t swapEvenAndOddBits(uint32_t n)
{
    return (((n & 0x55555555) << 1 ) | ((n & 0xaaaaaaaa) >> 1));
}

int main()
{
    std::cout<<std::hex<<swapEvenAndOddBits(0x367c)<<std::endl;
}
