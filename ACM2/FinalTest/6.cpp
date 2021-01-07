#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int k, i, j, t, len;
	char s[32];
	while (cin >> s >> k)
	{
		//		cout<<s<<endl;
		len = strlen(s);
		for (i = 1; i <= k; i++)
		{
			t = 0;
			while (s[t] <= s[t + 1] && t != len - 1)
				t++;
			if (t == len - 1)
				len--;
			else
			{
				for (j = t; j < len - 1; j++)
					s[j] = s[j + 1];
				len--;
			}
		}
		for (i = 0; i < len; i++)
			cout << s[i];
		cout << endl;
	}
}
