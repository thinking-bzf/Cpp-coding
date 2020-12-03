#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main()
{
    int n;
    map<int, int> m;
    while (cin >> n)
    {
        int a;
        m.clear();
        int Max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            m[a]++;
            if(m[a]>Max)
            {
                Max = m[a];
            }
        }
        cout << Max << endl;
    }
}