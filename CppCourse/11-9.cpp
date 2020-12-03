#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
    int _group;
    int cnt = 1;
    //string file1;
    //cin >> file1;   可以用来重定向不同文件名
    ifstream fin("source.txt", ios_base::in);
    string s;
    //string file2;
    //cin >> file2;
    ofstream fout("lines.txt", ios_base::out | ios_base::trunc);
    while (getline(fin, s))
    {
        fout << cnt++ << "\t";
        fout << s << endl;
    }
    fin.close();
    fout.close();
    return 0;
}