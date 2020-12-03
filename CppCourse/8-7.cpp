#include <iostream>
using namespace std;
class Point
{
private:
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}
    Point &operator++();
    Point operator++(int);
    Point &operator--();
    Point operator--(int);
    void showxy() { cout << x << " " << y << endl; }
};
Point &Point::operator++()
{
    x++;
    y++;
    return *this;
}
Point Point::operator++(int)
{
    Point old = *this;
    x++;
    y++;
    return old;
}
Point &Point::operator--()
{
    x--;
    y--;
    return *this;
}
Point Point::operator--(int)
{
    Point old = *this;
    x--;
    y--;
    return old;
}
int main()
{
    Point p1(5, 5);
    cout << "p1:";
    p1.showxy();
    cout << "p1++:";
    (p1++).showxy();
    cout << "++p1:";
    (++p1).showxy();
    cout << "p1--:";
    (p1--).showxy();
    cout << "--p1:";
    (--p1).showxy();
}