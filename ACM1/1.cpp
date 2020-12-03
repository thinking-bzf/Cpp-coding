#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int c, n, i, j;
	long long m, a2, a3, a5, a7;
	while (cin >> m && m)
	{
		a2 = a3 = a5 = a7 = 0;
		while (m % 2 == 0)
		{
			m /= 2;
			a2++;
		}
		while (m % 3 == 0)
		{
			m /= 3;
			a3++;
		}
		while (m % 5 == 0)
		{
			m /= 5;
			a5++;
		}
		while (m % 7 == 0)
		{
			m /= 7;
			a7++;
		}
		cout << (a2 + 1) * (a3 + 1) * (a5 + 1) * (a7 + 1) << endl;
	}
}
