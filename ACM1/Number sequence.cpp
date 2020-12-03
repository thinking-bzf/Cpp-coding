#include <stdio.h>
int main()
{
    int a, b, n, i, arr[49] = {1, 1};
    while (scanf("%d%d%d", &a, &b, &n) && (a | b | n))
    {
        for (i = 2; i < 49; i++)
            arr[i] = (a * arr[i - 1] + b * arr[i - 2]) % 7;
        printf("%d\n", arr[(n - 1) % 49]); //数组下标从0开始，所以n先减1
    }
    return 0;
}