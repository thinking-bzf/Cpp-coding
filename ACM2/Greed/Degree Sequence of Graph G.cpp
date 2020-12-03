#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int d[1005] = {0};
// 判断是否可图
// 按照节点值从小到大排序，然后从最大的数n开始的n个数依次递减1，如果有出现负数，则判定为不可图，直到最后不为负数为可图 
int main()
{
    int T, n, flag = 1;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        // 初始化是否可图 默认可图
        flag = 1;
        cin >> n;
        memset(d, 0, sizeof(d));
        for (int j = 0; j < n; j++)
            cin >> d[j];
        int k = n;
        while (flag != 0 && k)
        {
            sort(d, d + n, cmp);
            int m = d[0];
            d[0] = 0;
            for (int i = 1; i <= m; i++)
            {
                d[i]--;
                if (d[i] < 0)
                    flag = 0;
            }
            k--;
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}