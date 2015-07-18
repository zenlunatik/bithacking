#include <iostream>
#include <time.h>

void setZeros()
{
    srand(time(NULL));
    int ar[7][8] = {0};
    uint32_t rowMap = 0x00000000;
    uint32_t colMap = 0x00000000;

    for (int ii = 0; ii < 7; ii ++) {
        for (int jj = 0; jj < 8; jj++) {
            ar[ii][jj] = rand() % 10;
        }
    }

    for (int ii = 0; ii < 7; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            std::cout<<ar[ii][jj]<<" ";
        }
        std::cout<<std::endl;
    }

    for (int ii = 0; ii < 7; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            if (ar[ii][jj] == 0) {
                if ((rowMap & (0x00000001 << ii)) || (colMap & (0x00000001 << jj))) {
                    continue;
                }
                rowMap |= 0x00000001<<ii;
                colMap |= 0x00000001<<jj;
                for (int cc = 0; cc < 8; cc++) {
                    ar[ii][cc] = 0;
                }
                for (int rr = 0; rr < 7; rr++) {
                    ar[rr][jj] = 0;
                }
            }
        }
    }

    std::cout<<std::endl;

    for (int ii = 0; ii < 7; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            std::cout<<ar[ii][jj]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main()
{
    setZeros();
}
