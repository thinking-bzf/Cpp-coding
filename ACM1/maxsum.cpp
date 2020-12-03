
#include "stdio.h"
main()
{
    int max, start, temp, end, sum, i, j, t, n, a[100001];
    scanf("%d", &t);
    for (j = 1; j <= t; j++)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", a + i);
        max = a[1];
        sum = 0;
        temp = start = end = 1;
        for (i = 1; i <= n; i++)
        {
            sum += a[i];
            if (sum > max)
            {
                max = sum;
                start = temp;
                end = i;
            }
            if (sum < 0)
            {
                sum = 0;
                temp = i + 1;
            }
        }

        printf("Case %d:\n", j);
        printf("%d %d %d\n", max, start, end);
        if (j < t)
            putchar(10);
    }
}