#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f;
int dp[25][510];
int a[25][20];
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int p;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
			{
				cin >> p;
				a[i][j] = p;
			}

		memset(dp, 0, sizeof(dp));
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int Min = inf;
				for (int q = 1; q <= k; q++)
				{
					Min = min(Min, dp[i - 1][a[i - 1][q]] + abs(a[i][j] - a[i - 1][q]));
				}
				dp[i][a[i][j]] = Min;
			}
		}
		int Min = inf;
		for (int i = 1; i <= k; i++)
			if (Min > dp[n][a[n][i]])
				Min = dp[n][a[n][i]];
		cout << Min << endl;
	}
}