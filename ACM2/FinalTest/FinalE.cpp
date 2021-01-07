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

void levelOrder(Tree *&root)
{
    if (root == NULL)
        return;
    queue<Tree *> q;
    Tree *tree = root;
    q.push(tree);
    while (!q.empty())
    {
        tree = q.front();
        cout << q.front()->data << " ";
        q.pop();
        if (tree->left != NULL)
            q.push(tree->left);
        if (tree->right != NULL)
            q.push(tree->right);

        
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
        levelOrder(T);
        cout << endl;
    }
}