#ifndef _SQLIST_H_
#define _SQLIST_H_
#include <iostream>
template <class T>
class SqList
{
private:
    int len;  //存放数据大小
    int size; //存放内存大小 最大可存放的大小
    T *ptr;

public:
    SqList(int m = 0);
    SqList(const SqList<T> &);
    ~SqList();
    bool IsEmpty() const { return len <= 0; }
    int Length() const { return len; }
    void DoubleSize();
    void Show();
    void Clear() { len = 0; }
    bool GetElem(T &, int);
    bool SetElem(T &, int);
    // 查找符合条件的数据元素
    int LocateElem(const T &) const;
    // 在表中指定位置插入
    bool Insert(const T &, int);
    // 表尾插入
    void Append(const T &);
    // 删除表中指定位置的数据元素
    bool Delete(T &, int);
    // 顺序表的遍历
    // void Traverse(void (*visit)(const SqList<T> &));
};

template <class T>
SqList<T>::SqList(int m)
{
    if (m <= 0)
    {
        ptr = NULL;
        len = 0;
        size = 0;
    }
    else
    {
        len = 0;
        size = m;
        ptr = new T[m];
    }
}
template <class T>
// 复制构造
SqList<T>::SqList(const SqList<T> &rhs)
{
    // 如果复制的链表为空
    if (rhs.ptr == NULL)
    {
        ptr = NULL;
        len = 0;
        size = 0;
    }
    // 链表非空
    else
    {
        len = rhs.len;
        ptr = new T[rhs.size];
        size = rhs.size;
        for (int i = 0; i < rhs.Length(); i++)
            ptr[i] = rhs.ptr[i];
    }
}

template <class T>
SqList<T>::~SqList()
{
    if (ptr)
    {
        delete[] ptr;
        size = len = 0;
    }
}
template <class T>
void SqList<T>::Show()
{
    if (len > 0)
        for (int i = 0; i < len; i++)
        {
            std::cout << ptr[i] << "\t";
            if (!((i + 1) % 10))
                std::cout << std::endl;
        }
    std::cout << std::endl;
}

template <class T>
bool SqList<T>::GetElem(T &out, int index)
{
    if (index > 0 && index <= len)
    {
        out = ptr[index - 1];
        return true;
    }
    else
        return false;
}
template <class T>
bool SqList<T>::SetElem(T &in, int index)
{
    if (index > 0 && index <= len)
    {
        ptr[index - 1] = in;
        return true;
    }
    else
        return false;
}

template <class T>
int SqList<T>::LocateElem(const T &in) const
{
    for (int i = 0; i < len; i++)
    {
        if (ptr[i] == in)
            return i + 1;
    }
    return -1;
}
template <class T>
void SqList<T>::DoubleSize()
{
    T *newptr = new T[2 * size + 1];
    for (int i = 0; i < len; i++)
        newptr[i] = ptr[i];
    size = size * 2 + 1;
    if (ptr)
        delete[] ptr;
    ptr = newptr;
}
template <class T>
bool SqList<T>::Insert(const T &in, int index)
{
    if (index > len || index < 1)
        return false;
    // 如果最大空间不够，则扩展两倍空间
    if (len >= size)
        this->DoubleSize();
    if (index == len)
    {
        // 如果插入的位置是末尾元素，则调用append方法
        Append(in);
        return true;
    }
    else
    {
        // 每个在目标元素后面的元素往后移动
        for (int i = len - 1; i >= index - 1; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index - 1] = in;
        len++;
        return true;
    }
    return false;
}

template <class T>
// 末尾元素插入
void SqList<T>::Append(const T &in)
{
    if (len >= size)
        this->DoubleSize();
    ptr[len] = in;
    len++;
}
template <class T>
bool SqList<T>::Delete(T &out, int index)
{
    out = ptr[index - 1];
    if (index > len || index < 1)
        return false;
    for (int i = index - 1; i < len - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    len--;
    return true;
}
#endif