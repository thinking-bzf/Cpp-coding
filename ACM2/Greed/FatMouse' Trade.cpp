#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct JavaCat
{
    int CatFood;
    int JvavBean;
    double Scale;

} JC[1005];
bool cmp(JavaCat a, JavaCat b)
{
    if (a.Scale != b.Scale)
        return a.Scale > b.Scale;
    return a.CatFood > b.CatFood;
}

int main()
{
    int M, N;
    while (cin >> M >> N)
    {
        // memset(JC, 0, sizeof(JC));
        if (M == -1 || N == -1)
            break;
        for (int i = 0; i < N; i++)
        {
            cin >> JC[i].JvavBean >> JC[i].CatFood;
            JC[i].Scale = JC[i].JvavBean * 1.0 / JC[i].CatFood;
        }
        double sum = 0;
        sort(JC, JC + N, cmp);
        for (int i = 0; i < N; i++)
        {
            if (M > JC[i].CatFood)
            {
                sum += JC[i].JvavBean;
                M -= JC[i].CatFood;
            }
            else
            {
                sum += M * 1.0 * JC[i].Scale;
                break;
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}