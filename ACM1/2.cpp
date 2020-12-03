#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int N, M, T;
char maze[10][10];
char v[10][10];
int suc;
void dfs(int i, int j, int t)
{
	if (maze[i][j] == 'D')
	{
		if (t <= T)
			suc = 1;
		return;
	}
	if (t > T)
		return;
	v[i][j] = 1;
	if (v[i - 1][j] != 1 && maze[i - 1][j] != 'X' && i - 1 >= 0)
		dfs(i - 1, j, t + 1);
	if (v[i][j - 1] != 1 && maze[i][j - 1] != 'X' && j - 1 >= 0)
		dfs(i, j - 1, t + 1);
	if (v[i + 1][j] != 1 && maze[i + 1][j] != 'X' && i + 1 < N)
		dfs(i + 1, j, t + 1);
	if (v[i][j + 1] != 1 && maze[i][j + 1] != 'X' && j + 1 < M)
		dfs(i, j + 1, t + 1);
	v[i][j] = 2;
}
int main()
{
	while (cin >> N >> M >> T && N + M + T)
	{
		suc = 0;
		memset(v, 0, sizeof(v));
		int si, sj, di, dj;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				if (maze[i][j] == 'D')
				{
					di = i;
					dj = j;
				}
			}
		dfs(si, sj, 0);
		if (suc)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
