#include <stdio.h>
#define m 5 //进程数量
#define n 3 //资源类数量

int main()
{
    int available[n] = [ 3, 3, 3 ];
    int Allocation[m][n];
    int finish[m];
    int requset[m][n];

    // 首先需要初始化request变量

    int work[n] = available;
    for (int i = 0; i < m; i++)
        finish[i] = true;

    // 记录未完成的进程数量
    int cnt = 0;
    // 初始化finish数组,对每个进程的每类资源都进行判断
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (Allocation[i][j] > 0)
            {
                finish[i] = false;
                break;
                cnt++;
            }
    // 开始循环
    while (cnt > 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (finish[i] == false)
            {
                // 判断全部资源可分配
                int flag = 1;
                for (int j = 0; j < n; j++)
                {
                    // 对所有类资源进行判断
                    if (requset[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                // 如果能够分配，则把已分配的临时归还给work进行下一步的判断
                if (flag)
                {
                    for (int j = 0; j < n; j++)
                        work[j] += Allocation[i][j];
                    // i进程完成，进程计数器减一
                    finish[i] = false;
                    cnt--;
                }
            }
        }
    }
}