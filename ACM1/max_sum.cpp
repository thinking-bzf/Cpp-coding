#include <iostream>
#include <cstring>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin >> n;
    int cnt = 1;
    while (n--)
    {
        int m;
        cin >> m;
        int Max = -9999;
        for (int i = 1; i <= m; i++)
            cin >> a[i];
        int sum = 0;
        int s = 1, e = 0, start = 1, end = 1;
        for (int i = 1; i <= m; i++)
        {
            sum += a[i];
            e = i;
            if (sum > Max)
            {
                Max = sum;
                start = s;
                end = e;
            }

            if (sum + a[i] < a[i])
            {
            sum = 0;
                s = i + 1;
            }
        }
        printf("Case %d:\n", cnt++);
        printf("%d %d %d\n", Max, start, end);
        if (n)
        {
            printf("\n");
        }
    }
}