#include <iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int c, n;
	int s[105][105];
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			for (int k = 0; k <= j; k++)
				cin >> s[j][k];
		for (int j = n - 2; j >= 0; j--)
			for (int k = 0; k <= j; k++)
				s[j][k] += max(s[j + 1][k], s[j + 1][k + 1]);
		cout << s[0][0] << endl;
	}
}