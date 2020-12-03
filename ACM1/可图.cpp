#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int d[1005] = {0};

int main()
{
	int T, n, flag = 1;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		flag = 1;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> d[j];
		int q = n;
		while (flag != 0 && q)
		{
			sort(d, d + n, cmp);
			int m = d[0];
			d[0] = 0;
			for (int i = 1; i <= m; i++)
			{
				d[i]--;
				if (d[i] < 0)
					flag = 0;
			}
			q--;
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}