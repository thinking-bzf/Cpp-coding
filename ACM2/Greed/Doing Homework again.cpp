#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct HomeWork
{
    int Score;
    int DeadLine;
    // 判断是否选择做
    int flag;
} HomeWorks[1005];
bool cmp(HomeWork a, HomeWork b)
{
    if (a.DeadLine != b.DeadLine)
        return a.DeadLine < b.DeadLine;
    return a.Score > b.Score;
}

int main()
{
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int day = 1;
        cin >> n;
        memset(HomeWorks, 0, sizeof(HomeWorks));
        for (int i = 0; i < n; i++)
            cin >> HomeWorks[i].DeadLine;
        for (int i = 0; i < n; i++)
            cin >> HomeWorks[i].Score;
        sort(HomeWorks, HomeWorks + n, cmp);
        for (int j = 0; j < n; j++)
        {
            // 如果当前模拟日期小于截止日期，则做该作业
            if (day <= HomeWorks[j].DeadLine)
            {
                HomeWorks[j].flag = 1;
                day++;
            }
            else
            {
                // 如果当前日期超过了截止日期，则判断该作业的分数与之前判断为做的作业分数相比
                // 如果比之前的取代之前分数最低的作业，以获取的分数最多
                int min_index = j;
                for (int k = 0; k < j; k++)
                    if ((HomeWorks[min_index].Score > HomeWorks[k].Score) && HomeWorks[k].flag)
                        min_index = k;
                if (j != min_index)
                {
                    HomeWorks[min_index].flag = 0;
                    HomeWorks[j].flag = 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (!HomeWorks[i].flag)
                sum += HomeWorks[i].Score;
        cout << sum << endl;
    }
    return 0;
}