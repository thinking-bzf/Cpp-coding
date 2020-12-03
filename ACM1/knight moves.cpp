#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int vis[9][9];
char s1[3], s2[3], ex, ey;
struct Node
{
    int x;
    int y;
    int s;
};
void bfs()
{
    Node cur, nex;
    memset(vis, 0, sizeof(vis));
    cur.s = 0;
    cur.x = s1[0] - 'a' + 1;
    cur.y = s1[1] - '1' + 1;
    queue<Node> qu;
    ex = s2[0] - 'a' + 1;
    ey = s2[1] - '1' + 1;
    qu.push(cur);
    vis[cur.x][cur.y] = 1;
    while (!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        if (cur.x == ex && cur.y == ey)
        {
            cout << "To get from " << s1 << " to " << s2 << " takes " << cur.s << " knight moves." << endl;
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            nex.x = cur.x + dir[i][0];
            nex.y = cur.y + dir[i][1];
            if (nex.x >= 1 && nex.x <= 8 && nex.y >= 1 && nex.y <= 8)
            {
                nex.s = cur.s + 1;
                vis[nex.x][nex.y] = 1;
                qu.push(nex);
            }
        }
    }
}
int main()
{
    while (~scanf("%s%s", s1, s2))
    {
        bfs();
    }
    return 0;
}