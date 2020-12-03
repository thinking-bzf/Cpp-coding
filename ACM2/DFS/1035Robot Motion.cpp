#include <iostream>
#include <cstring>
using namespace std;
char Map[15][15];
int flag;
int n, m, col;
int vis[15][15];
int judge;
int step;
int beloop, loop;
void dfs(int i, int j, int s)
{
    if (i > n || j > m || i < 1 || j < 1)
    {
        judge = 1;
        return;
    }
    step = s;
    if (judge)
        return;
    else
    {
        if (!vis[i][j])
        {
            vis[i][j] = s;
            if (Map[i][j] == 'N')
                dfs(i - 1, j, s + 1);
            else if (Map[i][j] == 'W')
                dfs(i, j - 1, s + 1);
            else if (Map[i][j] == 'E')
                dfs(i, j + 1, s + 1);
            else if (Map[i][j] == 'S')
                dfs(i + 1, j, s + 1);
        }
        else
        {
            // 第几步开始循环
            beloop = vis[i][j] - 1;
            // 循环的个数
            loop = s - vis[i][j];
        }
    }
}
int main()
{
    while (cin >> n >> m >> col)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m;j++)
                cin >> Map[i][j];
        memset(vis, 0, sizeof(vis));
        judge = 0;
        dfs(1, col, 1);
        if (judge)
            printf("%d step(s) to exit\n", step);
        else
            printf("%d step(s) before a loop of %d step(s)\n", beloop, loop);
    }
}