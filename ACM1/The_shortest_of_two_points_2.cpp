#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 100005
using namespace std;
struct Point
{
	double x, y;
};
struct Point point[MAXN], *px[MAXN], *py[MAXN];

bool cmpx(Point *a, Point *b) { return a->x < b->x; }
bool cmpy(Point *a, Point *b) { return a->y < b->y; }
double dis(Point *a, Point *b)
{
	return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}
double min(double a, double b) { return a < b ? a : b; }

double closest(int s, int e)
{
	if (s + 1 == e)
		return dis(px[s], px[e]);
	if (s + 2 == e)
		return min(dis(px[s], px[s + 1]), min(dis(px[s], px[s + 2]), dis(px[s + 1], px[s + 2])));
	int mid = (s + e) >> 2;
	double ans = min(closest(s, mid), closest(mid + 1, e));
	int i, j, cnt = 0;
	for (i = s; i <= e; i++)
		if (px[i]->x - px[mid]->x <= ans || px[mid]->x - px[i]->x <= ans)
			py[cnt++] = px[i];
	sort(py, py + cnt, cmpy);
	for (i = 0; i < cnt; i++)
	{
		for (j = i; j < cnt; j++)
		{
			if (py[j]->y - py[i]->y > ans)
				break;
			ans = min(ans, dis(py[i], py[j]));
		}
	}
	return ans;
}

int main()
{
	int i, n;
	while (cin >> n && n != 0)
	{
		for (i = 0; i < n; i++)
		{
			cin >> point[i].x >> point[i].y;
			px[i] = &point[i];
		}
		sort(px, px + n, cmpx);
		double result = 0;
		result = closest(0, n - 1) / 2;
		printf("%.2lf\n", result);
	}
}