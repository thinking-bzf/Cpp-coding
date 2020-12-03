#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    int x, y;
} p[60];
int main()
{
    int n;
    while (cin >> n && n)
    {
        double s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        p[n].x = p[0].x;
        p[n].y = p[0].y;
        for (int i = 0; i < n; i++)
        {
            s += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
        }
        s = 0.5 * s;
        printf("%.1lf\n", s);
    }
}