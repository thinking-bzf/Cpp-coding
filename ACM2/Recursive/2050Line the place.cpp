#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        // f(n) = f(n-1) +4(n-1) +1
        cout << 2 * n * n - n + 1 << endl;
    }
}