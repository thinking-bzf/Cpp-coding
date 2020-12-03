#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int data;
    Tree *left, *right;
};

struct Tree *T;
int flag = 0;
void add(Tree *&T, int s)
{
    if (T == NULL)
    {
        T = new Tree;
        T->data = s;
        T->left = T->right = NULL;
    }
    else
    {
        if (s < T->data)
            add(T->left, s);
        else
            add(T->right, s);
    }
}
void printpre(Tree *&T)
{
    if (T == NULL)
        return;
    else
    {
        if (!flag)
        {
            cout << T->data;
            flag = 1;
        }
        else
            cout <<" "<< T->data;
        printpre(T->left);
        printpre(T->right);
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        T = NULL;
        flag = 0;
        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            add(T, num);
        }
        printpre(T);
        cout << endl;
    }
}