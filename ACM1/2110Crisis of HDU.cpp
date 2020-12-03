#include <iostream>
#include <cstring>
using namespace std;
int c1[10010], c2[10010];
int main()
{
    int num[105], value[105];
    int n;
    while (cin >> n && n)
    {
        int sum = 0;
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for (int i = 1; i <= n; i++)
        {
            cin >> value[i] >> num[i];
            sum += num[i] * value[i];
        }
        int m = sum / 3;
        if (sum % 3 != 0)
        {
            cout << "sorry" << endl;
            continue;
        }
        for (int i = 0; i <= num[1] * value[1] && i <= m; i += value[1])
            c1[i] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; j + k <= m && k <= num[i] * value[i]; k += value[i])
                {
                    c2[j + k] += c1[j];
                    c2[j + k] %= 10000;
                }
            }
            for (int j = 0; j <= m; j++)
            {
                c1[j] = c2[j] % 10000;
                c2[j] = 0;
            }
        }
        if (!c1[m])
            cout << "sorry" << endl;
        else
            cout << c1[m] << endl;
    }
}