#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char ch;
    int weight;
    int parent;
    int lchild, rchild;
} HTNode, *HuffmanTree; //哈夫曼树结点结构
typedef struct
{
    char *code; //哈夫曼编码
    char ch;    //字符
    int start;
} HfmCode, *HfmCodeForm; //哈夫曼编码表编码结构
int MinVal(HuffmanTree &ht, int i)
{
    int k, min, cnt = 0;
    while (ht[cnt].parent != -1) //找到没有双亲的结点
        cnt++;
    min = ht[cnt].weight;
    k = cnt;
    for (int j = cnt + 1; j < i; j++)
    {
        if (ht[j].parent == -1 && ht[j].weight < min)
        {
            min = ht[j].weight;
            k = j;
        }
    }                 //找到权值最小的结点
    ht[k].parent = 1; //双亲置为非空
    return k;
}
void Select(HuffmanTree &ht, int i, int &s1, int &s2)
{
    int s;
    s1 = MinVal(ht, i);
    s2 = MinVal(ht, i);
    if (s1 > s2)
    { //三角置换，保持序号小在左，序号大在右
        s = s1;
        s1 = s2;
        s2 = s;
    }
} //为没有字符的结点寻找左孩子和右孩子
void InitHfmTree(HuffmanTree &ht, int n)
{
    ht = new HTNode[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++)
    {
        ht[i].ch = ' ';
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    } //给所有结点赋初值
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个字符：\n", i + 1);
        getchar();
        scanf("%c", &ht[i].ch);
        printf("请输入第%d个字符的权值：\n", i + 1);
        scanf("%d", &ht[i].weight);
    } //输入字符集（有字符的结点）
    int lnode, rnode;
    for (int i = n; i < 2 * n - 1; i++)
    {
        Select(ht, i, lnode, rnode);
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    } //构造哈夫曼树
    printf("已成功初始化哈夫曼树！\n");
    printf("所建哈夫曼树的静态链表表示如下:\n");
    printf("------------------------------------\n");
    printf("下标\t字符\t权值\t左孩子\t右孩子\t双亲\n");
    for (int i = 0; i < 2 * n - 1; i++)
    {
        printf("%d\t%c\t%d\t%d\t%d\t%d\t\n", i, ht[i].ch, ht[i].weight, ht[i].lchild, ht[i].rchild, ht[i].parent);
    }
    printf("------------------------------------\n");
}
void BuildHfmForm(HuffmanTree &ht, HfmCodeForm &hf, int n)
{
    //根据哈夫曼树建立哈夫曼编码表
    hf = new HfmCode[n];
    char *cd = (char *)malloc(n * sizeof(char)); //动态分配空间
    cd[n - 1] = '\0';                            //为编码赋上终止符
    int c, f, start;
    for (int i = 0; i < n; i++)
    {
        start = n - 1; //start指向哈夫曼编码开始字符
        hf[i].ch = ht[i].ch;
        for (c = i, f = ht[i].parent; f != -1; c = f, f = ht[f].parent)
            //从叶子结点开始逆向求哈夫曼编码
            if (ht[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        hf[i].code = new char[n - start]; //start减几次，就代表编码有几位
        for (int j = start; j < n; j++)
            hf[i].code[j - start] = cd[j]; //逆序赋值
    }
    printf("哈夫曼编码表如下:\n");
    printf("------------------------------------\n");
    printf("字符\t编码\t权值\n");
    for (int i = 0; i < n; i++)
        printf("%c\t%s\t%d\n", hf[i].ch, hf[i].code, ht[i].weight);
    printf("------------------------------------\n");
}
void Encoding(HuffmanTree &ht, HfmCodeForm &hf, int n)
{
    BuildHfmForm(ht, hf, n);
    //对输入的字符串用哈夫曼编码表进行编码
    char str[50];
    printf("请输入正文：\n");
    getchar();
    gets(str);
    printf("编码后为：\n");
    for (int i = 0; i < strlen(str); i++)
        for (int j = 0; j < n; j++)
            if (str[i] == hf[j].ch)
                printf("%s", hf[j].code);
    printf("\n");
}
void Decoding(HuffmanTree &ht, int n)
{
    char str[50];
    int q = 2 * n - 2;
    printf("请输入需要译码的二进制电文:\n");
    getchar();
    gets(str);
    printf("译码结果为：\n");
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '0')
            q = ht[q].lchild;
        else if (str[i] == '1')
            q = ht[q].rchild;
        if (ht[q].lchild == -1 && ht[q].rchild == -1)
        {
            printf("%c", ht[q].ch);
            q = 2 * n - 2;
        }
    }
    printf("\n");
}
int main()
{
    char input; //指令
    int n = 0;  //字符集大小
    HuffmanTree ht;
    HfmCodeForm hf;
    do
    {
        printf("------------------------------------\n");
        printf("\n");
        printf("         哈夫曼编译码器系统         \n");
        printf("\n");
        printf("---------请输入指令进行操作---------\n");
        printf("I：初始化。\n");
        printf("E：编码。\n");
        printf("D：译码。\n");
        printf("Q：退出系统。\n");
        printf("------------------------------------\n");
        scanf(" %c", &input);
        if (input == 'I')
        {
            printf("请输入字符集大小：\n");
            scanf("%d", &n);
            if (n > 1) //当字符集大小>1
                InitHfmTree(ht, n);
            else //当字符集大小不正确
                printf("请输入正确的字符集大小(n>1)!\n");
        }
        else if (input == 'E')
        {
            if (n == 0)
                printf("未进行初始化操作，请先进行初始化(I)操作！\n");
            else
                Encoding(ht, hf, n);
        }
        else if (input == 'D')
        {
            if (n == 0)
                printf("未进行初始化操作，请先进行初始化(I)操作！\n");
            else
                Decoding(ht, n);
        }
        else if (input == 'Q')
        {
            printf("----------已成功退出系统！----------");
            return 0;
        }
        else
            printf("-------输入错误！请重新输入！-------\n");
    } while (input != 'Q');
    return 0;
}
