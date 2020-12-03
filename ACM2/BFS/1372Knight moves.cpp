#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dir[8][2] = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}};
int vis[9][9];
int endx, endy;
char s1[3], s2[3];
struct Node
{
    int x, y, step;
};

void bfs()
{
    Node cur, next;
    memset(vis, 0, sizeof(vis));
    cur.step = 0;
    cur.x = s1[0] - 'a' + 1;
    cur.y = s1[1] - '1' + 1;
    queue<Node> qu;
    qu.push(cur);
    endx = s2[0] - 'a' + 1;
    endy = s2[1] - '1' + 1;
    vis[cur.x][cur.y] = 1;
    while (!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        if (cur.x == endx && cur.y == endy)
        {
            cout << "To get from " << s1 << " to " << s2 << " takes " << cur.step << " knight moves." << endl;
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x >= 1 && next.x <= 8 && next.y >= 1 && next.y <= 8)
            {
                next.step = cur.step + 1;
                vis[next.x][next.y] = 1;
                qu.push(next);
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
}