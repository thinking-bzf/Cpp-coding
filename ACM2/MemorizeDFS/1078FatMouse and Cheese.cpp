#include <iostream>
#include <cstring>
using namespace std;
int ans[105][105];
int Map[105][105];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, k;
bool check(int x, int y)
{
    if (x >= n || x < 0 || y < 0 || y >= n)
        return false;
    return true;
}
int dfs(int x, int y)
{
    int answer = 0;
    if (ans[x][y])
        return ans[x][y];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int xx = x + dir[i][0] * j;
            int yy = y + dir[i][1] * j;
            if (check(xx, yy) && Map[x][y] < Map[xx][yy])
                answer = max(answer, dfs(xx, yy));
        }
    }
    ans[x][y] = answer + Map[x][y];
    return ans[x][y];
}

int main()
{
    while (cin >> n >> k)
    {
        if (n == -1 && k == -1)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = 0;
                Map[i][j] = 0;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> Map[i][j];
        cout << dfs(0, 0) << endl;
    }
}