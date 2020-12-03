#include <iostream>
#include <cstring>
using namespace std;
char s[2010];
string result;
string bd = "zsbd";
int main()
{
    int T, n, l;
    cin >> T;

    while (T--)
    {

        cin >> n;
        scanf("%s", s);
        l = strlen(s);
        int m = n - l;
        int c = 0;
        result = s;
        if (m >= 0)
            if (m % 4 == 0)
            {
                c = m / 4;
            }
            else
            {
                c = m / 4 + 1;
            }
        for (int i = 1; i <= c; i++)
        {
            result = result + bd;
        }
        cout << result << endl;
    }
}