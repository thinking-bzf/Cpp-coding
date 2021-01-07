#include <iostream>
#include <algorithm>

using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int edges[3];
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		for (int i = 0; i < 3; i++)
			cin >> edges[i];
		sort(edges, edges + 3, cmp);
		if (edges[0] >= edges[1] + edges[2])
		{
			cout << "Impossible!" << endl;
		}
		else
		{
			if (edges[0] * edges[0] == (edges[1] * edges[1] + edges[2] * edges[2]))
				cout << "Right triangle" << endl;
			if (edges[0] * edges[0] < (edges[1] * edges[1] + edges[2] * edges[2]))
				cout << "Acute triangle" << endl;
			if (edges[0] * edges[0] > (edges[1] * edges[1] + edges[2] * edges[2]))
				cout << "Obtuse triangle" << endl;
		}
	}
}