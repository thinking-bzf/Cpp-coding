#include <iostream>
using namespace std;
long long a[60] = {0};
int main()
{
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i < 60; i++)
        a[i] = a[i - 1] + a[i - 2];
    int m;
    while (cin >> m)
        cout << a[m] << endl;
}