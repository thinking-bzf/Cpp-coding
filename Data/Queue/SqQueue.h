#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_
#include <iostream>
using namespace std;
template <class T>
class SqQueue
{
private:
    int m_front; //队头
    int m_rear;  //队尾
    int m_size;
    T *m_base;

public:
    SqQueue(int m = 100);
    ~SqQueue();                                      //析构函数
    void Clear();                                    //清空队列
    bool IsEmpty() const { return m_front == m_rear; } //判断队列为空
    int Length() const;                              //求长度
    T &GetHead() const;                              //取对头元素值
    T &GetLast() const;                              //取队尾元素值
    void Append(const T &);                          //入队
    void Remove();                                   //出队
    void Show();
};
template <class T>
SqQueue<T>::SqQueue(int m)
{
    m_base = new T[m];
    m_front = m_rear = 0;
    m_size = m;
}
template <class T>
SqQueue<T>::~SqQueue()
{
    if (m_base)
        delete[] m_base;
}
template <class T>
void SqQueue<T>::Clear()
{
    m_front = m_rear = 0;
}

template <class T>
int SqQueue<T>::Length() const
{
    if (m_rear > m_front)
        return m_rear - m_front;
    else
        return m_size - m_front + m_rear;
}
template <class T>
T &SqQueue<T>::GetHead() const
{
    return m_base[m_front];
}
template <class T>
T &SqQueue<T>::GetLast() const
{
    return m_base[(m_rear - 1 + m_size) % m_size];
}

template <class T>
void SqQueue<T>::Append(const T &rhs)
{
    
    if ((m_rear + 1) % m_size == m_front)
    {
        T *new_base = new T[2 * m_size];
        int j = 0;
        if (m_front > m_rear)
        {
            for (int i = m_front; i < m_size; i++, j++)
                new_base[j] = m_base[i];
            for (int i = 0; i < m_rear; i++, j++)
                new_base[i] = m_base[j];
        }
        else
            for (int i = m_front; i < m_rear; i++, j++)
                new_base[j] = m_base[i];

        delete m_base;
        m_base = new_base;
        m_front = 0;
        m_rear = j;
        m_size *= 2;
    }
    m_base[m_rear] = rhs;
    m_rear = (m_rear + 1) % m_size;
}
template <class T>
void SqQueue<T>::Remove()
{
    m_front = (m_front + 1) % m_size;
}

template<class T>
void SqQueue<T>::Show()
{
    int mode = 0;
    for (int i = m_front; i < m_rear; i++)
    {
        std::cout << m_base[i] << "\t";
        mode++;
        if (mode % 10 == 0)
            std::cout << std::endl;
    }
}
#endif