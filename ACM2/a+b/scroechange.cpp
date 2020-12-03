#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int nmod = n % 10;
        if (nmod == 9)
            cout << "A" << endl;
        if (nmod == 8)
            cout << "B" << endl;
        if (nmod == 7)
            cout << "C" << endl;
        if (nmod == 6)
            cout << "D" << endl;
        if (nmod >= 0 && nmod < 6)
            cout << "E" << endl;
        if (nmod >= 10 || nmod < 0)
            cout << "Score is error!" << endl;
    }
}