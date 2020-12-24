#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int set[102];
int n, m, ans;
struct EDGE
{
    int s, e, cost, c;
} edge[102 * 102];
// kruskal求最小生成树
int findx(int x)
{
    if (x == set[x])
    {
        return x;
    }
    return set[x] = findx(set[x]);
}
bool cmp(EDGE a, EDGE b)
{
    return a.cost < b.cost;
}
void merge(int x, int y)
{
    if (findx(x) != findx(y))
        set[findx(x)] = findx(y);
}
void kruskal()
{
    ans = 0;
    sort(edge + 1, edge + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int xf = findx(edge[i].s);
        int yf = findx(edge[i].e);
        if (xf == yf || edge[i].c == 1)
            continue;
        set[xf] = yf;
        ans += edge[i].cost;
    }
}
int main()
{
    while (cin >> n && n != 0)
    {
        m = n * (n - 1) / 2;
        memset(edge, 0, sizeof(edge));
        for (int i = 1; i <= n; i++)
            set[i] = i;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d %d %d", &edge[i].s, &edge[i].e, &edge[i].cost, &edge[i].c);
            if (edge[i].c == 1)
            {
                merge(edge[i].s, edge[i].e);
            }
        }
        kruskal();
        cout << ans << endl;
    }
}