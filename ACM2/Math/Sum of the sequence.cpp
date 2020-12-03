#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int a, b;
    double sum, x;
    while (cin >> a >> b)
    {
        x = a;
        sum = a;
        for (int i = 1; i < b; i++)
        {
            x = sqrt(x);
            sum += x;
        }
        printf("%.2f\n", sum);
    }
    return 0;
}