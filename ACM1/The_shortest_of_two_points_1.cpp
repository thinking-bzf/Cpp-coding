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
double get_dis(Point *p1, Point *p2)
{
	return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}
bool cmpx(Point *p1, Point *p2) { return p1->x < p2->x; }
bool cmpy(Point *p1, Point *p2) { return p1->y < p2->y; }
double min(double a, double b) { return a < b ? a : b; }

double closest(int s, int e)
{
	if (s + 1 == e)
		return get_dis(px[s], px[e]);
	if (s + 2 == e)
		return min(get_dis(px[s], px[s + 1]), min(get_dis(px[s + 1], px[e]), get_dis(px[s], px[e])));
	int mid = (s + e) >> 1;
	double ans = min(closest(s, mid), closest(mid + 1, e));
	int i, j, cnt = 0;
	for (i = s; i <= e; i++)
	{
		if (px[i]->x >= px[mid]->x - ans && px[i]->x <= px[mid]->x + ans)
			py[cnt++] = px[i];
	}
	sort(py, py + cnt, cmpy);
	for (i = 0; i < cnt; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (py[j]->y - py[i]->y >= ans)
				break;
			ans = min(ans, get_dis(py[i], py[j]));
		}
	}
	return ans;
}
int main()
{
	int i, n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &point[i].x, &point[i].y);
			px[i] = &point[i];
		}
		sort(px, px + n, cmpx);
		double distance = closest(0, n - 1);
		printf("%.2lf\n", distance / 2);
	}
	return 0;
}