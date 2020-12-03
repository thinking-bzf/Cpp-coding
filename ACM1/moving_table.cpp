#include <iostream>
using namespace std;
int main()
{
	int cnt, n, s, t;
	int st[200] = {0};
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		for (int q = 0; q < 200; q++)
			st[q] = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> s >> t;
			s = (s - 1) / 2, t = (t - 1) / 2;
			if (s > t)
			{
				int temp = s;
				s = t, t = temp;
			}
			for (int k = s; k <= t; k++)
				st[k]++;
		}
		int min = -1;
		for (int m = 0; m < 200; m++)
			if (min < st[m])
				min = st[m];
		cout << min * 10 << endl;
	}
}