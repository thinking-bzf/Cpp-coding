#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>
#include <cstring>
using namespace std;
int a[10000];
bool cmp1(int x,int y)
{
    return x >= y;
}
bool cmp2(int x,int y)
{
    return x <= y;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(a, 0, sizeof(a));
        string s;
        cin >> s;
        if (s == "Faster")
        {
            int n;
            cin >> n;
            for (int i = 0; i < n;i++)
                cin >> a[i];
            sort(a, a + n, cmp2);
            cout << a[0] << endl;
            
        }
        else if (s == "Higher")
        {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> a[i];
            sort(a, a + n, cmp1);
            cout << a[0] << endl;
        }
        else if(s=="Stronger")
        {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> a[i];
            sort(a, a + n, cmp1);
            cout << a[0] << endl;
        }
    }
}