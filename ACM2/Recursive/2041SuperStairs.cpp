#include <iostream>
using namespace std;
int stairs[50] = {0};
int main()
{
    int m, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        stairs[0] = 1;
        stairs[1] = 2;
        for (int i = 2; i < m; i++)
        {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }
        cout << stairs[m - 2] << endl;
    }
}