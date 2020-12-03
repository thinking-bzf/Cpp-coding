#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        map<char, int> times;
        for (char i = 'a'; i <= 'z'; ++i)
            times.insert(make_pair(i, 0));
        for (char &a : s)
        {
            if (a >= 'a' && a <= 'z')
                ++times[a];
        }
        for (auto it = times.begin(); it != times.end(); ++it)
        {
            printf("%c:%d\n", it->first, it->second);
        }
        cout << endl;
    }
}