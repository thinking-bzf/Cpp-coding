#include <iostream>
using namespace std;
int fn1()
{
    static int n = 0;
    n++;
    return n;
}
int main()
{
    for (int i = 0; i < 10; i++)
        cout << fn1() << " ";
    return 0;
}