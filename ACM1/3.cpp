#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int c, n, m, i, j, a[1005];
	char s[1000];
	cin >> c;
	while (c--)
	{
		cin >> s;
		m = 0;
		for (i = 0; i < strlen(s); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				m = m * 10 + s[i] - '0';
		}
		m = m * 513;
		cout << m;
		cout << endl;
	}
}
