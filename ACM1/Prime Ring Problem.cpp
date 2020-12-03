#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int vis[30];
int a[30];
int n;

bool prime(int x)
{
    for (int i = 2; i < x / 2; i++)
        if (x % i == 0)
            return false;
    return true;
}
void dfs(int step)
{
    if (step == n + 1 && prime(a[1] + a[n]))
    {
        for (int i = 1; i < n; i++)
            cout << a[i] << " ";
        cout << a[n] << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i] && prime(i + a[step - 1]))
        {
            vis[i] = 1;
            a[step] = i;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    int kase = 0;
    a[1] = 1;
    while (cin >> n)
    {
        memset(vis, 0, sizeof(vis));
        printf("Case %d:\n", ++kase);
        dfs(2);
        cout << endl;
    }
}