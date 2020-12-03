#include <iostream>
#include <cstring>
using namespace std;
int dp[255555], V[5005], num;
int main()
{
    int T;
    while (cin >> T && T > 0)
    {
        memset(V, 0, sizeof(V));
        memset(dp, 0, sizeof(dp));
        int v = 0, sum = 0;
        int n = 0;
        for (int i = 1; i <= T; i++)
        {
            cin >> v >> num;
            while (num--)
            {
                V[n++] = v;
                sum += v;
            }
        }
        int s = sum / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = s; j >= V[i]; j--)
                dp[j] = max(dp[j], dp[j - V[i]] + V[i]);
        }
        cout << sum - dp[s] << " " << dp[s] << endl;
    }
}
