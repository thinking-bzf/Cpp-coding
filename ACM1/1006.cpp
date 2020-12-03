#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
struct C
{
    long long p; //敌军
    long long c; //守军容量
    long long result;
} c[100010];
int map1[100100];
int findx(int x)
{
    while (x != map1[x])
        x = map1[x];
    return x;
}
int main()
{
    int T, n;
    int a, b;
    cin >> T;
    while (T--)
    {

        memset(c, 0, sizeof(c));
        cin >> n;
        for (int i = 1; i <= n; i++)
            map1[i] = i;
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            if (a > b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            map1[b] = a;
        }
        map1[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].p >> c[i].c;
        }
        for (int i = 2; i <= n; i++)
        {
            int x = findx(i);
            if (x == 1)
                map1[i] = 1;
        }
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (map1[i] == 1)
            {
                c[i].result = c[i].p - min(c[i].p, c[i].c);
                sum += c[i].result;
            }
        }
        if (sum > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}