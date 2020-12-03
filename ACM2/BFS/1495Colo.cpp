#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int vis[105][105];
// s表示可乐的体积，n,m为两个杯子的体积
int s, n, m;
struct Node
{
    int s, n, m, step;
};
void bfs();
int main()
{
    while (cin >> s >> n >> m && (s > 0 && n > 0 && m > 0))
    {
        if (s % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        if (n < m)
        {
            int temp = n;
            n = m;
            m = temp;
        }
        bfs();
    }
}
void bfs()
{
    Node cur, next;
    memset(vis, 0, sizeof(vis));
    queue<Node> qu;
    cur.m = cur.n = cur.step = 0;
    cur.s = s;
    qu.push(cur);
    vis[n][m] = 1;
    while (!qu.empty())
    {
        cur = qu.front();

        if (cur.s == s / 2 && cur.n == s / 2)
        {
            cout << cur.step << endl;
            return;
        }
        // s->n
        if (cur.s && cur.n != n)
        {
            int c = n - cur.n;
            if (cur.s >= c)
            {
                next.n = n;
                next.s = cur.s - c;
            }
            else
            {
                next.n = cur.n + cur.s;
                next.s = 0;
            }
            next.step = cur.step + 1;
            next.m = cur.m;
            if (!vis[next.n][next.m])
            {
                vis[next.n][next.m] = 1;
                qu.push(next);
            }
        }
        // n->s
        if (cur.n && cur.s != s)
        {
            int c = s - cur.s;
            if (cur.n >= c)
            {
                next.s = s;
                next.n = cur.n - c;
            }
            else
            {
                next.s = cur.s + cur.n;
                next.n = 0;
            }
            next.step = cur.step + 1;
            next.m = cur.m;
            if (!vis[next.n][next.m])
            {
                vis[next.n][next.m] = 1;
                qu.push(next);
            }
        }
        // n->m
        if (cur.n && cur.m != m)
        {
            int c = m - cur.m;
            if (cur.n > c)
            {
                next.m = m;
                next.n = cur.n - c;
            }
            else
            {
                next.n = 0;
                next.m = cur.m + cur.n;
            }
            next.step = cur.step + 1;
            next.s = cur.s;
            if (!vis[next.n][next.m])
            {
                vis[next.n][next.m] = 1;
                qu.push(next);
            }
        }
        // m->n
        if (cur.m && cur.n != n)
        {
            int c = n - cur.n;
            if (cur.m > c)
            {
                next.n = n;
                next.m = cur.m - c;
            }
            else
            {
                next.m = 0;
                next.n = cur.m + cur.n;
            }
            next.step = cur.step + 1;
            next.s = cur.s;
            if (!vis[next.n][next.m])
            {
                vis[next.n][next.m] = 1;
                qu.push(next);
            }
        }
        // s->m
        if (cur.s && cur.m != m)
        {
            int c = m - cur.m;
            if (cur.s >= c)
            {
                next.m = m;
                next.s = cur.s - c;
            }
            else
            {
                next.m = cur.m + cur.s;
                next.s = 0;
            }
            next.step = cur.step + 1;
            next.n = cur.n;
            if (!vis[next.n][next.m])
            {
                vis[next.n][next.m] = 1;
                qu.push(next);
            }
        }
        // m->s
        if (cur.m && cur.s != s)
        {
            int c = s - cur.s;
            if (cur.m >= c)
            {
                next.s = s;
                next.m = cur.m - c;
            }
            else
            {
                next.s = cur.s + cur.m;
                next.m = 0;
            }
            next.step = cur.step + 1;
            next.n = cur.n;
            if (!vis[next.n][next.m])
            {
                vis[next.n][next.m] = 1;
                qu.push(next);
            }
        }
        qu.pop();
    }
    cout << "NO" << endl;
}