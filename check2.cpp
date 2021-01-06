#include <iostream>
#include <cstring>
using namespace std;
int mp[102][102];
int ans[102][102];
int n, m, t;
int dfs(int x, int y)
{
    if (ans[x][y] >= 0)
        return ans[x][y];
    ans[x][y] = 0;
    for (int i = 0; i <= mp[x][y]; i++)
        for (int j = 0; j <= mp[x][y] - i; j++)
        {
            if (x + i >= 1 && x + i <= n && y + j <= m && y + j >= 1)
                ans[x][y] = (dfs(x + i, y + j) + ans[x][y]) % 10000;
        }
    return ans[x][y];
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(ans, -1, sizeof(ans));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &mp[i][j]);
        ans[n][m] = 1;
        printf("%d\n", dfs(1, 1));
    }
    return 0;
}
