#include <iostream>

// To keep the number of bits the same, we need to flip a 1 to 0 and a 0 to a 1.
// For finding the next largest number, the 0 that goes to a 1 must be to the
// left of the 1 going to 0. So we have to find the first 0 form the right that
// has 1s to its right. We flip it to 0. Next, we count the number of 1s to its
// right and make the largest possible number from it with one lesser 1 bit.
//

using namespace std;

uint32_t findNext(uint32_t num)
{
    int pos = 0;
    int firstOneSeen = false;
    int numOnes = 0;
    uint32_t tmp = num;
    while (tmp) {
        if (tmp & 0x01) {
            ++numOnes;
            firstOneSeen = true;
        } else {
            if (firstOneSeen) {
                break;
            }
        }
        tmp = tmp >> 1;
        ++pos;
    }

    num = num | (0x01<<pos);
    uint32_t bitmask = 0x01<<pos;
    bitmask = ~(bitmask-1);
    num = num & bitmask;

    bitmask = 0x01<<(numOnes-1);
    --bitmask;
    num = num | bitmask;
    return num;
}

int main()
{
    uint32_t num = 0x367C;
    std::cout<<findNext(num);
}
