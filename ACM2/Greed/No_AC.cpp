#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Show
{
    int start;
    int end;
} Shows[105];
bool cmp(Show a, Show b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        for (int i = 0; i < n; i++)
            cin >> Shows[i].start >> Shows[i].end;
        sort(Shows, Shows + n, cmp);
        int count = 1, pre = 0;
        for (int i = 1; i < n; i++)
        {
            // 如果前一次的结束时间比后一次的开始时间前,则添加该节目,
            // 每次选节目都按照这个原则来,即可得到最长事件序列
            if (Shows[pre].end <= Shows[i].start)
            {
                count++;
                pre = i;
            }
        }
        cout << count << endl;
    }
    return 0;
}