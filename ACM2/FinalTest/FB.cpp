#include <iostream>
using namespace std;
int main()
{
    int n;
    int a, b, c;
    int kase = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a + b <= c || b + c <= a || a + c <= b)
        {
            cout << "Case #" << ++kase << ": invalid!" << endl;
            continue;
        }
        if (a == b && b == c)
            cout << "Case #" << ++kase << ": equilateral" << endl;
        else if (a == b || b == c || c == a)
            cout << "Case #" << ++kase << ": isosceles" << endl;
        else
            cout << "Case #" << ++kase << ": scalene" << endl;
    }
}