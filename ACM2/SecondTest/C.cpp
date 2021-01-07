#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[4] = {0, 0, 0, 0};
int b[4] = {2, 3, 5, 7};
__int64 num[5843];
int main()
{
	int n;
	__int64 k;
	cin >> n;
	while (n--)
	{
		cin >> k;
		while (k % 2 == 0)
		{
			k = k / 2;
		}
		while (k % 3 == 0)
			k = k / 3;
		while (k % 5 == 0)
			k = k / 5;
		while (k % 7 == 0)
			k = k / 7;
		if (k == 1)
		{
			cout << "Yes" << endl;
			continue;
		}
		cout << "No" << endl;
	}
}
