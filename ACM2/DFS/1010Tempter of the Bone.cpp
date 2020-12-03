#include <iostream>
using namespace std;
int n, m, time, dx, dy;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char Map[10][10];
// 判断是否逃出
bool escape;
void dfs(int sx, int sy, int t);
int main()
{
    while (cin >> n >> m >> time)
    {
        if (n == 0 && m == 0 && time == 0)
            break;
        int wall = 0;
        int sx, sy;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> Map[i][j];
                if (Map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if (Map[i][j] == 'D')
                {
                    dx = i;
                    dy = j;
                }
                if (Map[i][j] == 'X')
                    wall++;
            }
        }
        if (n * m - wall <= time)
        {
            cout << "NO" << endl;
            continue;
        }
        escape = 0;
        Map[sx][sy] = 'X';
        dfs(sx, sy, 0);
        if (escape == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

void dfs(int sx, int sy, int t)
{
    if (sx > n || sy > m || sx <= 0 || sy <= 0)
        return;
    if (sx == dx &&sy == dy &&t == time)
        escape = 1;
    if (escape)
        return;
    int temp = (time - t) - abs((sx - dx) + (sy - dy));
    if (temp < 0 || temp % 2)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (Map[sx + dir[i][0]][sy + dir[i][1]] != 'X')
        {
            Map[sx + dir[i][0]][sy + dir[i][1]] = 'X';
            dfs(sx + dir[i][0], sy + dir[i][1], t + 1);
            Map[sx + dir[i][0]][sy + dir[i][1]] = '.';
        }
    }
    return;
}