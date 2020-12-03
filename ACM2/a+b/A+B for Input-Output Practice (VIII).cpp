#include <iostream>
using namespace std;
int main()
{
    int n;
    int cnt, a, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        cin >> cnt;
        for (int i = 0; i < cnt; i++)
        {
            cin >> a;
            sum += a;
        }
        if (i != n - 1)
            cout << sum << endl
                 << endl;
        else
            cout << sum << endl;
    }
}