#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map1[55][55][55];
int vis[55][55][55];
int dir[6][3]{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1}};
int T, a, b, c;
struct Node
{
    int x;
    int y;
    int z;
    int t;
};
int bfs()
{
    if (a == 1 && b == 1 && c == 1)
    {
        return 0;
    }
    Node cur, nex;
    cur.x = cur.y = cur.z = 1;
    cur.t = 0;
    queue<Node> qu;
    qu.push(cur);
    vis[1][1][1] = 1;
    nex.y = nex.x = nex.y = 1;
    nex.t = 0;

    while (!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        if (cur.x == a && cur.y == b && cur.z == c)
        {
            if (cur.t > T)
                return -1;
            else
                return cur.t;
        }
        for (int i = 0; i < 6; i++)
        {
            int ttx = cur.x + dir[i][0];
            int tty = cur.y + dir[i][1];
            int ttz = cur.z + dir[i][2];
            if (!map1[ttx][tty][ttz] && ttx >= 1 && tty >= 1 && ttz >= 1 && ttx <= a && tty <= b && ttz <= c)
            {
                nex.t = cur.t + 1;
                nex.x = ttx;
                nex.y = tty;
                nex.z = ttz;
                if (!vis[ttx][tty][ttz])
                {
                    vis[ttx][tty][ttz] = 1;
                    qu.push(nex);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(map1, 0, sizeof(map1));
        memset(vis, 0, sizeof(vis));
        scanf("%d %d %d %d", &a, &b, &c, &T);

        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                for (int k = 1; k <= c; k++)
                    scanf("%d", &map1[i][j][k]);
        int r = bfs();
        cout << r << endl;
    }
}