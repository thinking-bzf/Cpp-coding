#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class Array
{
private:
    T *list;
    int size;

public:
    Array(int sz = 50);
    Array(const Array<T> &a);
    ~Array();
    Array<T> &operator=(const Array<T> &rhs);
    T &operator[](int i);
    const T &operator[](int i) const;
    operator T *();
    operator const T *() const;
    int getSize() const;
    void resize(int sz);
};

template <class T>
Array<T>::Array(int sz)
{
    assert(sz >= 0);
    size = sz;
    list = new T[size];
}

template <class T>
Array<T>::~Array()
{
    delete[] list;
}
template <class T>
Array<T>::Array(const Array<T> &a)
{
    size = a.size;
    list = new T[size];
    for (int i = 0; i < a.size; i++)
        list[i] = a.list[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (&rhs != this)
    {
        delete[] list;
        size = rhs.size;
        list = new T[size];
    }
    for (int i = 0; i < rhs.size; i++)
        list[i] = rhs.list[i];
    return *this;
}

template <class T>
T &Array<T>::operator[](int i)
{
    if (i >= 0 && i < size)
        return list[i];
}

template <class T>
const T &Array<T>::operator[](int i) const
{
    if (i >= 0 && i < size)
        return list[i];
}

template <class T>
Array<T>::operator T *()
{
    return list;
}

template <class T>
Array<T>::operator const T *() const
{
    return list;
}

template <class T>
int Array<T>::getSize() const
{
    return size;
}

template <class T>
void Array<T>::resize(int sz)
{
    assert(sz >= 0);
    if (size == sz)
        return;
    T *newlist = new T[sz];
    int n = min(sz, size);
    for (int i = 0; i < n; i++)
        newlist[i] = list[i];
    delete[] list;
    list = newlist;
    size = sz;
}

int main()
{
    int n;
    cout << "The count of the class is:" << endl;
    cin >> n;
    Array<float> A(n);
    float sum;
    for (int i = 0; i < n; i++)
    {
        cout << "NO." << i + 1 << " Input your score:" << endl;
        cin >> A[i];
        sum += A[i];
    }
    cout << "The average score of class is " << sum / n << endl;
    return 0;
}