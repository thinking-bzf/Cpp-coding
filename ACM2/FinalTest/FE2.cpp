#include <iostream>
using namespace std;
char Map[105][105];
int vis[105][105];
int steps[105][105];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
int sx, sy;
int maxn;
int  dfs(int x, int y, int step)
{
    if(steps[x][y])
    {
        maxn = max(maxn, step);
        return steps[x][y];
    }
    int answer;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < 1 || ny > n || ny < 1 || nx > n)
            continue;
        if (!vis[nx][ny])
        {
            if (Map[x][y] == 'W')
            {
                if (Map[nx][ny] == 'A')
                {
                    vis[nx][ny] = 1;
                    answer= dfs(nx, ny, step + 1);
                    vis[nx][ny] = 0;
                }
            }
            else if (Map[x][y] == 'A')
            {
                if (Map[nx][ny] == 'W')
                {
                    vis[nx][ny] = 1;
                   answer= dfs(nx, ny, step + 1);
                    vis[nx][ny] = 0;
                }
            }
        }
    }
    return answer;
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            cin >> Map[i] + 1;
        while (m--)
        {
            maxn = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    vis[i][j] = 0;
            cin >> sx >> sy;
            vis[sx][sy] = 1;
            dfs(sx, sy, 1);
            cout << maxn << endl;
        }
    }
}