#include <iostream>

using namespace std;

char*
align_mem(int nBytes, int pow)
{
    char* ptr = (char*)malloc(nBytes + (pow-1));
    char* ptr2 = (char*)(((size_t)ptr + (pow-1)) & ~(pow-1));
    char* ptr3 = ptr2 - 1;
    *ptr3 = (char) (ptr - ptr2);
    return ptr2;
}

void
align_free(char* ptr2)
{
    char* ptr3 = ptr2 - 1;
    char offset = *ptr3;
    char* ptr = ptr2 - offset;
    free(ptr);
}


int main()
{
    char* ptr = align_mem(1000, 8);
    std::cout<<((size_t)ptr) % 8<<std::endl;
    align_free(ptr);
}

