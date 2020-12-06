#include <iostream>
using namespace std;
int vis[15] = {0};
struct tu
{
    int farmer;
    int wolf;
    int sheep;
    int veg;
} T[16];
bool check(tu x)
{
    if ((x.farmer != x.sheep) && (x.wolf == x.sheep || x.sheep == x.veg))
        return false;
    else
        return true;
}
void tuinit(tu T[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    T[l + 2 * k + 4 * j + 8 * i].farmer = i;
                    T[l + 2 * k + 4 * j + 8 * i].wolf = j;
                    T[l + 2 * k + 4 * j + 8 * i].sheep = k;
                    T[l + 2 * k + 4 * j + 8 * i].veg = l;
                }
            }
        }
    }
}
void dfs(int k, tu T[])
{
    if (k == 15)
    {
        for (int i = 0; i < 16; i++)
            vis[i] = 1;
        cout << "1	1	1	1" << endl;
        return;
    }
    if (vis[k] == 1)
        return;
    
    else if (vis[k] == 0)
    {
        vis[k] = 1;
        if (!check(T[k]))
            return;
        else
        {
            cout << T[k].farmer << "	" << T[k].wolf << "	" << T[k].sheep << "	" << T[k].veg << endl;
            if ((k + 8) <= 15)
            {

                dfs(k + 8, T);
                if (T[k].wolf == 0)
                    dfs(k + 12, T);
                if (T[k].sheep == 0)
                    dfs(k + 10, T);
                if (T[k].veg == 0)
                    dfs(k + 9, T);
                vis[k] = 0;
            }
            else
            {
                dfs(k - 8, T);
                if (T[k].wolf == 1)
                    dfs(k - 12, T);
                if (T[k].veg == 1)
                    dfs(k - 9, T);
                if (T[k].sheep == 1)
                    dfs(k - 10, T);
                vis[k] = 0;
            }
        }
    }
}
int main()
{
    cout << "农夫	狼	羊	菜" << endl;
    tuinit(T);
    dfs(0, T);
    return 0;
}
