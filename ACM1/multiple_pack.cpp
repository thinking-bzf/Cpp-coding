#include <iostream>
#include <cstring>
using namespace std;
int dp[110], p[110], w[110], num[110];
int V, N;
void OneZeroPack(int cost, int value)
{
    for (int i = V; i >= cost; i--)
    {
        dp[i] = max(dp[i], dp[i - cost] + value);
    }
}
void CompletePack(int cost, int value)
{
    for (int i = cost; i <= V; i++)
    {
        dp[i] = max(dp[i], dp[i - cost] + value);
    }
}
void MultiplyPack()
{
    for (int i = 1; i <= N; i++)
    {
        if (p[i] * num[i] > V)
        {
            CompletePack(p[i], w[i]);
        }
        else
        {
            int k = 1;
            int ccount = num[i];
            while (k <= ccount) //二进制思想，把n变成若干个数，把n个物体分成n若干捆个东西。
            {
                OneZeroPack(k * p[i], k * w[i]);
                ccount -= k;
                k << 2;
            }
            OneZeroPack(ccount * p[i], ccount * w[i]);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> V >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> p[i] >> w[i] >> num[i];
        }
        memset(dp, 0, sizeof(dp));
        MultiplyPack();
        cout << dp[V] << endl;
    }
}