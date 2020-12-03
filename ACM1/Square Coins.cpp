#include <iostream>
using namespace std;
const int lmax = 300;
int c1[lmax + 1], c2[lmax + 1];
int main()
{
	int n, i, j, k;
	while (cin >> n && n != 0)
	{
		for (i = 0; i <= n; i++)
		{
			c1[i] = 1;
			c2[i] = 0;
		}
		for (i = 2; i <= 17; i++)
		{
			for (j = 0; j <= n; j++)
				for (k = 0; k + j <= n; k += i * i)
				{
					c2[j + k] += c1[j];
				}
			for (j = 0; j <= n; j++)
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[n] << endl;
	}
	return 0;
}
