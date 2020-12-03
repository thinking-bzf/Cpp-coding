#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int c1[10000], c2[10000];
int main()
{
	int a[1005];
	int n;
	while (cin >> n)
	{
		int sum = 0;
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		c1[0] = 1;
		c1[a[1]] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= sum; j++)
				for (int k = 0; j + k <= sum && k <= a[i]; k += a[i])
				{
					c2[j + k] += c1[j];
					c2[abs(j - k)] += c1[j];
				}
			for (int j = 0; j <= sum; j++)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		int cnt = 0;
		int count[10005];
		for (int i = 1; i <= sum; i++)
		{
			if (c1[i] == 0)
			{
				cnt++;
				count[cnt] = i;
			}
		}
		if (cnt == 0)
			cout << 0 << endl;
		else
		{
			cout << cnt << endl;
			for (int i = 1; i <= cnt - 1; i++)
			{
				cout << count[i] << " ";
			}
			cout << count[cnt] << endl;
		}
	}
}