#include <bits/stdc++.h>
#include <cstring>
using namespace std;
char map1[202][202];
int vis[202][202] = {0};
int n, m, c, sx, sy;
struct Node
{
    int x;
    int y;
    int t;
} ed[40000];
int bfs()
{
    Node cur, nex;
    cur.x = sx;
    cur.y = sy;
    cur.t = 0;
    queue<Node> qu;
    qu.push(cur);
    vis[cur.x][cur.y] = 1;
    nex.y = nex.x = nex.y = 0;
    while (!qu.empty())
    {
        cur = qu.front();
        for (int i = 0; i < c; i++)
        {
            if (cur.x == ed[i].x && cur.y == ed[i].y)
            {
                return cur.t;
            }
        }
        if (cur.x + 1 <= n) //向下移动
        {
            if (map1[cur.x + 1][cur.y] == '.' || map1[cur.x + 1][cur.y] == 'r')
            {
                nex.x = cur.x + 1;
                nex.y = cur.y;
                nex.t = cur.t + 1;
            }
            else if (map1[cur.x + 1][cur.y] == 'x')
            {
                nex.x = cur.x + 1;
                nex.y = cur.y;
                nex.t = cur.t + 2;
            }
            if (!vis[nex.x][nex.y])
            {
                vis[nex.x][nex.y] = 1;
                qu.push(nex);
            }
        }
        if (cur.x - 1 >= 1) //向上移动
        {
            if (map1[cur.x - 1][cur.y] == '.' || map1[cur.x - 1][cur.y] == 'r')
            {
                nex.x = cur.x - 1;
                nex.y = cur.y;
                nex.t = cur.t + 1;
            }
            else if (map1[cur.x - 1][cur.y] == 'x')
            {
                nex.x = cur.x - 1;
                nex.y = cur.y;
                nex.t = cur.t + 2;
            }
            if (!vis[nex.x][nex.y])
            {
                vis[nex.x][nex.y] = 1;
                qu.push(nex);
            }
        }
        if (cur.y + 1 <= m) //向右移动
        {
            if (map1[cur.x][cur.y + 1] == '.' || map1[cur.x][cur.y + 1] == 'r')
            {
                nex.x = cur.x;
                nex.y = cur.y + 1;
                nex.t = cur.t + 1;
            }
            else if (map1[cur.x][cur.y + 1] == 'x')
            {
                nex.x = cur.x;
                nex.y = cur.y + 1;
                nex.t = cur.t + 2;
            }
            if (!vis[nex.x][nex.y])
            {
                vis[nex.x][nex.y] = 1;
                qu.push(nex);
            }
        }
        if (cur.y - 1 >= 1) //向左移动
        {
            if (map1[cur.x][cur.y - 1] == '.' || map1[cur.x][cur.y + 1] == 'r')
            {
                nex.x = cur.x;
                nex.y = cur.y - 1;
                nex.t = cur.t + 1;
            }
            else if (map1[cur.x][cur.y - 1] == 'x')
            {
                nex.x = cur.x;
                nex.y = cur.y - 1;
                nex.t = cur.t + 2;
            }
            if (!vis[nex.x][nex.y])
            {
                vis[nex.x][nex.y] = 1;
                qu.push(nex);
            }
        }

        qu.pop();
    }
    return -1;
}

int main()
{

    while (cin >> n >> m)
    {
        c = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> map1[i] + 1;
            for (int j = 1; j <= m; j++)
            {

                vis[i][j] = 0;
                if (map1[i][j] == 'a')
                {
                    sx = i;
                    sy = j;
                }
                if (map1[i][j] == 'r')
                {
                    ed[c].x = i;
                    ed[c].y = j;
                    c++;
                }
            }
        }
        int b = bfs();
        if (b == -1)
            cout << "Poor ANGEL has to stay in the prison all his life.\n";
        else
            cout << b << endl;
    }
    return 0;
}