#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        int result, x;
        cin >> x;
        result = x;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> x;
            result = result / gcd(x, result) * x;
        }
        cout << result << endl;
    }
}