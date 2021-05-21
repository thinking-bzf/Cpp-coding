#include <bits/stdc++.h>
using namespace std;
#define N 100

typedef struct BiTNode
{
    char data;
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

void insert(int m)
{
    BiTree p1, p2;
    if (root == NULL)
    {
        root = new BiTNode;
        root->data = m;
        root->lchild = root->rchild = NULL;
    }
    else
    {
        p1 = root;
        while (m != p1->data)
        {
            if ((m < p1->data) && (p1->lchild != NULL))
            {
                p1 = p1->lchild;
            }
            else if ((m > p1->data) && (p1->rchild != NULL))
            {
                p1 = p1->rchild;
            }
            else if ((m < p1->data) && (p1->lchild == NULL))
            {
                p2 = new BiTNode;
                p2->data = m;
                p2->lchild = p2->rchild = NULL;
                p1->lchild = p2;
                return;
            }
            else if ((m > p1->data) && (p1->rchild == NULL))
            {
                p2 = new BiTNode;
                p2->data = m;
                p2->lchild = p2->rchild = NULL;
                p1->rchild = p2;
                return;
            }
        }
    }
}

void create()
{
    cout << "输入节点数量：";
    cin >> n;
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
    create();
    cout << "中序遍历输出：" << endl;
    inOrder(root);
    return 0;
}
