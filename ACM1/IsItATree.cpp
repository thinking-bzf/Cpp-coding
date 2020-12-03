#include <iostream>
#include <cstring>
using namespace std;
int set[10010];
bool temp[10010];
int main()
{
	int m, n, a, k = 1, b;
	bool flag;
	while (cin >> m >> n && (m > 0 || n > 0))
	{
		for (int i = 0; i < 10001; i++)
		{
			temp[i] = false;
			set[i] = i;
		}
		set[m] = n;
		temp[m] = true;
		temp[n] = true;
		flag = false;
		while (cin >> a >> b && a != 0 || b != 0)
		{
			temp[a] = true;
			temp[b] = true;
			if (set[b] != b) //判断该节点是否已被指向，用来判断环
				flag = true;
			else
				set[b] = a;
		}
		if (flag)
			cout << "Case " << k++ << " is not a tree." << endl;
		else
		{
			int sum = 0;
			for (int i = 0; i < 10001; i++)
			{
				if (temp[i] && set[i] == i)
					sum++;
				if (sum > 1)
					break;
			}
			if (sum != 1)
				cout << "Case " << k++ << " is not a tree." << endl;
			else
				cout << "Case " << k++ << " is a tree." << endl;
		}
	}
}