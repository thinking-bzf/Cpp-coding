#include <iostream>
#include <algorithm>
using namespace std;
int M, N, sum;
struct JF
{
	int J;
	int F;
	double rate;
} JF[1005];

bool cmp(struct JF a, struct JF b)
{
	return a.rate > b.rate;
}

int main()
{
	while (cin >> M >> N)
	{
		if (M == -1 && N == -1)
			break;

		sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> JF[i].J >> JF[i].F;
			JF[i].rate = JF[i].J / JF[i].F * 1.0;
		}
		sort(JF, JF + N, cmp);
		for (int i = 0; i < N; i++)
		{
			if (M >= JF[i].F)
			{
				M -= JF[i].F;
				sum += JF[i].J;
			}
			if (M < JF[i].F)
				break;
		}
		cout << sum << endl;
	}
}