#include <iostream>
#include <cstring>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main()
{
	int n;
	int s[100005][12];
	while (cin >> n && n != 0)
	{
		memset(s, 0, sizeof(s));
		int j, k, m = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &j, &k);
			s[k][j]++;
			if (k > m)
				m = k;
		}
		for (int i = m - 1; i >= 0; i--)
			for (int j = 0; j <= 10; j++)
			{
				if (j == 0)
					s[i][j] += max(s[i + 1][j + 1], s[i + 1][j]);
				else if (j == 10)
					s[i][j] += max(s[i + 1][j - 1],  s[i + 1][j]);
				else
					s[i][j] += max(s[i + 1][j - 1], max(s[i + 1][j], s[i + 1][j + 1]));
			}
		cout << s[0][5] << endl;
	}
}