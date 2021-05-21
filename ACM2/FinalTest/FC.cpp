#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long dp[100005][2];
long long val[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        memset(val, 0, sizeof(val));
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
            dp[i][0] = dp[i][1] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = dp[i - 1][0] + val[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
}