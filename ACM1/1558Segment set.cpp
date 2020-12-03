#include <iostream>
#include <cstring>
#define MaxSize 1005
using namespace std;
int set[1005];
struct Points
{
	double x, y;
};
struct Segments
{
	Points A, B;
} Segment[MaxSize];
int findx(int x)
{
	while (set[x] != x)
		x = set[x];
	return x;
}
void marge(int a, int b)
{
	if (findx(a) != findx(b))
		set[findx(a)] = findx(b);
}
double Matrix(Points a, Points b, Points c)
{
	double x1 = c.x - a.x;
	double y1 = c.y - a.y;
	double x2 = b.x - a.x;
	double y2 = b.y - a.y;
	return x1 * y2 - x2 * y1;
}

bool OnSegment(Points a, Points b, Points c)
{
	double MinX = min(a.x, b.x);
	double MaxX = max(a.x, b.x);
	double MinY = min(a.y, b.y);
	double MaxY = max(a.y, b.y);
	if (c.x >= MinX && c.x <= MaxX && c.y >= MinY && c.y <= MaxY)
		return true;
	return false;
}
bool Interset(Segments a, Segments b)
{
	Points p1 = a.A, p2 = a.B;
	Points p3 = b.A, p4 = b.B;

	double d1 = Matrix(p3, p4, p1);
	double d2 = Matrix(p3, p4, p2);
	double d3 = Matrix(p1, p2, p3);
	double d4 = Matrix(p1, p2, p4);

	if (d1 * d2 < 0 && d3 * d4 < 0)
		return true;
	else if (d1 == 0 && OnSegment(p3, p4, p1))
		return true;
	else if (d2 == 0 && OnSegment(p3, p4, p2))
		return true;
	else if (d3 == 0 && OnSegment(p1, p2, p3))
		return true;
	else if (d4 == 0 && OnSegment(p1, p2, p4))
		return true;
	else
		return false;
}

int main()
{
	int c;

	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		memset(set, 0, sizeof(set));
		for (int i = 1; i <= n; i++)
			set[i] = i;
		int count = 0;

		char B, C;
		for (int i = 1; i <= n; i++)
		{
			scanf("%c%c", &B, &C);
			if (C == 'P')
			{
				count++;
				cin >> Segment[count].A.x >> Segment[count].A.y >> Segment[count].B.x >> Segment[count].B.y;
				for (int i = 1; i < count; i++) //和自己相交不算
				{
					if (Interset(Segment[i], Segment[count]))
						if (findx(i) != findx(count))
							marge(i, count);
				}
			}
			else if (C == 'Q')
			{
				int sum = 0;
				int k;
				cin >> k;
				for (int i = 1; i <= count; i++)
				{
					if (findx(i) == findx(k))
						sum++;
				}
				cout << sum << endl;
			}
		}
		if(c)
		{
			cout << endl;
		}
		
	}
}