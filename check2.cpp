#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char s[200];
    // string s = new char[200];
    cin.getline(s, 200);
    // getline(x, 100);
    // cout << strlen(x);
    string x(s);
    if (x.empty())
        cout << "Yes" << endl;
    else
    {
        int temp = stoi(x);
        cout << temp;
    }
}