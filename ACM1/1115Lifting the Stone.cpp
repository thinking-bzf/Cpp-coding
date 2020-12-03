#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    int x, y;
} p[20010];
int main()
{
    int c, n;
    double s, sumx, sumy, sums;
    cin >> c;
    while (c--)
    {
        s = sums = sumx = sumy = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;

        // p[n].x = p[0].x;
        // p[n].y = p[0].y;
        for (int i = 1; i < n - 1; i++)
        {
            s = (p[i].x - p[0].x) * (p[i + 1].y - p[0].y) - (p[i].y - p[0].y) * (p[i + 1].x - p[0].x);
            sums += s;
            sumx += s * (p[0].x + p[i].x + p[i + 1].x) / 3;
            sumy += s * (p[0].y + p[i].y + p[i + 1].y) / 3;
        }
        printf("%.2lf %.2lf\n", sumx / sums, sumy / sums);
    }
}