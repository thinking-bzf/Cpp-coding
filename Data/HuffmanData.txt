#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
char screen[40][100];
struct Tnode
{
	char data;
	Tnode *left, *right;
};
class BiTree
{
private:
	int size;
	Tnode *root;
	void preTraverse(Tnode *);								//前序遍历
	void midTraverse(Tnode *);								//中序遍历
	void postTraverse(Tnode *);								//后序遍历
	void CreatePreOrder(Tnode *&root, string &str, int &i); //前序加#创建树

	// 前中序创建二叉树
	bool CreatePreInOrder(Tnode *&, string, string, int, int, int &);
	// 中后序创建二叉树
	bool CreatePostInOrder(Tnode *&, string, string, int, int, int &);

	int Getleaves(Tnode *);												 //获取叶子数量的递归实现
	Tnode *Parent(Tnode *, char);										 //寻找双亲节点，返回双亲节点的节点指针
	void Locate(char, Tnode *, Tnode *&, Tnode *, Tnode *&, int, int &); //查找节点，得到双亲节点和所在深度
	void GetDegree(Tnode *, map<int, int> &);							 //获得每个深度·的个数的递归实现
	void ChangeLeftRight(Tnode *);										 //交换左右孩子的递归实现
	void Locate(char x, Tnode *, Tnode *&);								 //定位节点的递归实现
	bool GetNodePath(Tnode *, Tnode *, vector<char> &);					 //获取指定节点的路径的递归实现
	void ConvertTreeStore(Tnode *, char *, int);						 //二叉树的链式存储转顺序存储的内部实现
	void ConvertTreeTolist(Tnode *&, string, int);						 //顺序字符串转链式存储的内部实现

	bool IsBalanced(Tnode *, int); //平衡二叉树判断的递归实现
	bool IsnormalTree(Tnode *);	   //正则二叉树判断的递归实现
	int Draw(Tnode *, int, int);   //作图的内部实现

public:
	BiTree();
	Tnode *GetRoot() { return root; } //获取根节点
	char GetRootData()
	{
		if (root)
			return root->data;
		else
			return '\0';
	}									   //获取根节点的字符
	map<int, int> GetDegree();			   //获取度为0，1，2的分别数量
	bool CountEveryLevel(map<int, int> &); //获取每层的节点个数
	int Getleaves();					   //获取叶子节点个数
	int GetSize() { return size; }
	bool IsEmpty() { return root == nullptr; }
	void Distroy(Tnode *&);			//删除指定节点及其子树
	bool Delete(char);				//指定字符删除节点
	void Clear();					//清空二叉树
	bool GetLeft(char, char &);		//获取指定字符的左孩子节点值
	bool GetRight(char, char &);	//获取指定字符的右孩子节点值
	bool GetLeftBro(char, char &);	//获取指定字符的左兄弟
	bool GetRightBro(char, char &); //获取指定字符的右兄弟

	void CreatePreOrder(string str);		//前序加#创建树
	bool CreatePreInOrder(string, string);	//前中序遍历创建树
	bool CreatePostInOrder(string, string); //中后序遍历创建树
	int GetDepth(Tnode *);					//获取指定节点的深度
	int GetDepth();							//获取整棵树的深度

	void preOrder();							  //前序遍历
	void midOrder();							  //中序遍历
	void postOrder();							  //后序遍历
	void levelOrder();							  //层次遍历
	char Parent(char);							  //指定字符获取双亲节点的字符
	bool Locate(char, Tnode *&, Tnode *&, int &); //根据字符查找节点，获取其父节点，深度
	bool Locate(char x, Tnode *&);				  //根据字符查找节点

	void GetNodePath(Tnode *); //获取指定节点的路径
	void GetAllNodePath();	   //获取所有节点的路径

	void ChangeLeftRight();			//交换左右孩子
	bool Insert(char, char, int);	//根据父节点，左右模式插入或修改节点值
	bool IsBalanced();				//判断是否为平衡二叉树
	bool IsnormalTree();			//判断是否为正则二叉树
	bool IsFull();					//判断是否是满二叉树
	bool IsComplete();				//判断是否是完全二叉树
	char *ConvertTreeStore();		//二叉树的链式存储转顺序存储
	void ConvertTreeTolist(string); //顺序字符串转链式存储
	void PrintTree();				//画图外部接口

	~BiTree();
};

BiTree::BiTree()
{
	size = 0;
	root = nullptr;
}
void BiTree::Distroy(Tnode *&root)
{
	if (root->left)
		Distroy(root->left);
	if (root->right)
		Distroy(root->right);
	delete root;
	root = nullptr;
	size--;
}
void BiTree::Clear()
{
	if (root)
		Distroy(root);
}
BiTree::~BiTree()
{
	if (root)
		Distroy(root);
}
bool BiTree::Delete(char x)
{
	// 如果该节点是根节点，那就将整个树删掉
	if (root->data == x)
	{
		Distroy(root);
		return true;
	}
	// 获取该字符所在的指针的父节点，然后删除其左或右子树
	Tnode *p = Parent(root, x);
	if (p->left && p->left->data == x)
	{
		Distroy(p->left);
		p->left = nullptr;
		return true;
	}
	if (p->right && p->right->data == x)
	{
		Distroy(p->right);
		p->right = nullptr;
		return true;
	}
	return false;
}
int BiTree::Getleaves(Tnode *root)
{
	// 根节点的判断
	if (root == nullptr)
		return 0;
	else if (root->left == nullptr && root->right == nullptr)
		return 1;
	return Getleaves(root->left) + Getleaves(root->right);
}
int BiTree::Getleaves()
{
	return Getleaves(root);
}
bool BiTree::GetLeft(char x, char &out)
{
	Tnode *cur;
	Locate(x, cur);
	if (cur->left)
	{
		out = cur->left->data;
		return true;
	}
	else
		return false;
}
bool BiTree::GetRight(char x, char &out)
{
	Tnode *cur;
	Locate(x, cur);
	if (cur->right)
	{
		out = cur->right->data;
		return true;
	}
	else
		return false;
}
bool BiTree::GetLeftBro(char x, char &out)
{
	Tnode *p = Parent(root, x);
	if (p && p->left)
	{
		// 确保不是自身
		if (p->left && p->left->data != x)
		{
			out = p->left->data;
			return true;
		}
	}
	return false;
}
bool BiTree::GetRightBro(char x, char &out)
{
	Tnode *p = Parent(root, x);
	if (p && p->right)
	{
		// 确保不是自身
		if (p->right && p->right->data != x)
		{
			out = p->right->data;
			return true;
		}
	}
	return false;
}
void BiTree::CreatePreOrder(Tnode *&root, string &str, int &i)
{
	// i表示当前字符串坐在的位置，确保字符串后面有足够的#来设置空指针
	if (i >= str.length())
		str += '#';
	// 如果碰到#或结束符，则将该指针挂空
	if (str[i] == '#' || str[i] == '\0')
		root = nullptr;
	else
	{
		root = new Tnode;
		root->data = str[i];
		size++;
		root->left = root->right = nullptr;
		CreatePreOrder(root->left, str, ++i);
		CreatePreOrder(root->right, str, ++i);
	}
}
void BiTree::CreatePreOrder(string str)
{
	int i = 0;
	CreatePreOrder(root, str, i);
}
void BiTree::preTraverse(Tnode *root)
{
	if (root == nullptr)
		return;
	else
	{
		cout << root->data << " ";
		preTraverse(root->left);
		preTraverse(root->right);
	}
}
void BiTree::midTraverse(Tnode *root)
{
	if (root == nullptr)
		return;
	else
	{
		midTraverse(root->left);
		cout << root->data << " ";
		midTraverse(root->right);
	}
}
void BiTree::postTraverse(Tnode *root)
{
	if (root == nullptr)
		return;
	else
	{
		postTraverse(root->left);
		postTraverse(root->right);
		cout << root->data << " ";
	}
}
int BiTree::GetDepth(Tnode *root)
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
Tnode *BiTree::Parent(Tnode *root, char x)
{
	if (root == nullptr)
		return nullptr;
	if ((root->left && root->left->data == x) || (root->right && root->right->data == x))
		return root;
	Tnode *temp;
	temp = Parent(root->left, x);
	if (temp)
		return temp;
	temp = Parent(root->right, x);
	return temp;
}
char BiTree::Parent(char x)
{
	Tnode *p = Parent(root, x);
	if (p)
		return p->data;
	return '\0';
}
void BiTree::GetDegree(Tnode *root, map<int, int> &Degree)
{
	int cnt = 0;
	if (root->left)
		cnt++;
	if (root->right)
		cnt++;
	Degree[cnt]++;
	if (root->left)
		GetDegree(root->left, Degree);
	if (root->right)
		GetDegree(root->right, Degree);
}
// 获取度为0/1/2的节点数，并将这些存入一个map里面
map<int, int> BiTree::GetDegree()
{
	map<int, int> Degree;
	GetDegree(root, Degree);
	return Degree;
}
int BiTree::GetDepth()
{
	return GetDepth(root);
}
void BiTree::preOrder()
{
	preTraverse(root);
	cout << endl;
}
void BiTree::postOrder()
{
	postTraverse(root);
	cout << endl;
}
void BiTree::midOrder()
{
	midTraverse(root);
	cout << endl;
}
void BiTree::levelOrder()
{
	queue<Tnode *> Q;
	if (root)
		Q.push(root);
	while (!Q.empty())
	{
		Tnode *cur = Q.front();
		Q.pop();
		cout << cur->data << " ";
		if (cur->left)
			Q.push(cur->left);
		if (cur->right)
			Q.push(cur->right);
	}
	cout << endl;
}
bool BiTree::CreatePreInOrder(Tnode *&root, string preStr, string inStr, int low, int high, int &n)
{
	int i;
	// 中序子串的长度小于0时，根节点设为空指针
	if (low > high)
	{
		root = nullptr;
		return true;
	}
	else
	{
		// 将前序的第一个元素挂在该子根节点上
		root = new Tnode;
		root->data = preStr[n];
		root->left = root->right = nullptr;
		size++;
	}
	// 在中序子串找到前序遍历的第一个元素
	for (i = low; i <= high && inStr[i] != preStr[n]; i++)
		;
	if (inStr[i] == preStr[n])
	{
		// n表示前序遍历到了第n个根
		n++;
		if (!CreatePreInOrder(root->left, preStr, inStr, low, i - 1, n))
			return false;
		if (!CreatePreInOrder(root->right, preStr, inStr, i + 1, high, n))
			return false;
	}
	else // inStr[i] 都不等于preStr[n]，找不到根节点，返回false
		return false;
	return true;
}

// 与前中序遍历创建树不同的是，后中序创建树实现创建右子树，然后再创建左子树，因为后序遍历中，
// 从后往前遍历都是右节点，这样就不用费很大劲去找左根节点的位置，直接像前中序左节点累加即可
bool BiTree::CreatePostInOrder(Tnode *&root, string postStr, string inStr, int low, int high, int &n)
{
	int i;
	// 如果长度不够长则挂空指针，并返回true
	if (low > high)
	{
		root = nullptr;
		return true;
	}
	else
	{
		// 将后序的最后一个元素挂在根节点上
		root = new Tnode;
		root->data = postStr[n];
		root->left = root->right = nullptr;
		size++;
	}
	// 在中序遍历中找到后序的最后一个元素所在位置
	for (i = low; i <= high && postStr[n] != inStr[i]; i++)
		;
	if (postStr[n] == inStr[i])
	{
		n--;
		if (!CreatePostInOrder(root->right, postStr, inStr, i + 1, high, n))
			return false;
		if (!CreatePostInOrder(root->left, postStr, inStr, low, i - 1, n))
			return false;
	}
	else //如果找不到最后的元素则返回false
		return false;
	return true;
}
bool BiTree::CreatePostInOrder(string post, string mid)
{
	// 判断两个字符串是否相等，是否存在异词根
	int m = mid.length();
	int n = post.length();
	int cmp[256] = {0};
	if (m != n)
		return false;
	for (int i = 0; i < m; i++)
		cmp[mid[i]]++;
	for (int i = 0; i < n; i++)
	{
		cmp[post[i]]--;
		if (cmp[post[i]] < 0)
			return false;
	}
	int x = post.length() - 1;
	if (CreatePostInOrder(root, post, mid, 0, post.length() - 1, x))
		return true;
	return false;
}
bool BiTree::CreatePreInOrder(string pre, string mid)
{
	// 判断两个字符串是否相等，是否存在异词根
	int m = mid.length();
	int n = pre.length();
	int cmp[256] = {0};
	if (m != n)
		return false;
	for (int i = 0; i < m; i++)
		cmp[mid[i]]++;
	for (int i = 0; i < n; i++)
	{
		cmp[pre[i]]--;
		if (cmp[pre[i]] < 0)
			return false;
	}
	// CreatePreInOrder(root, pre, mid, n);
	int x = 0;
	if (CreatePreInOrder(root, pre, mid, 0, m - 1, x))
		return true;
	return false;
}
// 查找值所在的节点，该节点的深度，节点的双亲元素
void BiTree::Locate(char x, Tnode *root, Tnode *&target, Tnode *parent, Tnode *&parent_target, int depth, int &depth_target)
{
	if (root)
	{
		// 当找到该元素时，将当前查找的根节点设置为目标节点，此时得到的深度值设置为最终深度，此时的双亲节点设置为最终节点
		if (root->data == x)
		{
			target = root;
			depth_target = depth;
			parent_target = parent;
			return;
		}
		// 如果没有找到该节点，则把该节点设置为双亲节点
		else
			parent = root;
		// 先查左子树，再查右子树，递归每次depth+1，根节点左右更新
		Locate(x, root->left, target, parent, parent_target, depth + 1, depth_target);
		Locate(x, root->right, target, parent, parent_target, depth + 1, depth_target);
	}
}
// 单次获取父节点，深度，双亲节点
bool BiTree::Locate(char x, Tnode *&target, Tnode *&parent, int &depth)
{

	Tnode *temp_target = nullptr;
	Tnode *temp_parent = nullptr;
	int temp_depth = 0;
	Locate(x, root, temp_target, nullptr, temp_parent, 1, temp_depth);
	target = temp_target;
	parent = temp_parent;
	depth = temp_depth;
	if (temp_target == nullptr)
	{
		return false;
		cout << "false" << endl;
	}
	return true;
}
// 获取当前节点所在位置
void BiTree::Locate(char x, Tnode *root, Tnode *&target)
{
	if (root)
	{
		// 当找到该元素时，将当前查找的根节点设置为目标节点
		if (root->data == x)
		{
			target = root;
			return;
		}
		// 先查左子树，再查右子树，递归每次depth+1，根节点左右更新
		Locate(x, root->left, target);
		Locate(x, root->right, target);
	}
}
bool BiTree::Locate(char x, Tnode *&target)
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
bool BiTree::CountEveryLevel(map<int, int> &Count)
{
	// map<int, int> Count;
	queue<Tnode *> Q;
	if (root == nullptr)
		return false;
	Q.push(root);
	Q.push(nullptr);
	int level = 1;
	int count = 0;
	while (!Q.empty())
	{
		Tnode *front = Q.front();
		Q.pop();
		if (front == nullptr)
		{
			Count[level] = count;
			level++;
			if (Q.empty())
				break;
			else
				Q.push(nullptr);
			count = 0;
		}
		else
		{
			count++;
			if (front->left)
				Q.push(front->left);
			if (front->right)
				Q.push(front->right);
		}
	}
	return true;
}
bool BiTree::GetNodePath(Tnode *root, Tnode *target, vector<char> &v)
{
	if (root == nullptr)
		return false;
	v.push_back(root->data);
	// found表示是否找到目标值
	bool found = false;
	if (root == target)
	{
		for (int i = 0; i < v.size() - 1; i++)
			cout << v[i] << "->";
		cout << v[v.size() - 1] << endl;
		return true;
	}
	// 如果未找到目标值，先遍历左子树，再遍历右子树，
	if (!found && root->left)
		found = GetNodePath(root->left, target, v);
	if (!found && root->right)
		found = GetNodePath(root->right, target, v);
	// 如果遍历完某条线路之后未发现目标值，则把最近添加的元素删除，然后再退栈，继续便利
	v.pop_back();
	return found;
}
void BiTree::GetNodePath(Tnode *target)
{
	vector<char> v;
	GetNodePath(root, target, v);
}
void BiTree::GetAllNodePath()
{
	queue<Tnode *> Q;
	if (root)
		Q.push(root);
	while (!Q.empty())
	{
		Tnode *cur = Q.front();
		Q.pop();
		GetNodePath(cur);
		if (cur->left)
			Q.push(cur->left);
		if (cur->right)
			Q.push(cur->right);
	}
}
void BiTree::ChangeLeftRight(Tnode *root)
{
	if (root)
	{
		Tnode *temp = root->left;
		root->left = root->right;
		root->right = temp;
		ChangeLeftRight(root->left);
		ChangeLeftRight(root->right);
	}
	else
		return;
}

void BiTree::ChangeLeftRight()
{
	ChangeLeftRight(root);
}
// 返回类型需要变为int表示插入/添加的状态
bool BiTree::Insert(char parent, char target, int mode)
{
	// 需要加入判断是否是树根
	Tnode *ParentNode;
	if (Locate(parent, ParentNode))
	{
		if (mode)
		{
			if (ParentNode->right)
				ParentNode->right->data = target;
			else if (ParentNode->right == nullptr)
			{
				ParentNode->right = new Tnode;
				ParentNode->right->right = ParentNode->right->left = nullptr;
				ParentNode->right->data = target;
			}
		}
		else
		{
			if (ParentNode->left)
				ParentNode->left->data = target;
			else if (ParentNode->left == nullptr)
			{
				ParentNode->left = new Tnode;
				ParentNode->left->right = ParentNode->left->left = nullptr;
				ParentNode->left->data = target;
			}
		}
		size++;
	}
	return false;
}
bool BiTree::IsBalanced(Tnode *root, int depth)
{
	// 如果该节点为空，则传出深度为0
	if (root == nullptr)
	{
		depth = 0;
		return true;
	}
	// 将深度寄存在depth中，进行递归，记录每个节点的深度
	// 先序遍历原理 确认左子树是否平衡，再确认右子树是否平衡
	int left = 0, right = 0;
	if (IsBalanced(root->left, left) && IsBalanced(root->right, right))
	{
		int diff = abs(left - right);
		if (diff <= 1)
		{
			// 记录该节点的深度
			depth = max(left, right) + 1;
			return true;
		}
	}
	return false;
}
bool BiTree::IsBalanced()
{
	int depth = 0;
	return IsBalanced(root, depth);
}
bool BiTree::IsComplete()
{
	map<int, int> DegreeMap;
	DegreeMap = GetDegree();
	return DegreeMap[1] == 0;
}
// 判断是否是正则二叉树
bool BiTree::IsnormalTree()
{
	return IsnormalTree(root);
}
bool BiTree::IsnormalTree(Tnode *root)
{
	if (root == nullptr)
		return true;
	if (root->right == nullptr && root->left == nullptr)
		return true;
	if (root->left && root->right)
	{
		if (IsnormalTree(root->left) && IsnormalTree(root->right))
			return true;
		return false;
	}
	return false;
}
bool BiTree::IsFull()
{
	int depth = GetDepth();
	return (pow(2, depth) - 1) == size;
}
void BiTree::ConvertTreeStore(Tnode *root, char *a, int i)
{
	if (root != nullptr)
	{
		a[i - 1] = root->data;
		if (root->left)
			ConvertTreeStore(root->left, a, i * 2);
		if (root->right)
			ConvertTreeStore(root->right, a, i * 2 + 1);
	}
	else
		a[i - 1] = '#';
}
char *BiTree::ConvertTreeStore()
{
	char *a = new char;
	ConvertTreeStore(root, a, 1);
	return a;
}
void BiTree::ConvertTreeTolist(Tnode *&root, string a, int i)
{
	int len = a.length();
	if (a[i - 1] != '#' && i <= len)
	{
		root = new Tnode;
		root->data = a[i - 1];
		size++;
		root->left = root->right = nullptr;
		if (a[2 * i - 1] != '#')
			ConvertTreeTolist(root->left, a, 2 * i);
		if (a[2 * i] != '#')
			ConvertTreeTolist(root->right, a, 2 * i + 1);
	}
	else if (a[i - 1] == '#')
		return;
}
void BiTree::ConvertTreeTolist(string a)
{
	ConvertTreeTolist(root, a, 1);
}
int BiTree::Draw(Tnode *root, int startx, int y)
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
	screen[y][rootX] = root->data;
	// 开始处理右子树
	endX++; //根节点打印之后，向右边走一个字符的位置，即右子树的初始位置
	if (root->right)
		// 右子树高度与左子树相同，y+2
		endX = Draw(root->right, endX, y + 2);
	return endX; //返回当前字数打完之后，在最右边的什么位置
}
void BiTree::PrintTree()
{
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 65; j++)
			screen[i][j] = ' ';
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
