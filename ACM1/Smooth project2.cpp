#include <iostream>
#include <cstring>
using namespace std;
int map1[102][102];
bool vis[102];
int dis[102];
int n, ans;
int inf = 0x3f3f3f3f;
void prime()
{
    for (int i = 2; i <= n; i++)
        dis[i] = map1[1][i];
    vis[1] = true;
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        int Min = inf, k;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && Min > dis[j])
            {
                Min = dis[j];
                k = j;
            }
        }
        ans += Min;
        vis[k] = true;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && dis[j] > map1[k][j])
                dis[j] = map1[k][j];
    }
}

int main()
{
    int a, b, c;
    while (cin >> n && n != 0)
    {
        ans = 0;
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n * (n - 1) / 2; i++)
        {
            cin >> a >> b >> c;
            map1[a][b] = map1[b][a] = c;
        }
        prime();
        cout << ans << endl;
    }
}