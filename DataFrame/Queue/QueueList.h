#ifndef _QUEUELIST_H_
#define _QUEUELIST_H_
#include <iostream>
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class QueueList
{
private:
    // int m_front; //队头
    Node<T> *m_rear; //队尾
    Node<T> *m_front;
    int m_length;

public:
    QueueList();            //队尾对头都变成空指针
    ~QueueList();           //析构函数
    void Clear();           //清空队列
    bool IsEmpty() const;   //判断队列为空
    int Length() const;     //求长度
    T &GetHead() const;     //取对头元素值
    T &GetLast() const;     //取队尾元素值
    void Append(const T &); //入队
    void Remove();          //出队
    void Show();
};
template <class T>
QueueList<T>::QueueList()
{
    m_front = m_rear = new Node<T>;
    m_front->next = nullptr;
}
template <class T>
QueueList<T>::~QueueList()
{
    Clear();
    delete m_front;
}
template <class T>
void QueueList<T>::Clear()
{
    Node<T> *p;
    while (m_front->next != nullptr)
    {
        p = m_front->next;
        m_front->next = p->next;
        delete p;
    }
    m_rear = m_front;
}
template <class T>
bool QueueList<T>::IsEmpty() const
{
    return m_front == m_rear;
}
template <class T>
int QueueList<T>::Length() const
{
    return m_length;
}

template <class T>
T &QueueList<T>::GetHead() const
{
    return m_front->next->data;
}
template <class T>
T &QueueList<T>::GetLast() const
{
    return m_rear->data;
}
template <class T>
void QueueList<T>::Append(const T &in)
{
    Node<T> *p = new Node<T>;
    p->data = in;
    p->next = nullptr;
    m_rear->next = p;
    m_rear = p;
    m_length++;
}
template <class T>
void QueueList<T>::Remove()
{
    Node<T> *p = m_front->next;
    m_front->next = p->next;
    if (p == m_rear)
        m_rear = m_front;
    delete p;
    m_length--;
}
template <class T>
void QueueList<T>::Show()
{
    int mode = 0;
    Node<T> *p = m_front;
    while (p->next != nullptr)
    {
        std::cout << p->next->data << "\t";
        mode++;
        if (mode % 10 == 0)
            std::cout << std::endl;
        p = p->next;
    }
}
#endif