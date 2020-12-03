#include <iostream>
int power(int a, int n)
{
    int ans;
    if (n == 0)
        ans = 1;
    else
    {
        ans = power(a * a, n / 2);
        if (n % 2 == 1)
            ans *= a;
    }
    return ans;
}