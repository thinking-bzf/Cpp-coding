#include <iostream>
#include <cstring>
using namespace std;
int dp[105][105];
int w[105], v[105];
int main()
{
    int n, m, k, s;
    while (cin >> n >> m >> k >> s)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= k; i++)
            cin >> w[i] >> v[i];
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                for (int k = v[i]; k <= m; k++)
                {
                    dp[k][j] = max(dp[k][j], dp[k - v[i]][j - 1] + w[i]);
                }
            }
        }
        if (dp[m][s] >= n)
        {
            for (int i = 0; i <= m; i++)
                if (dp[i][s] >= n)
                {
                    printf("%d\n", m - i);
                    break;
                }
        }
        else
            printf("-1\n");
    }
}