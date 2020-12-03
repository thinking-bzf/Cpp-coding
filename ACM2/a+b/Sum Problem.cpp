#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        long long result = 0;
        result = n * (1 + n) / 2;
        cout << result << endl
             << endl;
    }
}