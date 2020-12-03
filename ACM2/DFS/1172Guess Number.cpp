#include <bits/stdc++.h>
#include <cstring>

using namespace std;
int a[105], b[105], c[105];
int loc[5];
int judge(int s[], int x)
{
    int text_a[5], flag_a[5]; //����ƥ��
    int flag_n[5];            //λ��ƥ��
    int sumb = 0;             //�ۼƴ�������
    int sumc = 0;             //�ۼ�λ��ƥ��
    int temp = a[x];
    memset(flag_a, 0, sizeof(flag_a));
    memset(flag_n, 0, sizeof(flag_n));
    text_a[1] = temp % 10;
    temp = temp / 10;
    text_a[2] = temp % 10;
    temp = temp / 10;
    text_a[3] = temp % 10;
    temp = temp / 10;
    text_a[4] = temp % 10;
    for (int i = 1; i <= 4; i++)
    {
        if (text_a[i] == s[i])
        {
            flag_a[i] = 1; //��¼��λ�õ�����ƥ��
            flag_n[i] = 1;
            sumb++;
            sumc++;
        }
    }
    //Ѱ�����ִ���λ�ò�ƥ�������
    for (int i = 1; i <= 4; i++)
    {
        if (flag_n[i] == 0)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (text_a[j] == s[i] && flag_a[j] == 0)
                {
                    sumb++;
                    flag_a[j] = 1;
                    flag_n[i] = 1;
                    break;
                }
            }
        }
    }
    if (sumb == b[x] && sumc == c[x])
        return 1;
    return 0;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int cnt = 0, re;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> b[i] >> c[i];
        for (int i = 1000; i <= 9999; i++)
        {
            int temp, flag = 0;
            temp = i;
            loc[1] = temp % 10;
            temp = temp / 10;
            loc[2] = temp % 10;
            temp = temp / 10;
            loc[3] = temp % 10;
            temp = temp / 10;
            loc[4] = temp % 10;
            for (int i = 1; i <= n; i++)
                flag += judge(loc, i);
            if (flag == n)
            {
                cnt++;
                re = i;
            }
            if (cnt >= 2)
                break;
        }
        if (cnt == 1)
            cout << re << endl;
        else
            cout << "Not sure" << endl;
    }
}