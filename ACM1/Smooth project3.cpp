#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
double map1[102][102];
bool vis[102];
double dis[102];
int n;
double ans;
int inf = 0x3f3f3f3f;
struct P
{
    int x;
    int y;
} p[102];
double prime()
{
    ans = 0;
    for (int i = 2; i <= n; i++)
        dis[i] = map1[1][i];
    vis[1] = true;
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        double Min = inf;
        int k = -1;
        for (int j = 2; j <= n; j++)
        {
            if (!vis[j] && Min > dis[j])
            {
                Min = dis[j];
                k = j;
            }
        }
        if (k == -1)
            return -1;
        ans += Min;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && dis[j] > map1[k][j])
                dis[j] = map1[k][j];
    }
    return ans;
}
double dist(P a, P b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
    int T, x, y, flag;
    cin >> T;
    while (T--)
    {
        memset(vis, false, sizeof(vis));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            p[i].x = x;
            p[i].y = y;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                double q = dist(p[i], p[j]);
                if (i == j)
                    map1[i][j] = 0;
                else
                {
                    if (q > 1000 || q < 10)
                        map1[i][j] = inf;
                    else
                        map1[i][j] = q;
                }
            }
        }
        double r = prime();
        if (r != -1)
            printf("%.1f\n", r * 100);
        else
            cout << "oh!" << endl;
    }
}