#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int Left[105];
int Right[105];
int main()
{
    int n;
    int sum1, sum2;
    while (cin >> n)
    {
        sum1 = sum2 = 0;
        if (n == 0)
            break;
        memset(Left, 0, sizeof(Left));
        memset(Right, 0, sizeof(Right));
        for (int i = 0; i < n; i++)
            cin >> Left[i];
        for (int i = 0; i < n; i++)
            cin >> Right[i];
        sort(Left, Left + n, cmp);
        sort(Right, Right + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (Left[i] > Right[i])
                sum1 += 2;
            else if (Left[i] == Right[i])
            {
                sum1++;
                sum2++;
            }
            else
                sum2 += 2;
        }
        cout << sum1 << " vs " << sum2 << endl;
    }

    return 0;
}