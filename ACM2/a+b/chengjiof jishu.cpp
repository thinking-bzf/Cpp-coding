#include <iostream>
using namespace std;
int main()
{
    int n, a, result;
    while (cin >> n)
    {
        result = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a % 2)
                result *= a;
        }
        cout << result << endl;
    }
    return 0;
}