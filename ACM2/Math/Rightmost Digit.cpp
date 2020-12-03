#include <iostream>
using namespace std;
int main()
{
    int a[20] = {0, 1, 4, 7, 6, 5, 6, 3, 6, 9, 0, 1, 6, 3, 6, 5, 6, 7, 4, 9};
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int m;
        cin >> m;
        cout << a[m % 20] << endl;
    }
}