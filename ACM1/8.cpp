#include <map>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int i, j, n, t, m, a[11000];
	double ans;
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[i];
		ans += 1.0 / max(a[0], a[n - 1]);
		for (i = 1; i < n; i++)
			ans += 1.0 / max(a[i - 1], a[i]);
		printf("%.2f\n", ans);
	}
}
