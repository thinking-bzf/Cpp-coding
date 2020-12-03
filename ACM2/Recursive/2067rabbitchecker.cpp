#include <iostream>
using namespace std;
__int64 check[38][38];
int main()
{
    for (int i = 0; i <= 38; i++)
    {
        check[0][i] = 1;
        check[i][0] = 1;
    }
    for (int i = 1; i <= 36; i++)
        for (int j = i; j <= 36; j++)
        {
            if (j != i)
                check[i][j] = check[i - 1][j] + check[i][j - 1];
            else
                check[i][j] = check[i - 1][j];
        }
    int count = 1;
    int m;
    while (cin >> m)
    {
        if (m == -1)
            break;
        printf("%d %d %I64d\n", count++, m, check[m][m] * 2);
    }
}