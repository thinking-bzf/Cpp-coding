#ifndef _Huffmantree_
#define _Huffmantree_
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#define max 10000
//哈夫曼树结点结构
struct HufftreeNode
{
    char ch;
    int weight, parent, lchild, rchild;
};
//哈夫曼树结构
struct Huffmantree
{
    HufftreeNode *ht; //静态树地址
    int htsize;       //树的结点个数
};
//初始化哈夫曼树
void InitHuffmantree(Huffmantree &HT, int n)
{
    HT.ht = new HufftreeNode[2 * n - 1];
    HT.htsize = 2 * n - 1;
}
//销毁哈夫曼树
void DestroyHuffmantree(Huffmantree &HT)
{
    delete[] HT.ht;
    HT.htsize = 0;
}
//在前i个结点找到双亲为0且权值weight最小的结点编号
int MinVal(Huffmantree &HT, int i)
{
    int j, k, min = max;
    for (j = 0; j < i; j++)
        if (HT.ht[j].parent == -1 && HT.ht[j].weight < min)
        {
            min = HT.ht[j].weight;
            k = j;
        }
    HT.ht[k].parent = max;
    return k;
}
//找到两个weight值最小的结点中编号小的结点
void Select(Huffmantree &HT, int i, int &s1, int &s2)
{
    int s;
    s1 = MinVal(HT, i);
    s2 = MinVal(HT, i);
    if (s1 > s2)
    {
        s = s1;
        s1 = s2;
        s2 = s;
    }
}
//根据字符表和权值，建立哈夫曼树
void CreateHaffmantree(Huffmantree &HT, int n, char ch[], int weight[])
{
    int i, s1, s2;
    if (n > 1)
    {
        for (i = 0; i < n; i++)
        {
            HT.ht[i].ch = ch[i];
            HT.ht[i].weight = weight[i];
            HT.ht[i].parent = -1;
            HT.ht[i].lchild = -1;
            HT.ht[i].rchild = -1;
        }
        for (; i < HT.htsize; ++i)
        {
            Select(HT, i, s1, s2);
            HT.ht[s1].parent = HT.ht[s2].parent = i;
            HT.ht[i].lchild = s1;
            HT.ht[i].rchild = s2;
            HT.ht[i].weight = HT.ht[s1].weight + HT.ht[s2].weight;
            HT.ht[i].parent = -1;
            HT.ht[i].ch = ' ';
        }
    }
    cout << "哈夫曼树建立完毕!" << endl;
}
//显示哈夫曼树
void Display(Huffmantree &HT)
{
    int i;
    cout << "所建哈夫曼树的静态链表表示如下:" << endl
         << endl;
    cout << "——-——-——-——-——-——-——-——-——-——-——-——-——-——-——" << endl;
    cout << "下标位置"
         << "  字符"
         << "  权值  "
         << " 左孩子 "
         << " 右孩子 "
         << " 双亲 " << endl;
    for (i = 0; i < HT.htsize; i++)
    {
        cout << setw(6) << i << setw(6) << HT.ht[i].ch << setw(8) << HT.ht[i].weight << setw(9) << HT.ht[i].lchild << setw(8) << HT.ht[i].rchild << setw(6) << HT.ht[i].parent << endl;
    }
    cout << "——-——-——-——-——-——-——-——-——-——-——-——-——-——-——" << endl;
}

//哈夫曼编码结构
struct HCnode
{
    char ch;
    char *pstring;
};
//编码表结构
struct HuffmanCoder
{
    HCnode *hc;
    int hcsize;
};
//初始化编码
void InitHuffmanCoder(HuffmanCoder &HC, int n)
{
    HC.hc = new HCnode[n];
    HC.hcsize = n;
}
//销毁哈夫曼编码
void DestroyHuffmanCoder(HuffmanCoder &HC)
{
    for (int i = 0; i < HC.hcsize; i++)
        delete[] HC.hc[i].pstring;
    delete[] HC.hc;
}
//建立n个字符的哈夫曼编码
void CreateHuffmanCoder(HuffmanCoder &HC, Huffmantree &HT)
{
    int i, j, c, f, start;
    char *cd = new char[HC.hcsize];
    cd[HC.hcsize - 1] = '\0';
    cout << "各个字符的哈夫曼编码为：" << endl
         << endl;
    for (i = 0; i < HC.hcsize; i++)
    {
        start = HC.hcsize - 1; //编码结束符的位置
        HC.hc[i].ch = HT.ht[i].ch;
        //从叶子结点开始逆向求编码
        for (c = i, f = HT.ht[i].parent; f != -1; c = f, f = HT.ht[f].parent)
        {
            if (HT.ht[f].lchild == c)
            {
                cd[--start] = '0';
            }
            else
            {
                cd[--start] = '1';
            }
        }
        HC.hc[i].pstring = new char[HC.hcsize - start];
        cout << "第" << i + 1 << "个字符" << HT.ht[i].ch << "编码是： ";
        for (j = start; j < HC.hcsize; j++)
        {
            cout << cd[j];
            HC.hc[i].pstring[j - start] = cd[j];
        }
        cout << endl;
    }
    cout << endl;
    delete[] cd;
}

#endif