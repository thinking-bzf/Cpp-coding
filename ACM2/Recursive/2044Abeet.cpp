#include <iostream>
using namespace std;
long long beet[60] = {0}; //注意数据范围超过int
int main()
{
    int m, start, end;
    cin >> m;
    beet[1] = 0;
    beet[2] = 1;
    beet[3] = 2;
    for (int i = 4; i <= 55; i++)
        beet[i] = beet[i - 1] + beet[i - 2];

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        cout << beet[end - start + 1] << endl;
    }
}