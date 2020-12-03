#include <iostream>
using namespace std;
class Base0
{
public:
    virtual void display() { cout << "base0" << endl; }
};

class Base1 : public Base0
{

public:
    Base1(int i = 0) { cout << "Base1 " << i << endl; }
    void display() { cout << "base1" << endl; }
};

// class Derived : public Base2, public Base1, public Base3
// {
// public:
//     Derived(int a, int b, int c, int d, int e) : m(a), member2(b), member1(c), Base2(d), Base1(e)
//     {
//     } //对继承的基类构造函数，以及内嵌类的构造

// private:
//     Base1 member1;
//     Base2 member2;
//     Base3 member3;
//     int m;
// };
class Base2
{
protected:
    int x;

public:
    //Base2(int i) { cout << "Base2 " << i << endl; }
};
class Base3 : protected Base2
{
public:
    Base3() { cout << "Base3" << x << endl; }
};

int main()
{
    //Derived obj(1, 2, 3, 4, 5);
    Base3 b3;

    Base1 b1;
    Base0 *b0 = &b1;
    b0->display();
    b0->Base0::display();

    //b3.x;
}