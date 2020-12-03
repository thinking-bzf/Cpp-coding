#include <iostream>
#include <cstring>
using namespace std;
int volume[1005], value[1005];
int dp[1005][1005];
int main()
{
    int c;
    int n, v;
    cin >> c;
    for (int k = 0; k < c; k++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> v;
        for (int j = 1; j <= n; j++)
            cin >> value[j];
        for (int j = 1; j <= n; j++)
            cin >> volume[j];
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= v; j++)
            {
                if (volume[i] <= j)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - volume[i]] + value[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        cout << dp[n][v] << endl;
    }
}