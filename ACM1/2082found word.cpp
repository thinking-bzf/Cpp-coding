#include <iostream>
#include <cstring>
using namespace std;
int c1[54], c2[54];
int main()
{
    int num[30];
    int n;
    cin >> n;
    while (n--)
    {
        memset(num, 0, sizeof(num));
        memset(c1, 0, sizeof(c1));
        memset(c1, 0, sizeof(c2));
        for (int i = 1; i <= 26; i++)
        {
            cin >> num[i];
        }
        for (int i = 0; i <= num[1]; i++)
            c1[i] = 1;
        for (int i = 2; i <= 26; i++)
        {
            for (int j = 0; j <= 50; j++)
                for (int k = 0; j + k * i <= 50 && k <= num[i]; k++)
                    c2[j + k * i] += c1[j];
            for (int j = 0; j <= 50; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        int s = 0;
        for (int i = 1; i <= 50; i++)
        {
            s += c1[i];
        }
        cout << s << endl;
    }
}