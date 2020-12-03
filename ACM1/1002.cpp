#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int map1[2005][2005];
int dis[2005][2005];
struct Node
{
    int x;
    int y;
    int dis;
};
int main()
{
    int T;
    cin >> T;
    int n, m, k;
    int cx, cy, x, y;
    while (T--)
    {
        Node Min;
        Min.dis = 0x3f3f3f3f;
        memset(map1, 0, sizeof(map1));
        memset(dis, 0, sizeof(dis));
        cin >> n >> m >> k;
        cx = (n + 1) / 2;
        cy = m / 2;
        for (int i = 1; i <= k; i++)
        {
            cin >> x >> y;
            map1[x][y] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dis[i][j] = abs(i - cx) + abs(j - cy);
                if (dis[i][j] < Min.dis && (map1[i][j] == 0 && map1[i][j + 1] == 0) && i < n && j < m)
                {
                    Min.dis = dis[i][j];
                    Min.x = i;
                    Min.y = j;
                }
            }
        if (Min.dis > 10000)
            cout << -1 << endl;
        else
            printf("(%d,%d) (%d,%d)\n", Min.x, Min.y, Min.x, Min.y + 1);
    }
}