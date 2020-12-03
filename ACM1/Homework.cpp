#include <iostream>
#include <algorithm>
using namespace std;
struct HW
{
	int time;
	int value;
	int flag;
};
bool cmp(HW a, HW b)
{
	if (a.time != b.time)
		return a.time < b.time;
	return a.value > b.value;
}
int main()
{
	HW hw[1008] = {0};
	int T, n, day, sum;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		day = 1;
		sum = 0;
		cin >> n;
		for (int p = 0; p < n; p++)
		{
			hw[p].flag = 0;
			hw[p].time = 0;
			hw[p].value = 0;
		}
		for (int j = 0; j < n; j++)
			cin >> hw[j].time;
		for (int j = 0; j < n; j++)
			cin >> hw[j].value;
		sort(hw, hw + n, cmp);
		for (int k = 0; k < n; k++)
		{
			if (day <= hw[k].time)
			{
				hw[k].flag = 1;
				day++;
			}
			else
			{
				int min_index = k;
				for (int q = 0; q < k; q++)
					if (hw[q].value < hw[min_index].value && hw[q].flag == 1)
						min_index = q;
				if (min_index != k)
				{
					hw[min_index].flag = 0;
					hw[k].flag = 1;
				}
			}
		}
		for (int k = 0; k < n; k++)
			if (hw[k].flag == 0)
				sum += hw[k].value;
		cout << sum << endl;
	}
}