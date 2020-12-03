#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	int n;
	int cnt1, cnt2;
	cin >> cnt1;
	for (int i = 0; i < cnt1; i++)
	{
		cin >> cnt2;
		cin >> n;
		int t = n;
		for (int j = 0; j < cnt2 - 1; j++)
		{
			cin >> n;
			t = t / gcd(t, n) * n;
		}
		cout << t << endl;
	}
}