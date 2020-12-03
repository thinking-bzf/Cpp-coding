#include <iostream>
#define PI 3.14
using namespace std;
class Circle
{
private:
	double radius;
	int cnt;

public:
	Circle(double a, int cnt = 1) : radius(a) {}
	double getArea();
	operator int() const;
	operator double() const;
};
double Circle::getArea()
{
	return radius * radius * PI;
}
Circle::operator int() const
{
	return radius;
}
Circle::operator double() const
{
	return radius;
}
int main()
{
	Circle c1(2.21, 2);
	int a = c1;
	cout << int(c1) << endl;
	cout << a << endl;
	cout << c1.getArea() << endl;
	return 0;
}