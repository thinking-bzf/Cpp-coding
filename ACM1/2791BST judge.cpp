#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int data;
    Tree *l, *r;
};
struct Tree *T;
void add(Tree *&T, int s)
{
    if (T == NULL)
    {
        T = new Tree;
        T->data = s;
        T->l = T->r = NULL;
    }
    else
    {
        if (T->data > s)
            add(T->l, s);
        else
            add(T->r, s);
    }
}
string tmp;
void preorder(Tree *&T)
{
    if (T == NULL)
        return;
    else
    {
        char x = '0' + T->data;
        tmp += x;
        preorder(T->l);
        preorder(T->r);
    }
}
int main()
{
    int n;
    string t1, t2;
    while (cin >> n && n)
    {
        T = NULL;
        t1.clear();
        t2.clear();
        string a, b;
        cin >> a;
        int size = a.size();
        for (int i = 0; i < size; i++)
        {
            int num = a[i] - '0';
            add(T, num);
        }
        preorder(T);
        t1 = tmp;
        tmp.clear();
        Tree *re;
        for (int i = 0; i < n; i++)
        {

            
            re = NULL;
            cin >> b;
            int sz = b.size();
            for (int i = 0; i < sz; i++)
            {
                int nm = b[i] - '0';
                add(re, nm);
            }
            preorder(re);
            t2 = tmp;
            if (t1 == t2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            tmp.clear();
            t2.clear();
        }
    }
}
