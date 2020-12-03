#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student
{
	char name[15];
	int age;
	double score;
} S[105];

bool cmp(Student a, Student b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
	{
		if (a.age != b.age)
			return a.age < b.age;
		return strcmp(a.name, b.name) == -1;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> S[i].name >> S[i].age >> S[i].score;
		sort(S, S + n, cmp);
		for (int i = 0; i < n; i++)
		{
			printf("%s %d %.2f", S[i].name, S[i].age, S[i].score);
			cout << endl;
		}
	}
}