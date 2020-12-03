#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long  qiehe[100005];
int a[100005];

void init()
{
    memset(a, 0, sizeof(a));
    memset(qiehe, 0, sizeof(qiehe));
}
void in(int n)
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        qiehe[i] = qiehe[i - 1] + a[i];
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        in(n);
        int x, y;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            if (x < y)
                cout << qiehe[y] - qiehe[x - 1] << endl;
            else
                cout << qiehe[x] - qiehe[y - 1] << endl;
        }
    }
}