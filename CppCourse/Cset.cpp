#include <iostream>
#include <algorithm>
using namespace std;
class CSet
{
public:
    //构造函数
    CSet();
    //增加元素
    bool Add(int x);
    //显示集合
    void Display() const;
    //并集
    CSet Union(const CSet &rhs) const;
    CSet intersect(const CSet &rhs) const;
    CSet diff(const CSet &rhs) const;
    //是否包含元素x
    bool In(int x) const;

private:
    enum
    {
        MaxSIZE = 100
    };
    int m_iDatasA[MaxSIZE]; //集合元素,递增排序表示
    int m_ICount;           //元素个数
};

//构造函数
CSet::CSet() : m_ICount(0)
{
}

//增加元素
bool CSet::Add(int x)
{
    if (In(x))
        return false; //元素已在集合中
    if (m_ICount >= MaxSIZE)
        throw "OverFlow"; //集合已满, 抛出异常待处理
    int i = m_ICount - 1;
    while (i >= 0 && x < m_iDatasA[i])
    {
        m_iDatasA[i + 1] = m_iDatasA[i];
        i--; //从后往前,元素后移
    }
    m_iDatasA[i + 1] = x; //填入元素
    m_ICount++;           //调整元素个数
    return true;
}

//显示集合
void CSet::Display() const
{
    cout << "{";
    int i;
    for (i = 0; i < m_ICount - 1; i++)
    {
        cout << m_iDatasA[i] << ",";
    }
    if (i < m_ICount)
        cout << m_iDatasA[i];
    cout << "}" << endl;
}

//并集,结果为A、B并集，效率为O（M+N)
CSet CSet::Union(const CSet &rhs) const
{
    CSet result;
    int i, j;
    i = j = 0;
    while (i < m_ICount && j < rhs.m_ICount)
    {
        if (result.m_ICount >= MaxSIZE)
            throw "OverFlow"; //集合已满, 抛出异常待处理
        //元素小先处理
        if (m_iDatasA[i] < rhs.m_iDatasA[j])
        {
            result.m_iDatasA[result.m_ICount++] = m_iDatasA[i];
            i++;
        }
        else if (m_iDatasA[i] == rhs.m_iDatasA[j])
        {
            result.m_iDatasA[result.m_ICount++] = m_iDatasA[i];
            i++;
            j++;
        }
        else
        {
            result.m_iDatasA[result.m_ICount++] = rhs.m_iDatasA[j];
            j++;
        }
    }
    while (i < m_ICount) //抄送其余元素
    {
        if (result.m_ICount >= MaxSIZE)
            throw "OverFlow"; //集合已满, 抛出异常待处理
        result.m_iDatasA[result.m_ICount++] = m_iDatasA[i];
        i++;
    }
    while (j < rhs.m_ICount) //抄送rhs其余元素
    {
        if (result.m_ICount >= MaxSIZE)
            throw "OverFlow"; //集合已满, 抛出异常待处理
        result.m_iDatasA[result.m_ICount++] = rhs.m_iDatasA[j];
        j++;
    }
    return result;
}
//交集
CSet CSet::intersect(const CSet &rhs) const
{
    CSet result;
    int i, j;
    i = 0, j = 0;
    while (i < m_ICount && j < rhs.m_ICount)
    {
        if (result.m_ICount >= MaxSIZE)
            throw "OverFlow"; //集合已满, 抛出异常待处理
        if (m_iDatasA[i] > rhs.m_iDatasA[j])
            j++;
        else if (m_iDatasA[i] < rhs.m_iDatasA[j])
            i++;
        else if (m_iDatasA[i] == rhs.m_iDatasA[j])
        {
            result.m_iDatasA[result.m_ICount++] = m_iDatasA[i];
            i++;
            j++;
        }
    }
    return result;
}
//差集
CSet CSet::diff(const CSet &rhs) const
{
    CSet result;
    int i, j;
    int flag;
    for (i = 0; i < m_ICount; i++)
    {
        flag = 1;
        for (j = 0; j < rhs.m_ICount && flag; j++)
        {
            if (m_iDatasA[i] == rhs.m_iDatasA[j])
                flag = 0;
        }
        if (flag)
            result.m_iDatasA[result.m_ICount++] = m_iDatasA[i];
    }
    return result;
}
//是否包含元素x
bool CSet::In(int x) const
{
    int i = 0;
    while (i < m_ICount && x > m_iDatasA[i])
        i++;
    if (i < m_ICount && x == m_iDatasA[i])
        return true;
    return false;
}

int main()
{
    CSet A, B, S, Q, C;
    int i, m, n, x;

    cin >> m >> n;
    //建立A 集
    for (i = 0; i < m; i++)
    {
        cin >> x;
        A.Add(x);
    }
    //建立B 集
    for (i = 0; i < n; i++)
    {
        cin >> x;
        B.Add(x);
    }

    A.Display();
    B.Display();

    S = A.Union(B);
    S.Display();
    Q = A.intersect(B);
    Q.Display();
    C = A.diff(B);
    C.Display();
    return 0;
}