#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    int x, y;
} p[1000];

int main()
{
    int n;
    while (cin >> n && n)
    {
        int flag = 1;
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        p[n].x = p[0].y;
        p[n].y = p[0].y;
        for (int i = 0; i < n - 1; i++)
        {
            if ((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i].y) - (p[i + 1].y - p[i].y) * (p[i + 2].x - p[i].x) < 0)
                flag = 0;
        }
        if ((p[0].x - p[n - 1].x) * (p[1].y - p[n - 1].y) - (p[0].y - p[n - 1].y) * (p[1].x - p[n - 1].x) < 0)
            flag = 0;
        if (flag)
            cout << "convex" << endl;
        else
            cout << "concave" << endl;
    }
}