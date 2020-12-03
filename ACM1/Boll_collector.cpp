#include <iostream>
#include <cstring>
using namespace std;
int v[1005];
int c[1005];
int dp[1005][1005];
int main()
{
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        memset(dp, 0, sizeof(dp));
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++)
            cin >> v[i];
        for (int i = 1; i <= N; i++)
            cin >> c[i];
        int MAX = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= V; j++)//可能出现体积为0的物体
            {
                if (j >= c[i])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + v[i]);
                else
                    dp[i][j] = dp[i - 1][j];
                
            }
        }
        cout << dp[N][V] << endl;
    }
}