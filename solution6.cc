#include <iostream>

using namespace std;

int getNumOnes(uint32_t m)
{
    int ret = 0;
    while (m) {
        m = m & (m-1);
        ++ret;
    }
    return ret;
}

int main()
{
    cout<<getNumOnes(31)<<endl;
}
