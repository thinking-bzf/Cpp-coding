#include <iostream>
#include "BiTree.h"
using namespace std;
void input(int *x, int start, int end);
void ShowMenu();
void CreateByPre(BiTree &);          //前序创建二叉树
void TraverseBinaryTree(BiTree &);   //树的遍历
void CreateByPreInOrder(BiTree &);   //前中序创建二叉树
void CreateByPostInOrder(BiTree &);  //中后序创建二叉树
void ShowStauts(BiTree &);           //显示二叉树状态
void GetElement(BiTree);             //查找结点
void ShowNodePath(BiTree);           //打印节点路径
void DeleteNode(BiTree &);           //删除节点
void InsertNode(BiTree &);           //插入节点
void SwapTree(BiTree &);             //交换左右子树
void JudgeTreeShape(BiTree &);       //判断二叉树形态
void CreateBTbyArray(BiTree &);      //顺序串创建二叉树
void ShowSequenceStorage(BiTree &T); //链式存储转顺序存储
void PrintTreeShape(BiTree T);       //打印树
int main()
{
    int choice;
    BiTree T;
    while (1)
    {

        int size;
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 16 for choice:";
        input(&choice, 1, 16);
        if (choice == 16)
            break;
        switch (choice)
        {
        case 1:
            // 前序创建二叉树
            if (T.IsEmpty())
                CreateByPre(T);
            else
            {
                T.Clear();
                CreateByPre(T);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            // 各种遍历二叉树
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                TraverseBinaryTree(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            // 前中序创建二叉树
            if (T.IsEmpty())
                CreateByPreInOrder(T);
            else
            {
                T.Clear();
                CreateByPreInOrder(T);
            }

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            // 中后序创建二叉树
            if (T.IsEmpty())
                CreateByPostInOrder(T);
            else
            {
                T.Clear();
                CreateByPostInOrder(T);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            // 清空二叉树
            if (T.IsEmpty())
                cout << "The Binary Tree is empty.";
            else
            {
                T.Clear();
                cout << "The Binary Tree is cleared.";
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            // 显示二叉树状态
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                ShowStauts(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                GetElement(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                ShowNodePath(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            // 删除节点
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                DeleteNode(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 10:
            // 插入节点
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                InsertNode(T);
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 11:
            /* code */
            // 左右子树交换
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                SwapTree(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 12:
            /* code */
            // 判断二叉树形态
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                JudgeTreeShape(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 13:
            /* code */
            // 顺序存储创建二叉树
            if (T.IsEmpty())
                CreateBTbyArray(T);
            else
            {
                T.Clear();
                CreateBTbyArray(T);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 14:
            /* code */
            // 链式转顺序存储
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                ShowSequenceStorage(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 15:
            /* code */
            // 树型打印
            if (T.IsEmpty())
                cout << "The Binay Tree is empty.";
            else
                PrintTreeShape(T);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        }
    }
    return 0;
}

void ShowMenu()
{
    cout << "************************I Love JLJ******************************" << endl;
    cout << endl;
    cout << "*******************Sequence List Basic System*******************" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    1. Create BT(Pre-Order)      2. Traverse Binary Tree      *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    3. Greate BT(Pre-In Order)   4. Greate BT(Post-In Order)  *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    5. Clear Binary Tree         6. Clear Binary Tree         *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    7. Search Node               8. Show Node path            *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    9. Delete Node               10. Insert Node              *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    11. Swap Tree                12. Judge Tree Shape         *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    13. Create BT (Array)        14. Show Sequence Storage    *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*    15. Print Tree Shape         16. Exit                     *" << endl;
    cout << "*                                                              *" << endl;
    cout << "****************************************************************" << endl;
}
void input(int *x, int start, int end)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}

void CreateByPre(BiTree &T)
{
    cout << "Please input the preorder traversal <# as NULL; such as:AB##C##>:";
    string str;
    cin >> str;
    T.CreatePreOrder(str);
    cout << "The Binary Tree is created successfully." << endl;
    TraverseBinaryTree(T);
    cout << "The depth is: " << T.GetDepth() << endl;
}
void TraverseBinaryTree(BiTree &T)
{
    cout << "----------------------Traverse Binary Tree----------------------" << endl;
    cout << "The preorder traversal: ";
    T.preOrder();
    cout << "The inorder traversal: ";
    T.midOrder();
    cout << "The postorder traversal: ";
    T.postOrder();
    cout << "The level-order traverse: ";
    T.levelOrder();
}
void CreateByPreInOrder(BiTree &T)
{
    string pre;
    string in;
    cout << "Input the preorder traversal of the Binary Tree :";
    cin >> pre;
    cout << "Input the inorder traversal of the Binary Tree :";
    cin >> in;

    T.CreatePreInOrder(pre, in);
    cout << "The Binary Tree is created successfully." << endl;
    TraverseBinaryTree(T);
    cout << "The depth is: " << T.GetDepth() << endl;
}
void CreateByPostInOrder(BiTree &T)
{
    string post;
    string in;
    cout << "Input the postorder traversal of the Binary Tree :";
    cin >> post;
    cout << "Input the inorder traversal of the Binary Tree :";
    cin >> in;
    T.CreatePostInOrder(post, in);
    cout << "The Binary Tree is created successfully." << endl;
    TraverseBinaryTree(T);
    cout << "The depth is: " << T.GetDepth() << endl;
}

void ShowStauts(BiTree &T)
{
    // 各种遍历
    TraverseBinaryTree(T);
    cout << "The data of root in the Birany tree is :" << T.GetRootData() << endl;
    cout << "The depth of Binary is :" << T.GetDepth() << endl;
    cout << "The count of nodes in the Binary tree is :" << T.GetSize() << endl;
    cout << "The leaves node in the Binary tree is :" << T.Getleaves() << endl;
    map<int, int> CountMap;
    CountMap = T.GetDegree();
    cout << "The count of node which degree is 1:" << CountMap[1] << endl;
    cout << "The count of node which degree is 2:" << CountMap[2] << endl;

    map<int, int> LevelMap;
    T.CountEveryLevel(LevelMap);
    cout << "The count of node in every level:" << endl;
    int depth = T.GetDepth();
    for (int i = 1; i <= depth; i++)
        cout << "level " << i << ":" << LevelMap[i] << endl;
}
void GetElement(BiTree T)
{
    char x;
    cout << "Please input the value of node to be found:";
    cin >> x;
    Tnode *target;
    if (T.Locate(x, target))
        cout << x << " is found in the tree." << endl;
    else
    {
        cout << x << " is not found in the tree." << endl;
        return;
    }
    cout << "The depth of this node :" << T.GetDepth(target) << endl;
    cout << "The path of this node :";
    T.GetNodePath(target);
    cout << endl;
    cout << "The parent node of this node is :" << T.Parent(x) << endl;
    char Lbro, Rbro;
    if (T.GetLeftBro(x, Lbro))
        cout << "The left brother is :" << Lbro << endl;
    else
        cout << "This node has no left brother." << endl;
    if (T.GetLeftBro(x, Rbro))
        cout << "The right brother is :" << Rbro << endl;
    else
        cout << "This node has no right brother." << endl;

    char Lchild, Rchild;
    if (T.GetLeft(x, Lchild))
        cout << "The left child is :" << Lchild << endl;
    else
        cout << "The node has no left child." << endl;
    if (T.GetLeft(x, Rchild))
        cout << "The right child is :" << Rchild << endl;
    else
        cout << "The node has no right child." << endl;
}

void ShowNodePath(BiTree T)
{
    cout << "The path of all node in the Binary tree:" << endl;
    T.GetAllNodePath();
}

void DeleteNode(BiTree &T)
{
    char x;
    cout << "Please input the value of node to delete:";
    cin >> x;
    if (T.Delete(x))
        cout << "The node is deleted successfully." << endl;
    else
    {
        cout << "The node  don't exist in the tree." << endl;
        return;
    }
    TraverseBinaryTree(T);
}
void InsertNode(BiTree &T)
{
    char p;
    char x;
    int mode;
    cout << "Please input the parent node of the node you want to insert<# as root>:";
    cin >> p;
    cout << "Please input the value of the node to insert :";
    cin >> x;
    cout << "Please input the mode to insert<0-left,1right> :";
    cin >> mode;
    if (T.Insert(p, x, mode))
        cout << "The node is inserted successfully." << endl;
    else
    {
        cout << "There is no node's value is " << p << endl;
        return;
    }
    TraverseBinaryTree(T);
}
void SwapTree(BiTree &T)
{
    TraverseBinaryTree(T);
    T.ChangeLeftRight();
    cout << "After swaping child:" << endl;
    TraverseBinaryTree(T);
}
void JudgeTreeShape(BiTree &T)
{
    // cout << T.GetSize() << endl;
    if (T.IsFull())
        cout << "The tree is Full Tree." << endl;
    else
        cout << "The tree isn't Full Tree." << endl;
    if (T.IsComplete())
        cout << "The tree is Completed Tree." << endl;
    else
        cout << "The tree isn't Completed Tree." << endl;
    if (T.IsBalanced())
        cout << "The tree is Balanced Tree." << endl;
    else
        cout << "The tree isn't Balanced Tree." << endl;
    if (T.IsnormalTree())
        cout << "The tree is Normal Tree." << endl;
    else
        cout << "The tree isn't Normal Tree." << endl;
}

void CreateBTbyArray(BiTree &T)
{
    string array;
    cout << "Please input the Array of the tree :";
    cin >> array;
    T.ConvertTreeTolist(array);
    TraverseBinaryTree(T);
}

void ShowSequenceStorage(BiTree &T)
{
    cout << "The Array of the tree is :";
    cout << T.ConvertTreeStore() << endl;
}
void PrintTreeShape(BiTree T)
{
    cout << "The Binary Tree is :" << endl;
    T.PrintTree();
}