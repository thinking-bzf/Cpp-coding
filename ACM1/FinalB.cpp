#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int bin[10];
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        memset(bin, 0, sizeof(bin));
        for (int i = 0; n > 0; i++)
        {
            bin[i] = n % 2;
            n /= 2;
        }
        int flag = 1;
        int sum = 0;
        for (int i = 0; flag; i++)
        {
            if (bin[i] == 1)
            {
                sum += (int)pow(2, i);
                flag = 0;
            }
        }
        cout << sum << endl;
    }
}