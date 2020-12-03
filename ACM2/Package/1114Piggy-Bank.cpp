#include <iostream>
#include <cstring>
#define inf 10000000
using namespace std;
int dp[10005];
int weight[505], value[505];
int main()
{
    int cnt;
    cin >> cnt;
    while (cnt--)
    {
        memset(dp, inf, sizeof(dp));
        int m1, m2;
        cin >> m1 >> m2;
        int m = m2 - m1;
        dp[0] = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> weight[i] >> value[i];
        for (int i = 1; i <= n; i++)
            dp[i] = min(dp[i], dp[i - weight[i]] + value[i]);
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