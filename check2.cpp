#include <bits/stdc++.h>
using namespace std;
int dp[35][35][35];
int w(int a, int b, int c)
{
    if (dp[a][b][c])
        return dp[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0)
    {
        dp[a][b][c] = 1;
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        dp[a][b][c] = 1;
        return 1;
    }
    else if (a < b && b < c)
    {
        return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}
int main()
{
    int a, b, c;

    while (cin >> a >> b >> c)
    {
        memset(dp, 0, sizeof(dp));
        cout << w(a, b, c) << endl;
    }
}
