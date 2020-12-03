#include <iostream>
using namespace std;
int mod[] = { 1, 2, 0, 2, 2, 1, 0, 1 };
int main()
{
    int n;
    while (cin >> n)
    {
        if (mod[n % 8] == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}