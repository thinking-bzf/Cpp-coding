#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// 存放26个字母对应数字的幂次值
int per[30][8];
// 记录字符访问记录
int vis[15];
int num[5];
// 用来得到最大的字符
int temp[5];
string str;
int sum;
// 标记是否成功
int flag;

void init()
{
    for (int i = 1; i <= 26; i++)
    {
        per[i][0] = 1;
        for (int j = 1; j <= 5; j++)
            per[i][j] = per[i][j - 1] * i;
    }
}
bool check()
{
    for (int i = 0; i < 5; i++)
        if (num[i] > temp[i])
            return true;
        else if (num[i] < temp[i])
            return false;
}
void dfs(int cur)
{
    if (cur == 5)
    {
        int k = per[num[0]][1] - per[num[1]][2] + per[num[2]][3] - per[num[3]][4] + per[num[4]][5];
        if (k == sum && check())
        {
            for (int i = 0; i < 5; i++)
                temp[i] = num[i];
            flag = 1;
        }
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!vis[i])
        {
            num[cur] = str[i] - 'A' + 1;
            vis[i] = 1;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    // 存入幂次值
    init();
    while (cin >> sum >> str)
    {
        if (!sum && str == "END")
            break;
        memset(vis, 0, sizeof(vis));
        memset(temp, 0, sizeof(temp));
        memset(num, 0, sizeof(num));
        flag = 0;
        dfs(0);
        if (flag)
            for (int i = 0; i < 5; i++)
                cout << (char)(temp[i] + 'A' - 1);
        else
            cout << "no solution";
        cout << endl;
    }
}