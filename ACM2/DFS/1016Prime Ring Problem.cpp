#include <iostream>
#include <cstring>
using namespace std;

int vis[30];
int a[30];
int n;

bool Prime(int x)
{
    for (int i = 2; i < x / 2; i++)
        if (x % i == 0)
            return false;
    return true;
}
void dfs(int step)
{
    // 判断是否达到
    if (step == n + 1 && Prime(a[1] + a[n]))
    {
        for (int i = 1; i < n; i++)
            cout << a[i] << " ";
        cout << a[n] << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0 && Prime(i + a[step - 1]))
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
    int count = 1;
    a[1] = 1;
    while (cin >> n)
    {
        memset(vis, 0, sizeof(vis));
        cout << "Case " << count << ":" << endl;
        // 第一个质数必为1，所以从2开始
        dfs(2);
        count++;
        cout << endl;
    }
}