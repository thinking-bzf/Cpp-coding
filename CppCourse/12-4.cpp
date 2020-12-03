#include <iostream>
#include <cstring>
using namespace std;
class MyException
{
public:
    MyException() {}
    ~MyException() {}
    virtual void PrintError() = 0;
};

class OutOfMemory : public MyException
{
public:
    OutOfMemory() {}
    ~OutOfMemory() {}
    void PrintError();
};
void OutOfMemory::PrintError()
{
    cout << "Out of Memory" << endl;
};
class RangeError : public MyException
{
    int number;

public:
    RangeError(unsigned int num) : number(num) {}
    ~RangeError() {}
    void PrintError();
};
void RangeError::PrintError()
{
    cout << "Number out of range. You used " << number << endl;
}
void fn1();
unsigned int *fn2();
void fn3(unsigned int *);

int main()
{
    try
    {
        fn1();
        fn1();
    }
    catch (MyException &TheException)
    {
        TheException.PrintError();
    }
    return 0;
}
unsigned int *fn2()
{
    unsigned int *p = new unsigned int;
    if (p == 0)
        throw OutOfMemory();
    return p;
}
void fn1()
{
    unsigned int *p = fn2();
    fn3(p);
    cout << "Number is " << *p << endl;
    delete p;
}
void fn3(unsigned int *n)
{
    long num;
    cout << "Input a number (1-10000)" << endl;
    cin >> num;
    if(num>10000||num<1)
        throw RangeError(num);
    *n = num;
}