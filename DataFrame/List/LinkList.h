#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <iostream>
template <class T>
class Node
{
public:
    Node<T> *pre;
    Node<T> *next;
    T data;
};

template <class T>
class LinkList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;
    int size;

public:
    LinkList(int m = 0);
    LinkList(const LinkList<T> &);
    ~LinkList();
    bool IsEmpty() const { return length <= 0; }
    int Length() const { return length; }
    void Show();
    void Clear();
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
};
template <class T>
LinkList<T>::LinkList(int m)
{
    head = new Node<T>;
    tail = new Node<T>;
    head->next = tail;
    head->pre = nullptr;
    tail->next = nullptr;
    tail->pre = head;
    length = 0;
    size = m;
}
template <class T>
LinkList<T>::LinkList(const LinkList<T> &rhs)
{
    length = 0;
    size = rhs.size;
    head = new Node<T>;
    tail = new Node<T>;
    head->pre = nullptr;
    tail->next = nullptr;
    head->next = tail;
    tail->pre = head;
    // length = rhs.length;
    Node<T> *temp = rhs.head;
    while (temp->next != rhs.tail)
    {
        temp = temp->next;
        // 将原来的尾节点变成中间节点，把新建的节点作为尾节点
        tail->data = temp->data;
        Node<T> *p = new Node<T>;
        tail->next = p;
        p->pre = tail;
        tail = p;
        length++;
    }
    tail->next = nullptr;
}
template <class T>
LinkList<T>::~LinkList()
{
    if (length == 0)
    {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }
    else
    {
        while (head->next != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
    }
    delete head;
    head = nullptr;
    tail = nullptr;
}
template <class T>
void LinkList<T>::Clear()
{
    Node<T> *temp = head;
    Node<T> *p;
    while (temp->next != tail)
    {
        p = temp->next;
        temp->next = temp->next->next;
        delete p;
    }
    head->next = tail;
    tail->pre = head;
    length = 0;
}
template <class T>
void LinkList<T>::Show()
{
    Node<T> *temp = head;
    int Mode = 1;
    while (temp->next != tail)
    {
        temp = temp->next;
        std::cout << temp->data << "\t";
        if (Mode % 10 == 0)
            std::cout << std::endl;
        Mode++;
    }
    std::cout << std::endl;
}

template <class T>
bool LinkList<T>::GetElem(T &out, int index)
{
    if (index > length || index < 1)
        return false;
    int i = 1;
    Node<T> *temp = head;
    while (i <= index && temp->next)
    {
        i++;
        temp = temp->next;
    }
    out = temp->data;
    return true;
}
template <class T>
bool LinkList<T>::SetElem(T &in, int index)
{
    if (index > length || index < 1)
        return false;
    int i = 1;
    Node<T> *temp = head;
    while (i <= index && temp->next)
    {
        i++;
        temp = temp->next;
    }
    temp->data = in;
    return true;
}
template <class T>
int LinkList<T>::LocateElem(const T &in) const
{
    Node<T> *temp = head;
    int i = 0;
    while (temp->next != tail)
    {
        temp = temp->next;
        i++;
        if (temp->data == in)
            return i;
    }
    return -1;
}

template <class T>
bool LinkList<T>::Insert(const T &in, int index)
{
    if (index > length || index < 1)
        return false;
    if (size == length)
        size++;
    Node<T> *temp = head;
    int i = 1;
    while (i++ < index)
        temp = temp->next;
    Node<T> *p = new Node<T>;
    p->data = in;
    p->pre = temp;
    p->next = temp->next;
    temp->next->pre = p;
    temp->next = p;
    length++;
    return true;
}
template <class T>
void LinkList<T>::Append(const T &in)
{
    tail->data = in;
    Node<T> *p = new Node<T>;
    tail->next = p;
    p->pre = tail;
    p->next = nullptr;
    tail = p;
    length++;
}

template <class T>
bool LinkList<T>::Delete(T &out, int index)
{
    if (index > length || index < 1)
        return false;
    Node<T> *temp = head;
    int i = 1;
    while (i <= index && temp->next)
    {
        i++;
        temp = temp->next;
    }
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    delete temp;
    length--;
    return true;
}
#endif