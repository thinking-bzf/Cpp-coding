#include <iostream>
#include <algorithm>
using namespace std;
class CStack
{
public:
    CStack() : m_sp(nullptr) //构造函数
    {
    }
    ~CStack(); //析构函数
    CStack(const CStack &rhs);
    CStack &operator=(const CStack &rhs);
    CStack(CStack &&rhs);
    CStack &operator=(CStack &&rhs);

    void push(int x);   //入栈
    bool empty() const; //判栈空
    int top() const;    //非空时取栈顶元素
    void pop();         //非空时出栈
private:
    struct Node //  内嵌结点类
    {
        Node() : next(nullptr) {} //结点建立时指针域值为nullptr
        int data;
        Node *next;
    };
    Node *m_sp; //链表首指针
};

CStack::~CStack()
{
    //删除所有结点
    while (m_sp != nullptr)
    {
        Node *p = m_sp; //临时指针变量p
        m_sp = m_sp->next;
        delete p; //删除p所指结点，删除后不可使用该结点
    }
}

void CStack::push(int x)
{
    Node *p = new Node; //动态分配1个结点
    p->data = x;
    p->next = m_sp;
    m_sp = p;
}

bool CStack::empty() const
{
    return (m_sp == nullptr);
}
int CStack::top() const
{
    return m_sp->data;
}

void CStack::pop()
{
    Node *p = m_sp;
    m_sp = p->next;
    delete p;
}
//将栈内所有元素出栈并显示
void DumpStack(CStack &S)
{
    while (!S.empty())
    {
        int x;
        x = S.top();
        cout << x << "  ";
        S.pop();
    }
    cout << endl;
}
//栈的拷贝构造代码
CStack::CStack(const CStack &rhs) //CStack S3(S1);
{
    m_sp = nullptr; //先对要构造的对象的头链指针，防止构造未初始化
    if (rhs.m_sp)   //如果rhs的链表不为空的话进行操作
    {
        m_sp = new Node;
        m_sp->data = rhs.m_sp->data;
        Node *p = m_sp;
        Node *q = rhs.m_sp->next; //指向rhs链表指针，因为为const 所以要新建
        while (q)
        {
            Node *s = new Node; //新建一个Node结构，储存新的数据
            s->data = q->data;
            p->next = s;
            p = s;
            q = q->next;
        }
    }
}
//栈的复制赋值代码
CStack &CStack::operator=(const CStack &rhs) //S4 = S2;  ->  S2.operator=(s2)
{
    CStack tmp(rhs); //复制构造，因为不能对rhs修改
    Node *p = m_sp;
    m_sp = tmp.m_sp;
    tmp.m_sp = p; //把this和tmp交换，这样把rhs复制给了this，又可以直接把tmp释放。
    return *this;
}
//栈的移动构造代码
CStack::CStack(CStack &&rhs)
{
    m_sp = rhs.m_sp; //把链表头交换，实现赋值，rhs直接不要了
    rhs.m_sp = NULL;
}
//栈的移动赋值代码
CStack &CStack::operator=(CStack &&rhs)
{
    Node *p = this->m_sp; //和复制赋值的道理一样
    this->m_sp = rhs.m_sp;
    rhs.m_sp = p;
    return *this;
}
int main()
{
    CStack S1, S2;
    int v, x;

    while (cin >> v >> x && v != 0)
    {
        if (v == 1)
            S1.push(x);
        else
            S2.push(x);
    }

    CStack S3(S1);
    CStack S4;
    CStack tmp1(S1);
    CStack tmp2 = S2;
    S4 = S2;
    S1.push(100);
    S2.push(200);
    S3.push(300);
    S4.push(400);

    CStack S6 = S3;
    CStack S5(std::move(tmp1)); //指定移动构造
    S6 = std::move(tmp2);       //指定移动赋值
    S5.push(500);
    S6.push(600);

    DumpStack(S1);
    DumpStack(S2);
    DumpStack(S3);
    DumpStack(S4);
    DumpStack(S5);
    DumpStack(S6);
}

// S1 100 3 2 1
// S2 200 6 4 2
// S3 300 3 2 1
// S4 400 6 4 2
// S5 500 3 2 1
// S6 600 6 4 2