#include <iostream>
#include <queue>
using namespace std;
int vis[15][15];
char Map[15][15];
int n, m;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int sx, sy, ex, ey;
struct pos
{
	int step;
	int x;
	int y;
};

int bfs();
int main()
{
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> Map[i] + 1;
			for (int j = 1; j <= m; j++)
			{
				vis[i][j] = 0;
			}
		}
		cin >> sx >> sy >> ex >> ey;
		Map[sx][sy] = '.';
		int result = bfs();
		cout << result << endl;
	}
}
int bfs()
{
	pos cur, next;
	cur.x = sx;
	cur.y = sy;
	cur.step = 0;
	queue<pos> qu;
	qu.push(cur);
	vis[sx][sy] = 1;
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		if (cur.x == ex && cur.y == ey)
		{
			return cur.step;
		}
		for (int i = 0; i < 4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.step = cur.step + 1;
			if (next.x < 1 || next.y < 1 || next.x > n || next.y > m)
				continue;
			if (Map[next.x][next.y] == '*')
			{
				next.x += dir[i][0];
				next.y += dir[i][1];
				if (Map[next.x][next.y] == '*')
					continue;
				if (!vis[next.x][next.y])
				{
					vis[next.x][next.y] = 1;
					qu.push(next);
				}
			}
			else
			{
				if (!vis[next.x][next.y])
				{
					vis[next.x][next.y] = 1;
					qu.push(next);
				}
			}
		}
	}
	return -1;
}