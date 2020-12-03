#include <map>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <string>
#include <cmath>
using namespace std;
int a[100005];
int main()
{
	int i, j, n, m, t;
	__int64 ans;
	cin >> t;
	while (t--)
	{
		ans = 1;
		cin >> n >> m;
		for (i = 0; i < n; i++)
			cin >> a[i];
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
			{
				ans = (ans % m) * (abs(a[i] - a[j]) % m) % m;
				if (ans == 0)
					goto label;
			}
	label:
		cout << ans << endl;
	}
}
