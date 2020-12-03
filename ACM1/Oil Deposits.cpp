#include <bits/stdc++.h>
using namespace std;
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
char mp[105][105];
int m, n;
void dfs(int x, int y)
{
    int tx, ty;
    for (int i = 0; i < 8; i++)
    {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (tx < 0 || ty < 0 || tx >= m || ty >= n)
            continue;
        if (mp[tx][ty] == '@')
        {
            mp[tx][ty] = '*';
            dfs(tx, ty);
        }
    }
    return;
}

int main()
{
    while (cin >> m >> n)
    {
        int cnt = 0;
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            cin >> mp[i];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mp[i][j] == '@')
                {
                    mp[i][j] = '*';
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}