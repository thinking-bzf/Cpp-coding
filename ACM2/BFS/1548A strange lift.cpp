#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
// 输入的变量设为全局变量
int N, A, B;
int vis[202];
int a[202];
struct pos
{
    int step;  //记录现在的所走的步数
    int level; //记录目前所在的层数
};
void bfs();
int main()
{
    while (cin >> N && N != 0)
    {
        cin >> A >> B;
        for (int i = 1; i <= N; i++)
        {
            // 输入每层的跳转机制，并且把vis设为0，指没有被访问过
            cin >> a[i];
            vis[i] = 0;
        }
        bfs();
    }
}
void bfs()
{
    pos cur, next;
    cur.level = A;
    cur.step = 0;
    queue<pos> qu;
    qu.push(cur);
    vis[A] = 1;
    while (!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        if (cur.level == B)
        {
            cout << cur.step << endl;
            return;
        }
        next.level = cur.level + a[cur.level];
        next.step = cur.step + 1;
        if (next.level <= N)
        {
            if (!vis[next.level])
            {
                vis[next.level] = 1;
                qu.push(next);
            }
        }
        next.level = cur.level - a[cur.level];
        next.step = cur.step + 1;
        if (next.level >= 1)
        {
            if (!vis[next.level])
            {
                vis[next.level] = 1;
                qu.push(next);
            }
        }
    }
    cout << -1 << endl;
    return;
}