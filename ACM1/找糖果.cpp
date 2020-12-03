#include <iostream>
using namespace std;
int s[1000000] = {0};
int main()
{
	int cnt1, cnt2;
	cin >> cnt1;
	for (int i = 0; i < cnt1; i++)
	{
		cin >> cnt2;
		long long sum = 0;
		int t = -1;
		for (int j = 0; j < cnt2; j++)
		{
			cin >> s[j];
			sum += s[j];
			if (t < s[j])
				t = s[j];
		}
		if (t <= sum + 1 - t)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}