#include <iostream>
using namespace std;
int power(int a, int b)
{
    int ans;
    if (b == 0)
        ans = 1;
    else if (b==1)
    {
        ans = a;
    }
    else
    {
        ans = power((a * a) % 1000, b / 2);
        if (b % 2)
            ans = (ans * a) % 1000;
        // ans %= 1000;
    }
    return ans;
}
int main()
{
    int a, b;
    long long result;
    while (cin >> a >> b)
    {
        result = 0;
        if (a == 0 && b == 0)
            break;
        result = power(a, b) % 1000;
        cout << result << endl;
    }
    return 0;
}