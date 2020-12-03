#include <iostream>
using namespace std;
int c1[8005], c2[8005];
int main()
{
    int cn[3] = {1, 2, 5};
    int num[3];
    while (cin >> num[0] >> num[1] >> num[2])
    {
        if (!num[0] && !num[1] && !num[2])
            break;
        int Max = num[0] + 2 * num[1] + 5 * num[2];
        for (int i = 0; i <= 8005; i++)//×¢Òâ³õÊ¼»¯
        {
            c1[i] = 0;
            c2[i] = 0;
        }
        for (int i = 0; i <= num[0]; i++)
            c1[i] = 1;
        for (int i = 1; i < 3; i++)
        {
            for (int j = 0; j <= Max; j++)
            {
                for (int k = 0; (j + k <= Max) && (k <= cn[i] * num[i]); k += cn[i])
                    c2[k + j] += c1[j];
            }
            for (int j = 0; j <= Max; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for (int i = 0; i <= Max + 1; i++)
        {
            if (!c1[i])
            {
                cout << i << endl;
                break;
            }
        }
    }
}