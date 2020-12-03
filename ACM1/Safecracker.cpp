#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int vis[15], per[30][8];
int num[6], t[6];
char a[15];
int n, sum, flag;
void init()
{
	for (int i = 1; i <= 26; i++)
	{
		per[i][0] = 1;
		for (int j = 1; j <= 5; j++)
			per[i][j] = per[i][j - 1] * i;
	}
}

bool check() //ÅÐ¶Ï×ÖµäÐò
{
	for (int i = 0; i < 5; i++)
	{
		if (num[i] > t[i])
			return 1;
		if (num[i] < t[i])
			return 0;
	}
}
void dfs(int cur)
{
	if (cur == 5)
	{
		int k = per[num[0]][1] - per[num[1]][2] + per[num[2]][3] - per[num[3]][4] + per[num[4]][5];
		if (k == sum && check())
		{
			for (int i = 0; i < 5; i++)
				t[i] = num[i];
			flag = 1;
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			num[cur] = a[i] - 'A' + 1;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	init();
	while (cin >> sum >> a)
	{
		if (!sum && strcmp(a, "END") == 0)
			break;
		memset(t, 0, sizeof(t));
		memset(num, 0, sizeof(num));
		memset(vis, 0, sizeof(vis));
		n = strlen(a);
		flag = 0;
		dfs(0);
		if (flag)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << (char)(t[i] + 'A' - 1);
			}
		}
		else
		{
			cout << "no solution";
		}
		cout << endl;
	}
}
