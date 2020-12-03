#include <iostream>
using namespace std;
// int s[1000000] = {0};
int main()
{
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        long long sum = 0;
        int max = -1;
        int s;
        for (int j = 0; j < n; j++)
        {
            cin >> s;
            sum += s;
            if (max < s)
                max = s;
        }
        if (max <= sum + 1 - max)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}