#include <iostream>
using namespace std;
int n, m, a[110][110], ans = 0;
int nex[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void dfs(int x, int y, int cnt) //注意考虑这个搜索的结束条件是什么，然而并没有递归出口
{
    a[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + nex[i][0];
        int ny = y + nex[i][1];
        if (a[nx][ny] == 1)
            dfs(nx, ny, cnt);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                dfs(i, j, ++ans);
    //测试代码
    //    for(int i=0; i<n; i++)
    //    {
    //        for(int j=0; j<m; j++)cout<<a[i][j]<<" ";
    //        cout<<endl;
    //    }
    cout << ans;
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;
int n, m, a[110][110], ans = 0;
int nex[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; //四连通遍历坐标
struct s
{
    int x;
    int y;
} f, t; //结构体变量f,t分别用于存储队列的头和尾
int main()
{
    queue<s> q; //定义结构体类型点队列
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
            {
                a[i][j] = 0; //置0防止重复计算
                ++ans;       //计数
                t.x = i;
                t.y = j;
                q.push(t);
                while (!q.empty())
                {
                    f = q.front(); //获取队列头坐标
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = f.x + nex[k][0]; //计算下一坐标点x
                        int ny = f.y + nex[k][1]; //计算下一坐标点y
                        if (a[nx][ny] == 1)
                        {
                            a[nx][ny] = 0;
                            t.x = nx;
                            t.y = ny;
                            q.push(t);
                        }
                    }
                    q.pop();
                }
            }
    //测试代码
    //    for(int i=0; i<n; i++)
    //    {
    //        for(int j=0; j<m; j++)cout<<a[i][j]<<" ";
    //        cout<<endl;
    //    }
    cout << ans;
    return 0;
}

#include <stdio.h>
#include <iostream>
using namespace std;
int n, m, p[4001], s;  //p保存节点的直接父节点
inline int find(int x) //查找x的根节点
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return a[x];
}
inline void join(int x, int y) //连接两个连通块
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        p[fy] = fx;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    register int i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        p[i] = i; //初始化p数组
    }
    for (i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        join(x, y);
    }
    for (i = 1; i <= n; i++)
    {
        if (p[i] == i)
            s++; //计算连通子图的个数s
    }
    cout << s << endl;
    return 0;
}