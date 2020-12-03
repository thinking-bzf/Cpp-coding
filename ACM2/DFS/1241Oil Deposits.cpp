#include <iostream>
#include <cstring>
using namespace std;
char Map[105][105];
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
int n, m;
int vis[105][105];
void dfs(int ix, int iy)
{
    int tx, ty;
    for (int i = 0; i < 8; i++)
    {
        tx = ix + dir[i][0];
        ty = iy + dir[i][1];
        if (tx < 0 || ty < 0 || tx >= n || ty >= m)
            continue;
        if (!vis[tx][ty] && Map[tx][ty] == '@')
        {
            vis[tx][ty] = 1;
            dfs(tx, ty);
        }
    }
}
int main()
{
    while (cin >> n >> m)
    {
        int cnt = 0;
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> Map[i];
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && Map[i][j] == '@')
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        cout << cnt << endl;
    }
}