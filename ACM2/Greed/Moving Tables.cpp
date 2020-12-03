#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt[205] = {0};

    for (int i = 0; i < n; i++)
    {

        int m;
        cin >> m;
        int max = -1;
        memset(cnt, 0, sizeof(cnt));
        for (int k = 0; k < m; k++)
        {
            int start, end;
            cin >> start >> end;
            start = (start - 1) / 2;
            end = (end - 1) / 2;
            if (start > end)
            {
                int temp = start;
                start = end;
                end = temp;
            }
            for (int j = start; j <= end; j++)
                cnt[j]++;

            for (int j = 1; j <= 200; j++)
            {
                if (max < cnt[j])
                    max = cnt[j];
            }
        }
        cout << max * 10 << endl;
    }

    return 0;
}