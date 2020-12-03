#include <iostream>
#include <cstring>
using namespace std;
int num[1000000];
int main()
{
    int n;
    while (cin >> n)
    {
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            num[a]++;
            if (num[a] == (n + 1) / 2)
                cout << a << endl;
        }
    }
}
