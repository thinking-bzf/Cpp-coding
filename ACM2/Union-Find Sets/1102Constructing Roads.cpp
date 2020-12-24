#include <iostream>
#include <cstring>
using namespace std;
int map1[102][102];
int dis[102];
bool vis[102];
int n, ans;
int inf = 0x3f3f3f3f;
// prim求最小生成树
void prim()
{
    for (int i = 2; i <= n; i++)
        dis[i] = map1[1][i];
    // 
    dis[1] = 0;
    vis[1] = true;
    int k;
    for (int i = 1; i < n; i++)
    {
        int minn = inf;
        for (int j = 1; j <= n; j++)
            // 寻找该节点相连未被加入生成树中的节点的最小值
            if (!vis[j] && dis[j] < minn)
            {
                minn = dis[j];
                k = j;
            }
        ans += minn;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
        {
            // 加入的节点加入生成树后，需要把当前节点与其他未连接的节点的边更新到dis数组中
            // 遍历dis数组，如果加入的节点的连接边比当前存在于生成树中的节点连接边代价还要大就不用加，反之就更新未加入节点的连接边的值
            if (!vis[j] && dis[j] > map1[k][j])
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
        // 如果两个村庄连接，则把他们两个之间的代价变为0
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            map1[a][b] = map1[b][a] = 0;
        }
        prim();
        cout << ans << endl;
    }
}