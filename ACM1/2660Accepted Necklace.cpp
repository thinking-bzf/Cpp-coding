#include <iostream>
#include <cstring>
using namespace std;

struct Stone
{
    int w;
    int v;
} s[25];
int W, n, k;
int ans;

void dfs(int cur, int sumw, int sumv, int pos)
{
    if (sumw > W)
        return;
    if (pos == k)//当数过的物品达到选择的k时
    {
        if (sumw <= W && sumv > ans)
            ans = sumv;
        return;
    }
    for (int i = cur; i < n;i++)
    {
        dfs(i + 1, sumw + s[i].w, sumv + s[i].v, pos + 1);//状态转移，添加一个石头，价值和重量都增加，数量增加
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> s[i].v >> s[i].w;
        cin >> W;
        dfs(0, 0, 0, 0);//起始状态，所有都是0
        cout << ans << endl;
    }
}
