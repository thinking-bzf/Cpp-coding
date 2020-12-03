#include <iostream>
using namespace std;

class CSet
{
public:
    CSet();                               //构造函数
    ~CSet();                              //析构函数，释放链表
    CSet(const CSet &);                   //拷贝构造函数
    CSet(CSet &&) noexcept;               //移动构造函数
    bool Remove(int x);                   //删除元素x
    bool In(int x);                       //是否包含元素x
    CSet &operator=(const CSet &rhs);     //复制赋值
    CSet &operator=(CSet &&rhs) noexcept; //移动赋值
    bool Add(int x);                      //增加元素
    void Display();                       //显示集合
    CSet Join(const CSet &rhs) const;     //结果为A、B交集
    CSet Sum(const CSet &rhs) const;      //结果为A,B并集
    CSet differ(const CSet &rhs) const;   //结果为A,B差集

private:
    struct Node
    {
        int data;
        Node *next;
    } * m_pHead; // 集合采用递增排序单链表表示
};
//构造函数
CSet::CSet()
{
    m_pHead = new Node;
    m_pHead->next = NULL;
}
//析构函数，释放链表
CSet::~CSet()
{
    while (m_pHead)
    {
        Node *p = m_pHead;
        m_pHead = p->next;
        delete p;
    }
}
//拷贝构造函数
CSet::CSet(const CSet &rhs)
{
    m_pHead = new Node;
    Node *last = m_pHead;
    Node *p = rhs.m_pHead->next;
    while (p)
    {
        Node *q = new Node;
        q->data = p->data;
        last->next = q;
        last = q;
        p = p->next;
    }
    last->next = NULL;
}
//增加元素
bool CSet::Add(int x)
{
    Node *p = m_pHead;
    while (p->next && (p->next->data < x))
    {
        p = p->next;
    }
    if (p->next && p->next->data == x)
        return false;
    Node *q = new Node;
    q->data = x;
    q->next = p->next;
    p->next = q;
    return true;
}
//移动构造函数
CSet::CSet(CSet &&rhs) noexcept
{
    m_pHead = rhs.m_pHead;
    rhs.m_pHead = NULL;
}
//删除元素x
bool CSet::Remove(int x)
{
    Node *p = m_pHead;
    while (p->next->data < x && p->next)
        p = p->next;
    if (p->next->data == x && p->next)
    {
        p->next = p->next->next;
        delete p->next;
        return true;
    }
    return false;
}
//是否包含元素x
bool CSet::In(int x)
{
    Node *p = m_pHead;
    while (p->next && p->next->data < x)
    {
        p = p->next;
    }
    if (p->next->data == x && p->next)
        return true;
    return false;
}
//复制赋值
CSet &CSet::operator=(const CSet &rhs)
{
    CSet temp(rhs);
    Node *t = m_pHead;
    m_pHead = temp.m_pHead;
    temp.m_pHead = t;
    return *this;
}
//移动赋值
CSet &CSet::operator=(CSet &&rhs) noexcept
{
    Node *p = this->m_pHead;
    this->m_pHead = rhs.m_pHead;
    rhs.m_pHead = p;
    return *this;
}
//显示集合
void CSet::Display()
{
    cout << "{";
    Node *p = m_pHead->next;
    while (p)
    {
        cout << p->data;
        p = p->next;
        if (p)
            cout << ",";
    }
    cout << "}" << endl;
}
CSet CSet::Join(const CSet &rhs) const
{
    CSet result;
    Node *last = result.m_pHead;
    Node *p = m_pHead->next;
    Node *q = rhs.m_pHead->next;

    while (p && q)
    {
        if (p->data == q->data)
        {
            Node *s = new Node;
            s->data = p->data;
            last->next = s;
            last = s;
            p = p->next;
            q = q->next;
        }
        else if (p->data > q->data)
        {
            q = q->next;
        }
        else if (q->data > p->data)
        {
            p = p->next;
        }
    }
    last->next = NULL;
    return result;
}
//AB并集
CSet CSet::Sum(const CSet &rhs) const
{
    CSet result;
    Node *last = result.m_pHead;
    Node *p = m_pHead->next;
    Node *q = rhs.m_pHead->next;
    while (p && q)
    {
        if (p->data < q->data)
        {
            Node *s = new Node;
            s->data = p->data;
            last->next = s;
            last = s;
            p = p->next;
        }
        else if (p->data == q->data)
        {
            Node *s = new Node;
            s->data = p->data;
            last->next = s;
            last = s;
            p = p->next;
            q = q->next;
        }
        else if (p->data > q->data)
        {
            Node *s = new Node;
            s->data = q->data;
            last->next = s;
            last = s;
            q = q->next;
        }
    }
    while (p)
    {
        Node *s = new Node;
        s->data = p->data;
        last->next = s;
        last = s;
        p = p->next;
    }
    while (q)
    {
        Node *s = new Node;
        s->data = q->data;
        last->next = s;
        last = s;
        q = q->next;
    }
    last->next = NULL;
    return result;
}
CSet CSet::differ(const CSet &rhs) const
{
    CSet result;
    Node *last = result.m_pHead;
    Node *p = m_pHead->next;
    Node *q = rhs.m_pHead->next;
    int flag;
    while (p)
    {
        flag = 1;
        while (q && flag)
        {
            if (q->data == p->data)
            {
                flag = 0;
            }
            q = q->next;
        }
        if (flag)
        {
            Node *s = new Node;
            s->data = p->data;
            last->next = s;
            last = s;
        }
        p = p->next;
    }
    last->next = NULL;
    return result;
}
int main()
{
    CSet A, B, S, S2;

    int i, m, n, x;
    cin >> m >> n;

    for (i = 0; i < m; i++)
    {
        cin >> x;
        A.Add(x);
    }
    for (i = 0; i < n; i++)
    {
        cin >> x;
        B.Add(x);
    }
    CSet C, D, E;
    A.Display();
    B.Display();

    C = A.Sum(B);
    D = A.Join(B);
    E = A.differ(B);
    C.Display();
    D.Display();
    E.Display();
    return 0;
}