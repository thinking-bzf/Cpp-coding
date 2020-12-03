#include <iostream>
using namespace std;
int dp[1005], s[1005];
int main()
{
    int n, Max;
    while (cin >> n)
    {
        Max = 0;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            dp[i] = s[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (s[i] > s[j])
                    dp[i] = max(dp[i], dp[j] + s[i]);
            Max = max(dp[i], Max);
        }
        cout << Max << endl;
    }
}