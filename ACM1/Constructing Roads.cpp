#include <iostream>
#include <cstring>
using namespace std;
int map1[102][102];
int dis[102];
bool vis[102];
int n, ans;
int inf = 0x3f3f3f3f;
void prime()
{
    for (int i = 2; i <= n; i++)
        dis[i] = map1[1][i];
    dis[1] = 0;
    vis[1] = true;
    int k;
    for (int i = 1; i < n; i++)
    {
        int minn = inf;
        for (int j = 1; j <= n; j++)

            if (!vis[j] && dis[j] < minn)
            {
                minn = dis[j];
                k = j;
            }
        ans += minn;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] > map1[k][j]) //寻找下一个支点的最小数
                dis[j] = map1[k][j];
        }
    }
}

int main()
{
    int m;
    while (cin >> n)
    {
        memset(vis, false, sizeof(vis));
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &map1[i][j]);
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            map1[a][b] = map1[b][a] = 0;
        }
        prime();
        cout << ans << endl;
    }
}