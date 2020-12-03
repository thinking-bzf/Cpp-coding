
#include <iostream>
using namespace std;
int main()
{
	int n, i, j, ans, t, tot, a[100];
	double ave;
	cin >> n;
	while (n--)
	{
		cin >> t;
		tot = 0;
		ans = 0;
		for (i = 0; i < t; i++)
		{
			cin >> a[i];
			tot += a[i];
		}
		ave = tot * 1.0 / t;
		for (i = 0; i < t; i++)
		{
			if (a[i] >= ave)
				ans++;
		}
		printf("%.2lf %d\n", ave, ans);
	}
}
