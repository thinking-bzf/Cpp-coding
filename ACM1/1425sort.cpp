#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, m;
    int s[1000010];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < m; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}