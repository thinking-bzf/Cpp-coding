#include <iostream>
#include <cstring>
using namespace std;
#define N 10001
int pre[N];
int vis[N];
int flag = 1;
int maxn = 0;
void init()
{
    for (int i = 0; i <= N; i++)
        pre[i] = i;
    memset(vis, 0, sizeof(vis));
    flag = 1;
}
int findx(int a)
{
    int r = a;
    while (r != pre[r])
    {
        r = pre[r];
    }
    return r;
}
void merge(int a, int b)
{
    // a->b
    int t1 = findx(a);
    int t2 = findx(b);
    // t2!=b 表示b节点已经被指向过 不能再被指向
    if (t2 != b || t1 == t2)
        flag = 0;
    else if (t1 != t2)
        pre[b] = a;
}
int main()
{
    int kase = 0;
    int a, b;
    init();
    while (cin >> a >> b && a >= 0 && b >= 0)
    {
        if (a == 0 && b == 0)
        {
            int sum = 0;
            for (int i = 1; i <= maxn; i++)
            {
                if (pre[i] == i && vis[i])
                    sum++;
                if (sum > 1)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                printf("Case %d is not a tree.\n", ++kase);
            else if (flag && sum <= 1)
                printf("Case %d is a tree.\n", ++kase);
            init();
            continue;
        }
        // 获取树的最大编号
        maxn = max(maxn, max(a, b));
        vis[a] = vis[b] = 1;
        merge(a, b);
    }
}