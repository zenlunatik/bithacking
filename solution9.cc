#include <iostream>

// Assuming all small case characters.
// All ASCII characters, would need 256 bit bitmap
//

bool
allUnique(char* str)
{
    if (str == NULL) {
        return true;
    }

    uint32_t bitmap = 0x0000;
    char* tmp = str;
    while (*tmp) {
        int index = *tmp - 'a';
        if ((bitmap & (0x0001 << index))) {
            return false;
        }
        bitmap |= 0x0001 << index;
        ++tmp;
    }
    return true;
}

int main()
{
    std::cout<<"all unique = "<<allUnique("abcdefgh")<<std::endl;
    std::cout<<"all unique = "<<allUnique("abcddfgh")<<std::endl;
}
