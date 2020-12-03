#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
char Map[15][15];
int mark[15][15];
int dis[15][15];
int sx, ex, sy, ey;
int n, m;
const int INF = 1e9 + 11;
int mov[5][5] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans, flag;
struct WZ
{
	int x, y;
};

int main()
{

	while (cin >> n >> m)
	{

		for (int i = 1; i <= n; i++)
		{
			cin >> Map[i] + 1;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				dis[i][j] = INF;
				memset(mark, 0, sizeof(mark));
			}
		flag = 0;
		cin >> sx >> sy >> ex >> ey;
		WZ u, v;
		queue<WZ> Q;
		u.x = sx, u.y = sy;
		Q.push(u);
		mark[sx][sy] = 1;
		dis[sx][sy] = 0;
		while (!Q.empty())
		{
			u = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				v = u;
				v.x += mov[i][0];
				v.y += mov[i][1];
				if ((v.x < 1 || v.x > n || v.y < 1 || v.y > m))
				{
					if (Map[v.x][v.y] == '*')
					{
						if (Map[v.x + mov[i][0]][v.y + mov[i][1]] != '.')
							continue;
						v.x += mov[i][0];
						v.y += mov[i][1];
					}
					if (!mark[v.x][v.y] && dis[v.x][v.y] > dis[u.x][u.y] + 1)
					{
						dis[v.x][v.y] = dis[u.x][u.y] + 1;
						Q.push(v);
						mark[v.x][v.y] = 1;
						if (v.x == ex && v.y == ey)
							flag = 1;
					}
				}
			}
		}
		if (!flag)
			cout << "-1" << endl;
		else
			cout << dis[ex][ey] << endl;
	}
}