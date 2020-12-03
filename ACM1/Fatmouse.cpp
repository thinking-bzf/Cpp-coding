#include <iostream>
#include <algorithm>
using namespace std;
struct JF
{
	int j;
	int f;
	double j_f;
};
bool cmp(JF x, JF y)
{
	if (x.j_f != y.j_f)
		return x.j_f > y.j_f;
	return x.f > y.f;
}
int main()
{
	int M, N;
	JF jf[1000];
	double sum = 0;
	while (cin >> M >> N && (M != -1 && N != -1))
	{
		for (int i = 0; i < N; i++)
		{
			cin >> jf[i].j >> jf[i].f;
			jf[i].j_f = 1.0 * jf[i].j / jf[i].f;
		}
		sort(jf, jf + N, cmp);
		for (int i = 0; i < N; i++)
		{
			if (M > jf[i].f)
			{
				M -= jf[i].f;
				sum += jf[i].j;
			}
			else
			{
				sum += jf[i].j * (1.0 * M / jf[i].f);
				break;
			}
		}
		printf("%.3f\n", sum);
		sum = 0;
	}
}