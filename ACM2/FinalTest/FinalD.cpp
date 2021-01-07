#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long sum[100005];
int a[100005];
int main()
{
    int n, c;
    while (cin >> n >> c)
    {
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        int a, b;
        for (int i = 0; i < c; i++)
        {
            cin >> a >> b;
            if (a < b)
                cout << sum[b] - sum[a - 1] << endl;
            else
                cout << sum[a] - sum[b - 1] << endl;
        }
    }
}