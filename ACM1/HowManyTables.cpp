#include <iostream>
#include <cstring>
using namespace std;
int set[1010];
int findx(int a)
{
    int r = a;
    while (r != set[r])
        r = set[r];
    return r;
}
void merge(int a, int b)
{
    if(findx(a)!=findx(b))
        set[findx(a)] = findx(b);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int m, n;
        int x, y;
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            set[i] = i;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            merge(x, y);
        }
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            if (set[i] == i)
                count++;
        }
        cout << count << endl;
    }
}