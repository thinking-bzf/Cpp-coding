#include <iostream>
#include <cstring>
using namespace std;
int set[1005];
int findx(int x)
{
    int r = x;
    while (set[r] != r)
        r = set[r];
    return r;
}
void marge(int a, int b)
{
    if (findx(a) != findx(b))
        set[findx(a)] = findx(b);
}
int main()
{
    int m, n;
    while (cin >> n >> m && n != 0)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            set[i] = i;

        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            marge(a, b);
        }
        for (int i = 1; i <= n; i++)
            if (set[i] == i)
                sum++;
        cout << sum - 1 << endl;
    }
}
