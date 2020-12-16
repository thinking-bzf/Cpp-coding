#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

// 哈夫曼树需要保存的东西：权值列表（用优先队列存储），对应编码的值，对应值的数量，
// 用权值列表创建对应二叉树，二叉树存放的东西：权值
// 二叉树引用：只要叶子节点就可

/*
    流程：输入流得到字符，将内容以及次数存入有优先队列中（作为一个节点队列出队列）
    单优先队列不空的时候，从优先队列出两个最小的，
*/

using namespace std;
struct chNode
{
    int count;
    char s;
};
char screen[40][300];
struct Tnode
{
    chNode data;
    Tnode *left, *right;
};
struct cmp
{
    bool operator()(const Tnode *a, const Tnode *b) const
    {
        return a->data.count >= b->data.count;
    }
};
bool compare(pair<char, string> a, pair<char, string> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
class HuffmanTree
{
private:
    int size;
    Tnode *root;
    Tnode *Parent(Tnode *, char); //寻找双亲节点，返回双亲节点的节点指针

    int GetDepth(Tnode *);                           //获取指定节点的深度
    void Locate(char x, Tnode *, Tnode *&);          //定位节点的递归实现
    int Draw(Tnode *, int, int);                     //作图的内部实现
    void Code(Tnode *, map<char, string> &, string); //编码的内部实现

public:
    HuffmanTree();
    Tnode *GetRoot() { return root; } //获取根节点
    char GetRootData()
    {
        if (root)
            return root->data.s;
        else
            return '\0';
    }                                      //获取根节点的字符
    map<int, int> GetDegree();             //获取度为0，1，2的分别数量
    bool CountEveryLevel(map<int, int> &); //获取每层的节点个数
    int Getleaves();                       //获取叶子节点个数
    int GetSize() { return size; }
    bool IsEmpty() { return root == nullptr; }
    void Distroy(Tnode *&);                       //删除指定节点及其子树
    bool Delete(char);                            //指定字符删除节点
    void Clear();                                 //清空二叉树
    int GetDepth();                               //获取整个树的深度
    char Parent(char);                            //指定字符获取双亲节点的字符
    bool Locate(char, Tnode *&, Tnode *&, int &); //根据字符查找节点，获取其父节点，深度
    bool Locate(char x, Tnode *&);                //根据字符查找节点
    void Create(string);
    vector<pair<char, string>> Code(map<char, string> &); //对哈夫曼树进行编码

    void PrintTree(); //画图外部接口

    ~HuffmanTree();
};

HuffmanTree::HuffmanTree()
{
    size = 0;
    root = nullptr;
}
void HuffmanTree::Distroy(Tnode *&root)
{
    if (root->left)
        Distroy(root->left);
    if (root->right)
        Distroy(root->right);
    delete root;
    root = nullptr;
    size--;
}
void HuffmanTree::Clear()
{
    if (root)
        Distroy(root);
}
HuffmanTree::~HuffmanTree()
{
    if (root)
        Distroy(root);
}

void HuffmanTree::Create(string str)
{
    map<char, int> Map;
    priority_queue<Tnode *, vector<Tnode *>, cmp> qu;
    for (int i = 0; i < str.length(); i++)
        Map[str[i]]++;
    for (map<char, int>::iterator iter = Map.begin(); iter != Map.end(); iter++)
    {
        Tnode *temp = new Tnode;
        temp->data.s = iter->first;
        temp->data.count = iter->second;
        temp->right = temp->left = nullptr;
        qu.push(temp);
    }

    while (qu.size() > 1)
    {
        Tnode *temp1 = qu.top();
        qu.pop();
        Tnode *temp2 = qu.top();
        qu.pop();
        int sum = temp1->data.count + temp2->data.count;
        Tnode *node = new Tnode;
        node->data.count = sum;
        node->data.s = '#';
        node->left = temp1;
        node->right = temp2;
        qu.push(node);
    }
    if (!qu.empty())
        root = qu.top();
    // this->PrintTree();
}

void HuffmanTree::Code(Tnode *root, map<char, string> &Map, string str)
{
    if (root->data.s != '#')
    {
        Map[root->data.s] = str;
        size++;
    }

    else
    {
        if (root->left)
            Code(root->left, Map, str + '0');
        if (root->right)
            Code(root->right, Map, str + '1');
    }
}

vector<pair<char, string>> HuffmanTree::Code(map<char, string> &target)
{
    map<char, string> Map;
    string s = "";
    Code(root, Map, s);
    vector<pair<char, string>> vec;
    for (map<char, string>::iterator iter = Map.begin(); iter != Map.end(); ++iter)
        vec.push_back(pair<char, string>(iter->first, iter->second));
    sort(vec.begin(), vec.end(), compare);
    target = Map;
    return vec;
}
int HuffmanTree::GetDepth()
{
    return GetDepth(root);
}
int HuffmanTree::GetDepth(Tnode *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int Dleft = GetDepth(root->left);
        int Dright = GetDepth(root->right);
        return (Dleft > Dright) ? (Dleft + 1) : (Dright + 1);
    }
}
Tnode *HuffmanTree::Parent(Tnode *root, char x)
{
    if (root == nullptr)
        return nullptr;
    if ((root->left && root->left->data.s == x) || (root->right && root->right->data.s == x))
        return root;
    Tnode *temp;
    temp = Parent(root->left, x);
    if (temp)
        return temp;
    temp = Parent(root->right, x);
    return temp;
}
char HuffmanTree::Parent(char x)
{
    Tnode *p = Parent(root, x);
    if (p)
        return p->data.s;
    return '\0';
}
// 获取当前节点所在位置
void HuffmanTree::Locate(char x, Tnode *root, Tnode *&target)
{
    if (root)
    {
        // 当找到该元素时，将当前查找的根节点设置为目标节点
        if (root->data.s == x)
        {
            target = root;
            return;
        }
        // 先查左子树，再查右子树，递归每次depth+1，根节点左右更新
        Locate(x, root->left, target);
        Locate(x, root->right, target);
    }
}
bool HuffmanTree::Locate(char x, Tnode *&target)
{
    Tnode *temp_target = nullptr;
    if (x == '#')
    {
        target = root;
        return true;
    }
    Locate(x, root, temp_target);
    if (temp_target == nullptr)
    {
        cout << "false" << endl;
        return false;
    }
    target = temp_target;
    return true;
}
int HuffmanTree::Draw(Tnode *root, int startx, int y)
{
    // 当前子树的作图右边界
    int endX = startx;

    // 中序递归，先处理左子树
    // 如果当前节点有左子树，先打印左子树，得到图形的右边界
    // 子树的高度位置y，再当前节点的下面两行
    if (root->left)
        endX = Draw(root->left, startx, y + 2) + 1;

    // 当前节点的x坐标
    int rootX = endX;
    // y是高度的位置，是由屏幕的行数决定的
    // rootX是水平位置，由第二维的坐标决定
    screen[y][rootX] = root->data.s;
    // 开始处理右子树
    endX++; //根节点打印之后，向右边走一个字符的位置，即右子树的初始位置
    if (root->right)
        // 右子树高度与左子树相同，y+2
        endX = Draw(root->right, endX, y + 2);
    return endX; //返回当前字数打完之后，在最右边的什么位置
}
void HuffmanTree::PrintTree()
{
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 65; j++)
            screen[i][j] = '_';
    Draw(root, 0, 0);
    // 用中序遍历把二叉树的图形写入screen二维数组中
    // screen[][]屏幕缓冲
    // 输入screen数组
    int height = GetDepth() * 2;
    for (int i = 0; i < height; i++)
    {
        screen[i][64] = '\0';
        cout << "\t" << screen[i] << endl;
    }
}

// int main()
// {
//     string a = "CAS;CAT;SAT;AT";
//     HuffmanTree tree;
//     tree.Create(a);
//     tree.PrintTree();
//     map<char, string> Map = tree.Code();
//     for (map<char, string>::iterator iter = Map.begin(); iter != Map.end(); ++iter)
//         cout << iter->first << " " << iter->second << endl;
// }