#include <iostream>
#include <cstring>
using namespace std;
int c1[10000], c2[10000];
int main()
{
    int m, n, k;
    int a[10], b[15]; //a表示学分值，b表示该学分有多少课
    cin >> m;
    while (m--)
    {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        cin >> n >> k;
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i] >> b[i];
            sum += a[i] * b[i];
        }
        if (sum < n)
            cout << 0 << endl;

        else
        {
            for (int i = 0; i <= b[1]; i++)
                c1[a[1] * i] = 1;
            for (int i = 2; i <= k; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    for (int k = 0; j + k * a[i] < sum && k <= b[i]; k++)
                        c2[j + k * a[i]] += c1[j];
                }
                for (int j = 0; j <= sum; j++)
                {
                    c1[j] = c2[j];
                    c2[j] = 0;
                }
            }
            cout << c1[n] << endl;
        }
    }
}