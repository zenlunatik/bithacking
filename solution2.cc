#include <iostream>
#include <string>

using namespace std;

string
binaryRep(double number)
{
    if (number <= 0 || number >= 1) {
        return "ERROR"; 
    }
    double frac = 0.5;
    string rep = ".";
    while (number > 0) {
        if (number >= frac) {
            rep.push_back('1');
            number -= frac;
        } else {
            rep.push_back('0');
        }
        frac /= 2;
        if (rep.size() == 32) {
            return "ERROR";
        }
        cout<<rep<<endl;
    }
    return rep;
}

int main()
{
    cout<<binaryRep(0.72)<<endl;
    cout<<binaryRep(0.52)<<endl;
    cout<<binaryRep(0.46)<<endl;
    cout<<binaryRep(0.12)<<endl;
}
