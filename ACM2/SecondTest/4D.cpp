#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int n, m, i, j, f[1050], J[1050], dp[1050];
	while (cin >> m >> n && m + n + 2)
	{
		memset(dp, 129, sizeof(dp));
		dp[0] = 0;
		for (i = 0; i < n; i++)
			cin >> J[i] >> f[i];
		for (i = 0; i < n; i++)
			for (j = m; j >= f[i]; j--)
				dp[j] = max(dp[j], dp[j - f[i]] + J[i]);
		if (dp[m] < 0)
			cout << "-1" << endl;
		else
			cout << dp[m] << endl;
	}
}
