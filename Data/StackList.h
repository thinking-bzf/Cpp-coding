#ifndef _STACKLIST_H_
#define _STACKLIST_H_
#include <iostream>
template <class T>
struct Node //  内嵌结点类
{
    T data;
    Node<T> *next;
};

template <class T>
class StackList
{
private:
    Node<T> *m_sp; //链表首指针 对应栈顶
    int length;

public:
    StackList() : m_sp(nullptr), length(0){};
    ~StackList();
    void Clear();
    bool IsEmpty();
    int GetLength() { return length; };
    bool GetTop(T &);
    void Push(T);
    bool pop(T &);
    void Show();
};
template <class T>
StackList<T>::~StackList()
{
    Clear();
}
template <class T>
void StackList<T>::Show()
{
    Node<T> *p = m_sp;
    int mode = 0;
    while (p != nullptr)
    {
        std::cout << p->data << "\t";
        mode++;
        if (mode % 10 == 0)
            std::cout << std::endl;
        p = p->next;
    }
}
template <class T>
bool StackList<T>::IsEmpty()
{
    return m_sp == nullptr;
}
template <class T>
bool StackList<T>::GetTop(T &out)
{
    if (this->IsEmpty())
        return false;
    else
        out = m_sp->data;
    return true;
}

template <class T>
void StackList<T>::Push(T in)
{
    Node<T> *p = new Node<T>;
    p->data = in;
    p->next = m_sp;
    m_sp = p;
    length++;
}
template <class T>
bool StackList<T>::pop(T &out)
{
    if (this->IsEmpty())
        return false;
    else
    {
        Node<T> *p = m_sp;
        out = m_sp->data;
        m_sp = p->next;
        delete p;
        length--;
        return true;
    }
}
template <class T>
void StackList<T>::Clear()
{
    while (m_sp != nullptr)
    {
        Node<T> *p = m_sp;
        m_sp = m_sp->next;
        delete p;
    }
}
#endif