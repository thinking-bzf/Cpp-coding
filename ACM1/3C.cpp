#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string a;
	int c;
	cin >> c;
	while (c--)
	{
		cin >> a;
		long long sum = 0;
		int n = a.size();
		for (int i = 0; i < n; i++)
		{

			if (a[i] >= '0' && a[i] <= '9')
			{
				int m = a[i] - '0';
				sum = sum * 10 + m;
			}
		}
		cout << sum * 513 << endl;
	}
}