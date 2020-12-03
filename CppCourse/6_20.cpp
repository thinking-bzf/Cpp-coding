#include <iostream>
#include <algorithm>
using namespace std;
class SimpleCircle
{
private:
    int *itsRadius;
    static int number;

public:
    SimpleCircle(int r = 1);
    int getRadius();
    ~SimpleCircle();
};

SimpleCircle::SimpleCircle(int r)
{
    if (r <= 0)
        itsRadius = new int(1); //新建一个int内存单元，使类中的指针指向该新的内存。
    else
        itsRadius = new int(r);
    number++;
}
int SimpleCircle::getRadius()
{
    if (*itsRadius <= 0)
    {
        cout << "data wrong:"; //如果小于等于0，报错
        return 0;
    }
    return *itsRadius;
}
SimpleCircle::~SimpleCircle()
{
    cout << number-- << " delete competed" << endl;
    delete itsRadius; //类结束后，释放指针指向的内存
}
int SimpleCircle::number = 0;
int main()
{
    SimpleCircle c[2] = {SimpleCircle(-2), SimpleCircle(5)};
    cout << "The first radius of cicle is " << c[0].getRadius() << endl
         << "The second radius of cicle is " << c[1].getRadius() << endl;
    return 0;
}