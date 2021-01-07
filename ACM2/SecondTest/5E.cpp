#include <iostream>
#include <cstring>
using namespace std;
int W[35][35][35];

int dfs(int a, int b, int c)
{
	int answer = 0;
	if (W[a][b][c])
		return W[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0)
		answer = 1;
	else if (a > 20 || b > 20 || c > 20)
		answer = dfs(20, 20, 20);
	else if (a < b && b < c)
		answer = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	else
	{
		answer = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
	}
	W[a][b][c] = answer;
	return W[a][b][c];
}

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		memset(W, 0, sizeof(W));
		cout << dfs(a, b, c) << endl;
	}
}