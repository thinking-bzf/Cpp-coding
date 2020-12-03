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
void printhou(Tree *&T)
{
	if (T == NULL)
		return;
	else
	{
		printhou(T->left);
		printhou(T->right);
		cout << T->data << " ";
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
		printhou(T);
		cout << endl;
	}
}