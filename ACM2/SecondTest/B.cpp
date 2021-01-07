#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct student
{
	string name;
	int age;
	double score;
} stu[105];
bool cmp(student a, student b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return a.name < b.name;
}
int main()
{
	int n;

	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> stu[i].name >> stu[i].age >> stu[i].score;
		sort(stu, stu + n, cmp);
		for (int i = 0; i < n; i++)
		{
			cout << stu[i].name << " " << stu[i].age << " ";
			printf("%.2f\n", stu[i].score);
		}
	}
}