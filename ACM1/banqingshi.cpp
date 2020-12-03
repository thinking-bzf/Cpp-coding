#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int a[2005];
long dp[2005][2005];
int main()
{
	int n, k;
	while (~scanf("%d %d", &n, &k))
	{
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i <= n; i++)
			for (int j = 1; j <= k; j++)
				dp[i][j] = inf;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		sort(a, a + n + 1);

		for (int i = 2; i <= n; i++)
			for (int j = 1; j * 2 <= i; j++)
				dp[i][j] = min((a[i - 1] - a[i]) * (a[i - 1] - a[i]) + dp[i - 2][j - 1], dp[i - 1][j]);
		printf("%d\n", dp[n][k]);
	}
}
