//编写程序，定义抽象基类模板Shape(形状)，由它派生出2个派生类模板: Circle(圆形)和Square (正方形)，
//用函数ShowArea()分别显示各种图形的面积。
//要求用deque容器存储圆形对象和正方形对象，并依次调用ShowArea输出面积。

#include <iostream>
#include <deque>
#define PI 3.14
using namespace std;

class Shape
{
public:
    virtual void ShowArea() = 0;
    ~Shape(){};
};

class Circle : public Shape
{
    int R;

public:
    Circle(int r) : R(r) {}
    void ShowArea() { cout << PI * R * R << " "; }
    ~Circle() {}
};
class Square : public Shape
{
    int side;

public:
    Square(int s) : side(s) {}
    void ShowArea() { cout << side * side << " "; }
    ~Square() {}
};
int main()
{
    deque<Circle> c;
    deque<Square> s;
    Circle C[3] = {Circle(1), Circle(2), Circle(3)};
    Square S[3] = {Square(1), Square(2), Square(3)};
    c.insert(c.begin(), C, C + 3);
    s.insert(s.begin(), S, S + 3);
    cout << "圆的面积:";
    for (deque<Circle>::iterator it = c.begin(); it != c.end(); ++it)
        it->ShowArea();
    cout << endl
         << "正方形的面积:";
    for (deque<Square>::iterator it = s.begin(); it != s.end(); ++it)
        it->ShowArea();
}