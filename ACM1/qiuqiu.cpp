#include <iostream>
#include <cstring>
using namespace std;
int dp[100005];
int k[110];
int x[110];
int main()
{
    int T, M;
    while (cin >> T)
    {
        memset(dp, 0, sizeof(dp));
        memset(k, 0, sizeof(k));
        memset(x, 0, sizeof(x));
        for (int m = 1; m <= T; m++)
            cin >> x[m] >> k[m];
        cin >> M;
        for (int i = 1; i <= T; i++)
        {
            for (int j = k[i]; j <= M; j++)
            {
                dp[j] = max(dp[j], dp[j - k[i]] + x[i]);
            }
        }
        cout << dp[M] << endl;
    }
}