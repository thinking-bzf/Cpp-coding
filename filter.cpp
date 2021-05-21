typedef struct Lnode
{                       //声明结点类型和指向结点的指针类型
    ElemType data;      //结点的数据域
    struct Lnode *next; //结点的指针域
} Lnode, *LinkList;     //LinkList为指向结构体Lnod的指针类型
// 构造一个空的线性表（带头结点）
Status InitList(LinkList &L)
{
    // 申请一个结点空间, 作为链表的头结点，并使L指向此头结点
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; // 头结点指针域为空，该链表为空表

    return OK;
}
int ListEmpty(LinkList L)
{ //若L为空，则返回1，否则返回0

    if (L->next) // 头结点指针域非空
        return 0;
    else
        return 1;
}
//销毁单链表L,最开始指针指向头结点
Status DestroyList(LinkList &L)
{
    LNode *p; //或者LinkList p，指向当前要销毁的结点；
    while (L)
    { //循环条件，L！=NULL，遍历所有结点，逐一删除
        p = L;
        L = L->next;
        free(p);
    }
    return OK;
}
//清空单链表L P=L->next;指向首元结点
Status DestroyList(LinkList &L)
{

    LNode *p， *q; //或者LinkList p,q；
    p = L->next;
    while (p)
    { //循环条件，没到表尾

        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; //头结点指针域设置为空
    return OK;
}
//返回L中数据元素个数
int ListLength(LinkList L)
{

    int i = 0;   // i为计数器
    Lnode *p;    //或者LinkList p
    p = L->next; // p指向第一个结点
    while (p)    // 用p循环遍历到表尾，用i逐一计数
    {
        i++;
        p = p->next;
    }
    return i;
}
// 返回链表中第i个数据元素的值
Status GetElem(LinkList L, int i, ElemType &e)
{
    //获取L中第i个元素的内容，通过变量e返回
    int j = 1; // j为计数器
    LNode *p;
    p = L->next; // p指向第一个结点

    while (p && j < i)
    { // 顺序向后查找,直到p指向第i个元素或者p为空
        p = p->next;
        ++j;
    }
    if (！P || j > i)
        return ERROR; //第i个元素不存在，p为空还不存在
    e = p->data;
    return OK;
}
//返回位置（地址）
int LocateElem(LinkList L, ElemType e)
{
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
//返回位置序号
int LocateElem(LinkList L, ElemType e)
{
    p = L->next;
    j = 1;
    while (p && p->data != e)
    {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}

// 在带头结点的单链线性表L中第i个位置之前插入元素e
Status ListInsert(LinkList &L, int i, ElemType e)
{
    j = 0;
    p = L;
    while (p && j < i - 1)
    { // 寻找第i-1个结点
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) // i小于1或者大于表长+1
        return ERROR;
    s = (LNode *)malloc(sizeof(LNode)); // 生成新结点
    s->data = e;                        // 插入L中
    s->next = p->next;
    p->next = s;
    return OK;
}

// 在带头结点的单链线性表L中，删除第i个元素,并由e返回其值
Status ListDelete(LinkList &L, int i, ElemType &e)
{
    j = 0;
    p = L;
    q;
    while (p->next && j < i - 1)
    { // 寻找第i-1个结点,并令p指向要删除结点的前趋
        p = p->next;
        ++j;
    }
    if (!p->next || j > i - 1) // 删除位置不合理
        return ERROR;
    q = p->next;       //临时保存被删结点的地址已备释放
    p->next = q->next; //改变删除结点前趋结点的指针域
    e = q->data;       //保存删除结点的数据域
    free(q);           //释放删除结点的空间
    return OK;
}
//头插法
Void CreatList_h(LinkList &L, int n)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //建立一个带头结点的单链表
    for (i = n; i > 0; --i)
    {
        p = (LNode *)malloc(sizeof(LNode)); //生成新结点p
        scanf(&p->data);                    //输入元素值
        p->next = L->next;                  //插入到表的前端
        L->next = p;
    }
}
//尾插法
Void CreatList_r(LinkList &L, int n)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //建立一个带头结点的单链表
    r = L;          //尾指针r指向头结点
    for (i = 0; i < n; ++i)
    {
        p = (LNode *)malloc(sizeof(LNode)); //生成新结点p
        scanf(&p->data);                    //输入元素值
        p->next = NULL;
        r->next = p; //插入到表的尾部
        r = p;       //r指向新的尾结点
    }
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    // 已知单链线性表La和Lb得元素按照非递减排序
    // 归并La和Lb得到的新的单链线性表Lc Lc的元素按照非递减排序
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(pb);
}