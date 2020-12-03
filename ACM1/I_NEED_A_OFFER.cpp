#include <iostream>
#include <cstring>
using namespace std;
double min(double a, double b)
{
    return a < b ? a : b;
}
double dp[10005], p[10005];
int c[10005];
int main()
{
    int n, m;
    while (cin >> n >> m && (m || n))
    {
        for (int i = 0; i <= n; i++)
        {
            dp[i] = 1.0;
        }
        for (int i = 1; i <= m; i++)
            cin >> c[i] >> p[i];
        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= c[i]; j--)
                dp[j] = min(dp[j], dp[j - c[i]] * (1 - p[i]));
        }
        printf("%.1lf%%\n", (1 - dp[n]) * 100);
    }
}