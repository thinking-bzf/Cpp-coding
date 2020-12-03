#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    double x, y;
};
struct Line
{
    Point s, e;
} L[110];
double xmulti(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        int cnt = 0;
        memset(L, 0, sizeof(L));
        for (int i = 0; i < n; i++)
        {
            cin >> L[i].s.x >> L[i].s.y >> L[i].e.x >> L[i].e.y;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (xmulti(L[i].s, L[i].e, L[j].s) * xmulti(L[i].s, L[i].e, L[j].e) <= 0 && xmulti(L[j].s, L[j].e, L[i].s) * xmulti(L[j].s, L[j].e, L[i].e) <= 0)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
}
