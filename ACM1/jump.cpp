#include <iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int s[1005];
int dp[1005];
int main()
{
	int n, Max;
	while (cin >> n && n != 0)
	{
		Max = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			dp[i] = s[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				if (s[i] > s[j])
					dp[i] = max(dp[i], s[i] + dp[j]);
			Max = max(dp[i], Max);
		}
		cout << Max << endl;
	}
}