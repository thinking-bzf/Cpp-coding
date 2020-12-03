    #include <iostream>
    #include <cstring>
    #include <vector>
    #include <algorithm>
    using namespace std;
    int t1[1005], t2[1005];
    int n, cnt;
    void dfs(int xb, int xe, int zb, int ze) //先序开始，先序结尾，中序开始，中序结尾
    {
        if (xb > xe || zb > ze)
            return;
        int pos = 0;
        for (int i = zb; i <= ze; i++)
        {
            if (t2[i] == t1[xb])
                pos = i;
        }
        int len = pos - zb + 1;
        dfs(xb + 1, xb + len - 1, zb, zb + len - 1);
        dfs(xb + len, xe, zb + len, ze);
        cout << t1[xb];
        cnt++;
        if (cnt != n)
            cout << " ";
    }
    int main()
    {

        while (cin >> n)
        {
            cnt = 0;
            int a, b;
            for (int i = 1; i <= n; i++)
            {
                cin >> t1[i];
            }
            for (int i = 1; i <= n; i++)
                cin >> t2[i];
            dfs(1, n, 1, n);
            cout << endl;
        }
    }