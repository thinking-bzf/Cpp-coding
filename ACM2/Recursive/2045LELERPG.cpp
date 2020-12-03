#include <iostream>
using namespace std;
long long square[60] = {0};
int main()
{
    square[1] = 3;
    square[2] = 6;
    square[3] = 6;
    for (int i = 4; i < 60; i++)
        square[i] = square[i - 1] + 2 * square[i - 2];
    int m;
    while (cin >> m)
        cout << square[m] << endl;
}