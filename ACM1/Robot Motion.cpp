#include <bits/stdc++.h>
#include <cstring>
using namespace std;
char Map[15][15];
int flag;
int n, m, t;
int vis[15][15];
int judge;
int step;
int beloop, loop;

bool check(int x, int y)
{
	if (x >= n || y >= m || x < 0 || y < 0)
	{
		judge = true;
		return false;
	}
	return true;
}
void dfs(int i, int j, int s)
{
	if (!check(i, j))
		return;
	step = s;
	if (!judge)
	{
		if (!vis[i][j])
		{
			vis[i][j] = s;
			if (Map[i][j] == 'N')
				dfs(i - 1, j, s + 1);
			else if (Map[i][j] == 'S')
				dfs(i + 1, j, s + 1);
			else if (Map[i][j] == 'E')
				dfs(i, j + 1, s + 1);
			else if (Map[i][j] == 'W')
				dfs(i, j - 1, s + 1);
		}
		else
		{
			beloop = vis[i][j] - 1;
			loop = s - vis[i][j];
		}
	}
}

int main()
{
	while (cin >> n >> m >> t)
	{
		if (n == 0 && m == 0)
			break;
		t--;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			cin >> Map[i];
		judge = 0;
		dfs(0, t, 1);
		if (judge)
			printf("%d step(s) to exit\n", step);
		else
			printf("%d step(s) before a loop of %d step(s)\n", beloop, loop);
	}
}