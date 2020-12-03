#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, i, j, len;
    string s;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, s);
        int len = s.size();
        for (i = len - 1; i >= 0; i--)
            cout << s[i];
        cout << endl;
    }
}
