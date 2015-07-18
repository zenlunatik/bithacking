#include <iostream>
#include <assert.h>
#include <time.h>
#include <vector>
#include <set>

using namespace std;

class BitSet
{
    public:
        BitSet(int n);
        ~BitSet();
        bool setBit(int index);
        bool unsetBit(int index);
        char getBit(int index);
        void printBits();

    private:
        unsigned char* m_buffer;
        int m_range;
};

BitSet::BitSet(int n)
{
    m_buffer = (unsigned char*) malloc((n+7)/8);
    assert(m_buffer);
    for (int ii = 0; ii < n; ii++) {
        m_buffer[ii] = 0x00;
    }
    m_range = n;
}

BitSet::~BitSet()
{
    if (m_buffer) {
        free(m_buffer);
    }
}

bool
BitSet::setBit(int index)
{
    if (index < 0 || index >= m_range) {
        return false;
    }

    m_buffer[index/8] = m_buffer[index/8] | ((0x01 << (index%8)));
    return true;
}

bool
BitSet::unsetBit(int index)
{
    if (index < 0 || index >= m_range) {
        return false;
    }

    m_buffer[index/8] &= ~(0x01 << (index%8));
    return true;
}

char
BitSet::getBit(int index)
{
    if (index < 0 || index >= m_range) {
        return false;
    }

    return (m_buffer[index/8] & (0x01 << (index%8))) ? 0x01 : 0x00;
}

void
BitSet::printBits()
{
    for (int ii = 0; ii < m_range/8; ii++) {
        cout<<"'"<<std::hex<<int(m_buffer[ii])<<"'";
    }
    cout<<endl;
}

int main()
{
    BitSet bits(40);

    srand(time(NULL));
    set<int> bitIndexes;
    for (int ii = 0; ii < rand() % 100; ii++) {
        int index = rand() % 40;
        bitIndexes.insert(index);
        bits.setBit(index);
        cout<<"Set bit "<<index<<endl;
    }

    bool success =  true;
    for (set<int>::iterator iter = bitIndexes.begin(); iter != bitIndexes.end(); iter++) {
        if ((bits.getBit(*iter) != 0x01)) {
            cout<<"Did not set bit "<<*iter<<" correctly"<<endl;
            success = false;
        } else {
            cout<<"Set bit "<<*iter<<" correctly"<<endl;
        }
        bits.unsetBit(*iter);
    }
    if (!success) {
        cout<<"Failed to set bits correctly!"<<endl;
        return 0;
    }
   
    success = true;
    for (set<int>::iterator iter = bitIndexes.begin(); iter != bitIndexes.end(); iter++) {
        if ((bits.getBit(*iter) != 0x00)) {
            cout<<"Did not unset bit "<<*iter<<" correctly"<<endl;
            success = false;
        }
        bits.unsetBit(*iter);
    }

    if (!success) {
        cout<<"Failed to unset bits correctly!"<<endl;
        return 0;
    }
   
    cout<<"Success!"<<endl;

}
