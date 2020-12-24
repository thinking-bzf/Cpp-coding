#include <iostream>
#include <cstring>
using namespace std;
int set[1010];
// 获取并查集集合的个数
int findx(int a)
{
    int r = a;
    // 一直往上找，看是否和自己本身一样，如果和本身一样就是该组织的老大
    while (r != set[r])
        r = set[r];
    return r;
}
void merge(int a, int b)
{
    // 如果两个人的老大不一样，那就把b的老大介绍给a的老大，
    if (findx(a) != findx(b))
        set[findx(a)] = findx(b);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int m, n;
        cin >> m >> n;
        // 先假设机子是自己的老大
        for (int i = 1; i <= m; i++)
            set[i] = i;
        for (int i = 1; i <= n; i++)
        {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        int cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            if (set[i] == i)
                cnt++;
        }
        cout << cnt << endl;
    }
}