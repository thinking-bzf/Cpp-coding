#include <iostream>
#include <cstring>
using namespace std;
int pin[101];
int Hash[2000030];
int main()
{
    for (int i = 0; i < 101; i++)
    {
        pin[i] = i * i;
    }
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        if (a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0)
        {
            cout << 0 << endl;
            continue;
        }
        memset(Hash, 0, sizeof(Hash));
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                Hash[pin[i] * a + pin[j] * b + 1000000]++;
        int sum = 0;
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                sum += Hash[-(c * pin[i] + pin[j] * d) + 1000000];
        cout << sum * 16 << endl;// 排列组合乘16
    }
}