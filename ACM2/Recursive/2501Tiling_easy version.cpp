#include <iostream>
using namespace std;
long long stone[40];
int main()
{
    stone[1] = 1;
    stone[2] = 3;
    for (int i = 3; i < 40; i++)
        stone[i] = stone[i - 1] + stone[i - 2] * 2;
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        cout << stone[n] << endl;
    }
}