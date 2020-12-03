#include <iostream>
using namespace std;
int main()
{
    int n;
    int cnt, a, sum = 0;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            cin >> cnt;
            for (int i = 0; i < cnt; i++)
            {
                cin >> a;
                sum += a;
            }
            cout << sum << endl;
        }
    }
    
}