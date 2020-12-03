#include <iostream>
using namespace std;
int main()
{
    const int a = 1;
    int b = 2;
    int c = 3;

    const int *p1 = &b;
    int *const p3 = &b;
    p1 = &c;
    b = 1;
    const int *const p2 = &a;
    //p2 = &c;  表达式必须是可修改的左值
    //const int *p1 指p1指针指向的是一个(const) int类型的变量 该指针指向的const int 变量不能被修改，但p1可以更改指向的地址，指向其他变量，此时尽管被指向的变量不是const，*p1也不能被修改。
    //int *const p2 指向的是int类型的变量，不能指向const int变量，该指针一旦被赋值就不能指向其他变量.当前指向的变量可以被修改。
    cout << *p1 << endl;
}