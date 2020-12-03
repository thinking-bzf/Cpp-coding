#include <iostream>
#include <cstring>
using namespace std;
int dp[100005][12];
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        memset(dp, 0, sizeof(dp));
        int T, postion, Tmax = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &postion, &T);
            dp[T][postion]++;
            if (T > Tmax)
                Tmax = T;
        }
        for (int i = Tmax - 1; i >= 0; i--)
            for (int j = 0; j <= 10; j++)
            {
                if (j == 0)
                    dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
                else if (j == 10)
                    dp[i][j] += max(dp[i + 1][j], dp[i + 1][j - 1]);
                else
                    dp[i][j] += max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
            }
        cout << dp[0][5] << endl;
    }
}