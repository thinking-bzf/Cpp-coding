#include <iostream>
#include <algorithm>
using namespace std;
struct JM
{
	int s;
	int e;
};
bool cmp(JM x, JM y)
{
	if (x.e != y.e)
		return x.e < y.e;
	return x.s < y.s;
}
int main()
{
	JM jm[100];
	int N;
	while (cin >> N && N != 0)
	{
		for (int i = 0; i < N; i++)
			cin >> jm[i].s >> jm[i].e;
		sort(jm, jm + N, cmp);
		int cnt = 1, k = 0;
		for (int i = 1; i < N; i++)
		{
			if (jm[k].e > jm[i].s)
			{
				continue;
				i++;
			}
			else
			{
				k = i;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}