#include <iostream>
using namespace std;
class Tree
{
private:
	int ages;

public:
	Tree(int a = 0) : ages(a){};
	void grow(int years)
	{
		ages += years;
	}
	void age()
	{
		cout << ages << endl;
	}
};
int main()
{
	Tree t1(10);
	t1.grow(10);
	t1.age();
	return 0;
	return 0;
}