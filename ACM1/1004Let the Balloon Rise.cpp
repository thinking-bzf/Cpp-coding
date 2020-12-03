#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main()
{
    int n;
    
    while (cin >> n && n)
    {
        map<string, int> s;
        for (int i = 0; i < n; i++)
        {
            string color;
            cin >> color;
            s[color]++;
        }
        string g;
        int Max = 0;
        for (auto t : s)
        {
            if (t.second > Max)
            {
                g = t.first;
                Max = t.second;
            }
        }
        cout << g << endl;
    }
}