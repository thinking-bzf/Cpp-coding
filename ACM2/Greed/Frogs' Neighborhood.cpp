#include <iostream>
#include <algorithm>
using namespace std;
struct FROG
{
    int nb;
    int index;
};
bool cmp(FROG a, FROG b)
{
    if (a.nb != b.nb)
        return a.nb > b.nb;
    return a.index < a.index;
}
void matrix(FROG *a, int b)
{
    int s[25][25] = {0};
    int q = b;
    while (q--)
    {
        sort(a, a + b, cmp);
        int n = a[0].nb;
        a[0].nb = 0;
        for (int i = 1; i <= n; i++)
        {
            s[a[0].index][a[i].index] = 1;
            s[a[i].index][a[0].index] = 1;
            a[i].nb--;
        }
    }
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << s[i][j];
            if (j != b - 1)
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int i, n, flag = 1;
    FROG f[25], f1[25];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        flag = 1;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> f[j].nb;
            f[j].index = j;
            f1[j].nb = f[j].nb;
            f1[j].index = j;
        }
        int q = m;
        while (flag && q--)
        {
            sort(f1, f1 + m, cmp);
            int p = f1[0].nb;
            f1[0].nb = 0;
            for (int i = 1; i <= p; i++)
            {
                f1[i].nb--;
                if (f1[i].nb < 0)
                    flag = 0;
            }
        }
        if (!flag)
            cout << "NO" << endl
                 << endl;
        else
        {
            cout << "YES" << endl;
            matrix(f, m);
        }
    }
}