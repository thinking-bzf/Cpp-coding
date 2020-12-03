#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct Rice
{
    int Price;
    int weight;
} rice[30];
bool cmp(Rice a, Rice b)
{
    if (a.Price != b.Price)
        return a.Price < b.Price;
    return a.weight > b.weight;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        memset(rice, 0, sizeof(rice));
        int money, m;
        cin >> money >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> rice[i].Price >> rice[i].weight;
        }
        sort(rice, rice + m, cmp);
        for (int i = 0; money > 0; i++)
        {
            if (money >= rice[i].Price * rice[i].weight)
            {
                sum += rice[i].weight;
                money -= rice[i].Price * rice[i].weight;
            }
            else
            {
                sum += money * 1.0 / rice[i].Price;
                money = 0;
            }
        }
        printf("%.2f\n", sum);
    }
}