#include <iostream>
#include <cstring>
using namespace std;
int dp[10005];
int c[3] = {150, 200, 350};
int main()
{
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < 3; j++)
        {
            for (int k = c[j]; k <= v; k++)
                dp[k] = max(dp[k], dp[k - c[j]] + c[j]);
        }
        cout << v - dp[v] << endl;
    }
}