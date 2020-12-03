#include <iostream>
using namespace std;
long long cow[60];
int main()
{
    cow[1] = 1;
    cow[2] = 2;
    cow[3] = 3;
    cow[4] = 4;
    for (int i = 5; i < 60; i++)
        cow[i] = cow[i - 1] + cow[i - 3];
    int m;
    while (cin >> m)
    {
        if (m == 0)
            break;
        cout << cow[m] << endl;
    }
}