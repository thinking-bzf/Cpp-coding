#include <bits/stdc++.h>
#include <random>
using namespace std;

int xmulty(int x, int y)
{
    int re = 1;
    for (int i = 0; i < y; i++)
        re *= x;
    return re;
}
int random()
{
    int x = rand() % 10;
    return x;
}
// template<class T>
bool gtr(int x, int y)
{
    return x > y;
}
int main()
{
    srand((unsigned)time(NULL));
    vector<int> vec(5);
    generate(vec.begin(), vec.end(), random);
    vector<int> vec1(vec);
    vector<int> vec2(vec);
    vector<int> vec3(vec);
    find_if(vec.begin(), vec.end(), bind2nd(ptr_fun(gtr), 2));
    cout << "n:\t";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    transform(vec.begin(), vec.end(), vec1.begin(), bind1st(ptr_fun(xmulty), 5));
    cout << "5^n:\t";
    copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    transform(vec.begin(), vec.end(), vec2.begin(), bind2nd(ptr_fun(xmulty), 7));
    cout << "n^7:\t";
    copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    transform(vec.begin(), vec.end(), vec.begin(), vec3.begin(), xmulty);
    cout << "n^n:\t";
    copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
}