#include <stdio.h>
#include <stdlib.h>
typedef struct Tnode
{
    char data;
    Tnode *left, *right;
} Tnode;

typedef struct BiTree
{
    Tnode *root;
} BiTree;
// &表示引用这样可以使得main函数和接口函数之间的数据同步
void CreateBiTree(Tnode *&T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = (Tnode *)malloc(sizeof(Tnode *));
        T->data = ch;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}

void preTraverse(Tnode *root)
{
    if (root == nullptr)
        return;
    else
    {
        printf("%c ", root->data);
        preTraverse(root->left);
        preTraverse(root->right);
    }
}
void midTraverse(Tnode *root)
{
    if (root == nullptr)
        return;
    else
    {
        midTraverse(root->left);
        printf("%c ", root->data);
        midTraverse(root->right);
    }
}

void postTraverse(Tnode *root)
{
    if (root == nullptr)
        return;
    else
    {
        postTraverse(root->left);
        postTraverse(root->right);
        printf("%c ", root->data);
    }
}


int main()
{
    BiTree T;
    printf("请输入要建立的二叉树的先序序列，用#表示空树（单个字符表示结点）:");
    CreateBiTree(T.root);
    printf("二叉树的前序遍历:");
    preTraverse(T.root);
    printf("\n二叉树的中序遍历:");
    midTraverse(T.root);
    printf("\n二叉树的后序遍历:");
    postTraverse(T.root);
}