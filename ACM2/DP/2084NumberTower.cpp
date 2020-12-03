#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int dp[105][105];
    int c, n;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= j; k++)
                cin >> dp[j][k];
        for (int j = n - 1; j >= 1; j--)
            for (int k = 1; k <= j; k++)
                dp[j][k] += max(dp[j + 1][k], dp[j + 1][k + 1]);
        cout << dp[1][1] << endl;
    }
}