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
    int a, b, c, d;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a >> b >> c >> d;
        int fenzi = a * c;
        int fenmu = b * d;
        int yueshu = gcd(fenzi, fenmu);
        cout << a * c / yueshu << " " << b * d / yueshu << endl;
    }
}