#include <iostream>
using namespace std;
long long step[30];
int main()
{
    step[1] = 3;
    step[2] = 7;
    for (int i = 3; i < 25; i++)
        step[i] = step[i - 1] * 2 + step[i - 2];
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        cout << step[n]<<endl;
    }
}