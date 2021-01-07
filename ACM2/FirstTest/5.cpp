#include <iostream>
#include <cmath>
using namespace std;
struct
{
    int x1, x2, x3, x4, x5;
} year[45];
int main()
{
    int n, i, j, k, t;
    cin >> n;
    year[1].x1 = 1;
    year[1].x2 = 0;
    year[1].x3 = 0;
    year[1].x4 = 0;
    year[1].x5 = 0;
    for (i = 2; i < 41; i++)
    {
        year[i].x1 = (year[i - 1].x2 + year[i - 1].x3 + year[i - 1].x4) * 4;
        year[i].x2 = year[i - 1].x1;
        year[i].x3 = year[i - 1].x2;
        year[i].x4 = year[i - 1].x3;
        year[i].x5 = year[i - 1].x4;
    }
    while (n--)
    {
        cin >> t;
        cout << (year[t].x1 + year[t].x2 + year[t].x3 + year[t].x4 + year[t].x5) << endl;
    }
}
