#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    double x, y;
} p[105];
double xmulti(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}
int main()
{
    int n;
    while (cin >> n && n > 0)
    {
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (xmulti(p[i], p[j]) < 0)
                {
                    Point tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%.1f %.1f", p[i].x, p[i].y);
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
    }
}