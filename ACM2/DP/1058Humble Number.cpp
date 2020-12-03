#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    long long dp[5900];
    dp[1] = 1;
    int a = 1, b = 1, c = 1, d = 1;
    for (int i = 2; i <= 5900; i++)
    {
        int v1 = dp[a] * 2;
        int v2 = dp[b] * 3;
        int v3 = dp[c] * 5;
        int v4 = dp[d] * 7;
        int ans = min(min(min(v1, v2), v3), v4);
        dp[i] = ans;
        if (ans == v1)
            a++;
        else if (ans == v2)
            b++;
        else if (ans == v3)
            c++;
        else if (ans == v4)
            d++;
        if (dp[i - 1] == dp[i])
            i--;
    }
    int n;
    while (cin >> n && n != 0)
    {
        if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
            printf("The %dth humble number is %lld.\n", n, dp[n]);
        else if (n % 10 == 1)
            printf("The %dst humble number is %lld.\n", n, dp[n]);
        else if (n % 10 == 2)
            printf("The %dnd humble number is %lld.\n", n, dp[n]);
        else if (n % 10 == 3)
            printf("The %drd humble number is %lld.\n", n, dp[n]);
        else
            printf("The %dth humble number is %lld.\n", n, dp[n]);
    }
}