#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int sum = 0;
        int pre = 0;
        int now;
        for (int i = 0; i < n; i++)
        {
            cin >> now;
            if (pre <= now)
                sum += (now - pre) * 6 + 5;
            else if (pre > now)
                sum += (pre - now) * 4 + 5;
            pre = now;
        }
        cout << sum << endl;
    }
}
