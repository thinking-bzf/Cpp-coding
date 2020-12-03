#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;
int main()
{
    string s1, s2;
    map<string, int> m;
    while (getline(cin, s1))
    {
        if (s1 == "#")
            break;
        m.clear();
        stringstream a(s1);
        while (a >> s2)
            m[s2]++;
        cout << m.size() << endl;
    }
}