#include <iostream>
#include <cstring>
using namespace std;
int num[15];
int b[10];
int n;
void dfs(int k, int pos) //pos表示当前b数组的位置 k表示当前num数组的位置
{
    if (pos == 6)
    {
        for (int i = 0; i < 5; i++)
            cout << b[i] << " ";
        cout << b[5] << endl;
        return;
    }
    for (int i = k; i < n; i++)
    {
        b[pos] = num[i];
        dfs(i + 1, pos + 1);
    }
}

int main()
{
    int time = 0;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        if (time == 0)
            time = 1;
        else
            cout << endl;
        dfs(0, 0);
        time++;
    }
    return 0;
}