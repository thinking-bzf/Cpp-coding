#include <iostream>
using namespace std;
int main()
{
    int cnt, sum, a;
    while (cin >> cnt)
    {
        if (cnt == 0)
            continue;
        sum = 0;
        for (int i = 0; i < cnt; i++)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }
}