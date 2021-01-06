#ifndef _SQSTACK_H_
#define _SQSTACK_H_
template <class T>
class SqStack
{
private:
    T *base;
    T *top;
    int stacksize;

public:
    SqStack(int size = 10);
    ~SqStack();
    void Clear() { top = base; };
    bool IsEmpty() { return base == top; };
    int GetLength() { return top - base; };
    bool GetTop(T &);
    void Push(T);
    bool pop(T &);
    void Show();
};
template <class T>
SqStack<T>::SqStack(int size)
{
    base = new T[size];
    top = base;
    stacksize = size;
}
template <class T>
SqStack<T>::~SqStack()
{
    if (base)
        delete base;
    top = nullptr;
    stacksize = 0;
}
template <class T>
bool SqStack<T>::GetTop(T &out)
{
    if (!this->IsEmpty())
    {
        out = *(top - 1);
        return true;
    }
    return false;
}

template <class T>
void SqStack<T>::Push(T in)
{
    if (top - base == stacksize)
    {
        T *newbase = new T[2 * stacksize];
        for (int i = 0; i < top - base; i++)
            newbase[i] = base[i];
        delete[] base;
        base = newbase;
        top = base + stacksize;
        stacksize *= 2;
    }
    
    *top++ = in;
}
template <class T>
bool SqStack<T>::pop(T &out)
{
    if (!this->IsEmpty())
    {
        out = *--top;
        return true;
    }
    return false;
}

template <class T>
void SqStack<T>::Show()
{
    int mode = 0;
    T *temp;
    for (temp = top - 1; temp >= base; temp--)
    {
        std::cout << *temp << "\t";
        mode++;
        if (mode % 10 == 0)
            std::cout << std::endl;
    }
}

#endif