#include <iostream>
using namespace std;
int* fn1()
{
    int *p = new int(5);
    return p;
}
int main()
{
    int *a = fn1();
    cout << "the value of a is " << *a;
    delete a;
    return 0;
}
//函数返回指针，把返回的指针指向的内存delete

