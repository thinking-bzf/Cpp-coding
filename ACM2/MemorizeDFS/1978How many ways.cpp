#include <iostream>
#include <cstring>
using namespace std;
int Map[105][105];
int ans[105][105];
int n, m;
int check(int x, int y)
{
    if (x < 1 || x > m || y < 1 || y > n)
        return false;
    return true;
}

int dfs(int x, int y)
{
    if (ans[x][y] >= 0)
        return ans[x][y];
    ans[x][y] = 0;
    for (int i = 0; i <= Map[x][y]; i++)
        for (int j = 0; j <= Map[x][y] - i; j++)
        {
            int xx = x + i;
            int yy = y + j;
            if (check(xx, yy))
                ans[x][y] = (dfs(xx, yy) + ans[x][y]) % 10000;
        }
    return ans[x][y];
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        cin >> m >> n;
        memset(ans, -1, sizeof(ans));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> Map[i][j];
        ans[m][n] = 1;
        cout << dfs(1, 1) << endl;
    }
}