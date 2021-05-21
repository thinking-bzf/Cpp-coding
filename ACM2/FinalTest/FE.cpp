#include <iostream>
#include <queue>
using namespace std;
char Map[105][105];
int vis[105][105];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
int sx, sy;
struct WA
{
    int x, y;
    int step;
};

int bfs(int sx, int sy)
{
    WA cur, next;
    queue<WA> qu;
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    qu.push(cur);
    vis[sx][sy] = 1;
    int maxn = 0;
    while (!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        maxn = max(maxn, cur.step);
        for (int i = 0; i < 4; i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x < 1 || next.y > n || next.y < 1 || next.x > n)
                continue;
            if (!vis[next.x][next.y])
            {
                if (Map[cur.x][cur.y] == 'W')
                    if (Map[next.x][next.y] == 'A')
                    {
                        next.step = cur.step + 1;
                        vis[next.x][next.y] = 1;
                        qu.push(next);
                    }
                if (Map[cur.x][cur.y] == 'A')
                    if (Map[next.x][next.y] == 'W')
                    {
                        next.step = cur.step + 1;
                        vis[next.x][next.y] = 1;
                        qu.push(next);
                    }
            }
        }
    }
    return maxn;
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            cin >> Map[i] + 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //         cout << Map[i][j];
        //     cout << endl;
        // }
        while (m--)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    vis[i][j] = 0;
            cin >> sx >> sy;
            cout << bfs(sx, sy) << endl;
        }
    }
}