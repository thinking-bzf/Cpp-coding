#include <iostream>
#include <cstring>
using namespace std;
int s[10000005];
int c[10000005];
int Max = 1;
int findx(int x)
{
    int r = x;
    while (s[r] != r)
        r = s[r];

    int i = x, j;
    while (i != r)//路径压缩
    {
        j = s[i];
        s[i] = r;
        i = j;
    }
    return r;
}
void marge(int a, int b)
{
    int fx=findx(a);
	int fy=findx(b);
    if (fx != fy)
    {
        s[fy] = fx;
        c[fx] += c[fy];//把在一起的集合元素个数加起来 
        if (Max < c[fx])
            Max = c[fx];
    }
}
int main()
{
    int T, a, b;
    while (scanf("%d", &T) != EOF)
    {
        Max = 1;
        for (int i = 1; i < 1000005; i++)
        {
            s[i] = i;
            c[i] = 1;
        }
        while (T--)
        {
            scanf("%d %d", &a, &b);
            marge(a, b);
        }

        cout << Max << endl;
    }
}