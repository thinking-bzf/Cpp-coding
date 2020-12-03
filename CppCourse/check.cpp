#include <iostream>
using namespace std;
int main()
{
    int x[2];
    int *x1 = &x[1];
    cout << x1 - x;
}