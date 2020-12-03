#include <iostream>
#include <cstring>
#define inf 10000000
using namespace std;
int p[50010], w[50010], dp[50010];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(dp, 0x3f, sizeof(dp));
        int m1, m2;
        cin >> m1 >> m2;
        int m = m2 - m1;
        int cnt;
        cin >> cnt;
        for (int i = 1; i <= cnt; i++)
            cin >> p[i] >> w[i];
        for (int i = 1; i <= m; i++)
            dp[i] = inf;
        dp[0] = 0;
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = w[i]; j <= m; j++)
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
        }
        if (dp[m] != inf)
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
        }
        else
        {
            printf("This is impossible.\n");
        }
    }
}