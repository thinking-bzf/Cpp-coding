#include <bits/stdc++.h>
using namespace std;
#define N 105

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree root = NULL;
int n, k[N];

void inOrder(BiTree T) //中序遍历
{

    if (T != NULL)
    {
        inOrder(T->lchild);     //左
        printf("%d ", T->data); // 根
        inOrder(T->rchild);     //右
    }
}
void levelOrder(BiTNode *&root)
{
    if (root == NULL)
        return;
    queue<BiTNode *> q;
    BiTNode *tree = root;
    q.push(tree);
    while (!q.empty())
    {
        tree = q.front();
        cout << tree->data << " ";
        q.pop();
        if (tree->lchild != NULL)
            q.push(tree->lchild);
        if (tree->rchild != NULL)
            q.push(tree->rchild);
    }
}

void insert(int m)
{
    BiTree p, q;
    if (root == NULL)
    {
        root = new BiTNode;
        root->data = m;
        root->lchild = root->rchild = NULL;
    }
    else
    {
        p = root;
        while (m != p->data)
        {
            if ((m < p->data) && (p->lchild != NULL))
            {
                p = p->lchild;
            }
            else if ((m > p->data) && (p->rchild != NULL))
            {
                p = p->rchild;
            }
            else if ((m < p->data) && (p->lchild == NULL))
            {
                q = new BiTNode;
                q->data = m;
                q->lchild = q->rchild = NULL;
                p->lchild = q;
                return;
            }
            else if ((m > p->data) && (p->rchild == NULL))
            {
                q = new BiTNode;
                q->data = m;
                q->lchild = q->rchild = NULL;
                p->rchild = q;
                return;
            }
        }
    }
}

void create(int n)
{

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++)
    {
        insert(k[i]);
    }
}

int main()
{
    while (cin >> n)
    {
        // 多次输入 需要多次将根节点设为空
        root = NULL;
        create(n);
        levelOrder(root);
        cout << endl;
    }
    return 0;
}
