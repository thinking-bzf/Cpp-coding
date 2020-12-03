#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int vis[102][102];
int s, n, m;
struct Node
{
    int n, m, s, t; //n为大的杯子
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
    return 0;
}
void bfs()
{
    Node cur, nex;
    memset(vis, 0, sizeof(vis));
    queue<Node> qu;
    cur.m = cur.n = cur.t = 0;
    cur.s = s;
    qu.push(cur);
    vis[n][m] = 1;
    while (!qu.empty())
    {
        cur = qu.front();
        if (cur.s == s / 2 && cur.n == s / 2)
        {
            cout << cur.t << endl;
            return;
        }
        if (cur.s && cur.n != n) //s->n
        {
            int c = n - cur.n;
            if (cur.s > c)
            {
                nex.n = n;
                nex.s = cur.s - c;
            }
            else
            {
                nex.s = 0;
                nex.n = cur.s + cur.n;
            }
            nex.m = cur.m;
            nex.t = cur.t + 1;
            if (!vis[nex.n][nex.m])
            {
                qu.push(nex);
                vis[nex.n][nex.m] = 1;
            }
        }
        if (cur.n && cur.s != s) //n->s
        {
            int c = s - cur.s;
            if (cur.n > c)
            {
                nex.s = s;
                nex.n = cur.n - c;
            }
            else
            {
                nex.n = 0;
                nex.s = cur.s + cur.n;
            }
            nex.m = cur.m;
            nex.t = cur.t + 1;
            if (!vis[nex.n][nex.m])
            {
                qu.push(nex);
                vis[nex.n][nex.m] = 1;
            }
        }
        if (cur.s && cur.m != m) //s->m
        {
            int c = m - cur.m;
            if (cur.s > c)
            {
                nex.m = m;
                nex.s = cur.s - c;
            }
            else
            {
                nex.s = 0;
                nex.m = cur.s + cur.m;
            }
            nex.n = cur.n;
            nex.t = cur.t + 1;
            if (!vis[nex.n][nex.m])
            {
                qu.push(nex);
                vis[nex.n][nex.m] = 1;
            }
        }
        if (cur.m && cur.s != s) //m->s
        {
            int c = s - cur.s;
            if (cur.m > c)
            {
                nex.s = s;
                nex.m = cur.m - c;
            }
            else
            {
                nex.m = 0;
                nex.s = cur.s + cur.m;
            }
            nex.n = cur.n;
            nex.t = cur.t + 1;
            if (!vis[nex.n][nex.m])
            {
                qu.push(nex);
                vis[nex.n][nex.m] = 1;
            }
        }
        if (cur.m && cur.n != n) //m->n
        {
            int c = n - cur.n;
            if (cur.m > c)
            {
                nex.n = n;
                nex.m = cur.m - c;
            }
            else
            {
                nex.m = 0;
                nex.n = cur.n + cur.m;
            }
            nex.s = cur.s;
            nex.t = cur.t + 1;
            if (!vis[nex.n][nex.m])
            {
                qu.push(nex);
                vis[nex.n][nex.m] = 1;
            }
        }
        if (cur.n && cur.m != m) //n->m
        {
            int c = m - cur.m;
            if (cur.n > c)
            {
                nex.m = m;
                nex.n = cur.n - c;
            }
            else
            {
                nex.n = 0;
                nex.m = cur.m + cur.n;
            }
            nex.s = cur.s;
            nex.t = cur.t + 1;
            if (!vis[nex.n][nex.m])
            {
                qu.push(nex);
                vis[nex.n][nex.m] = 1;
            }
        }
        qu.pop();
    }
    cout << "NO" << endl;
}
