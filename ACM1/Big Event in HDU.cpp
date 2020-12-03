#include <iostream>
#include <cstring>
#define Maxn 1001000
using namespace std;
int c1[Maxn], c2[Maxn];
int main()
{
    int n;
    int v[200], m[200];
    while (cin >> n && n > 0)
    {
        int Max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i] >> m[i];
            Max += v[i] * m[i];
        }
        int mid = Max / 2;
        memset(c1, 0, sizeof(int) * mid + 10);
        memset(c2, 0, sizeof(int) * mid + 10);
        for (int i = 0; i <= m[0]; i++)
            c1[i * v[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= mid; j++)
            {
                for (int k = 0; (j + k * v[i]) <= mid && k <= m[i]; k++)
                    c2[j + k * v[i]] += c1[j];
            }
            for (int j = 0; j <= mid; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        int ci = 0;
        for (int i = mid; i >= 0; i--)
        {
            if (c1[i] != 0)
            {
                ci = i;
                break;
            }
        }
        cout << Max - ci << " " << ci << endl;
    }
}