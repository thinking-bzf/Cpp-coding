#include <bits/stdc++.h>
#include <cmath>
using namespace std;
char Map[9][9];
int n, m, t, di, dj;
int escape;
int dir[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int si, int sj, int cnt);

int main()
{
    int si, sj;
    while (cin >> n >> m >> t)
    {
        int wall = 0;
        if (n == 0 && m == 0 && t == 0)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> Map[i][j];
                if (Map[i][j] == 'X')
                    wall++;
                else if (Map[i][j] == 'D')
                {
                    di = i;
                    dj = j;
                }
                else if (Map[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
            }
        if (n * m - wall <= t)
        {
            cout << "NO" << endl;
            continue;
        }
        escape = 0;
        Map[si][sj] = 'X';
        dfs(si, sj, 0);
        if (escape)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
void dfs(int si, int sj, int cnt)
{
    int i, temp;
    if (si > n || sj > m || si <= 0 || sj <= 0)
        return;
    if (si == di && sj == dj && cnt == t)
        escape = 1;
    if (escape)
        return;
    temp = (t - cnt) - abs(si - di) - abs(sj - dj);
    if (temp < 0 || temp % 2 == 1)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (Map[si + dir[i][0]][sj + dir[i][1]] != 'X')
        {
            Map[si + dir[i][0]][sj + dir[i][1]] = 'X';
            dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);
            Map[si + dir[i][0]][sj + dir[i][1]] = '.';
        }
    }
    return;
}