#include <iostream>
#include <queue>
using namespace std;
int vis[202][202] = {0};
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char Map[202][202];
int n, m, cnt, sx, sy;
int ex, ey;
struct Friend
{
    int x, y, step;
    bool operator<(const Friend &a) const
    {
        return step > a.step; //最小值优先
    }
} F[40000];
int bfs()
{
    Friend cur, next;
    cur.x = sx;
    cur.y = sy;
    cur.step = 0;
    priority_queue<Friend> qu;
    vis[cur.x][cur.y] = 1;
    qu.push(cur);
    while (!qu.empty())
    {
        cur = qu.top();
        qu.pop();
        for (int i = 0; i < cnt; i++)
        {
            if (cur.x == F[i].x && cur.y == F[i].y)
                return cur.step;
        }
        for (int i = 0; i < 4; i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x < 1 || next.y < 1 || next.x > n || next.y > m || Map[next.x][next.y] == '#' || vis[next.x][next.y])
                continue;

            if (Map[next.x][next.y] == 'x')
                next.step = cur.step + 2;
            else
                next.step = cur.step + 1;
            vis[next.x][next.y] = 1;
            qu.push(next);
        }
    }
    return -1;
}
int main()
{
    while (cin >> n >> m)
    {
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> Map[i] + 1;
            for (int j = 1; j <= m; j++)
            {
                vis[i][j] = 0;
                if (Map[i][j] == 'a')
                {
                    sx = i;
                    sy = j;
                }
                if(Map[i][j]=='r')
                {
                    F[cnt].x = i;
                    F[cnt].y = j;
                    cnt++;
                }
            }
        }
        int b = bfs();
        if (b == -1)
            cout << "Poor ANGEL has to stay in the prison all his life.\n";
        else
            cout << b << endl;
    }
}