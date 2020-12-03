#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1005];
int last[1005];
struct node
{
    int s;
    int v;
    int num;
} a[1010];
int cmp(node a, node b)
{
    if (a.v != b.v)
        return a.v < b.v;
    else
        return a.s < b.s;
}
int main()
{
    int n = 0;
    memset(last, -1, sizeof(last));
    while (~scanf("%d%d", &a[n].v, &a[n].s))
    {
        a[n].num = n + 1;
        n++;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i].s < a[j].s)
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    last[a[i].num] = a[j].num;
                }
            }
        }
    }
    int maxx = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxx)
        {
            maxx = dp[i];
            t = a[i].num;
        }
    }
    printf("%d\n", maxx);
    int sta[1005];
    int top = 0;
    for (int i = t; i != -1; i = last[i])
    {
        sta[top++] = i;
    }
    while (top > 0)
    {
        printf("%d\n", sta[--top]);
    }
}