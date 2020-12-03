#include <iostream>
#include <assert.h>
using namespace std;
// class Array
// {
// private:
//     int size;
//     int *ptr;

// public:
//     Array(int *a, int i) : size(i)
//     {
//         ptr = new int[size];
//         memcpy(ptr, a, sizeof(a));
//     }
//     virtual ~Array() { delete[] ptr; }
//     Array(const Array &src);
//     Array operator=(const Array &src);
//     int &operator[](int index); //a[2]=5 返回某数组的元素
//     friend ostream &operator<<(ostream &out, const Array &obj);
// };
// Array::Array(const Array &src)
// {
//     size = src.size;
//     ptr = new int[size];
//     for (int i = 0; i < size; i++)
//         ptr[i] = src.ptr[i];
// }

// Array Array::operator=(const Array &src)
// {
//     delete[] ptr; // 删除已存在的数组对象

//     size = src.size;
//     ptr = new int[size];
//     for (int i = 0; i < size; i++)
//         ptr[i] = src.ptr[i];
//     return *this;
// }
// int &Array::operator[](int index)
// {
//     assert(index && index < size);
//     return ptr[index];
// }
// ostream &operator<<(ostream &out, const Array &obj)
// {
//     for (int i = 0; i < obj.size; i++)
//         out << obj.ptr[i] << " ";
//     cout << endl;
//     return out;
// }

// int main()
// {
//     int a[3] = {0, 1, 2};

//     Array ar(a, 3),ar1=ar;
//     ar[2] = 100;
//     ar1 = ar;
//     cout << ar;
// }

// template <typename T> //函数模板
// T abs(T a)
// {
//     return a > 0 ? a : -a;
// }
// int main()
// {
//     cout << abs<float>(2) << endl//隐含<>可进行强制转换
//          << abs<int>(2.5) << endl;
// }

template <typename T>
class Arr
{
private:
    int len;
    T *ptr;

public:
    Arr(int l) : len(l) { ptr = new T[len]; }
    ~Arr() { delete[] ptr; }
    Arr(const Arr &src);
};

template <typename T> // 具体化类对象方法定义 template <typename T>+尖括号限定
Arr<T>::Arr(const Arr<T> &src)
{
    len = src.len;
    ptr = new T[len];
}

int main()
{
    Arr<int> a(10);   //定义时需要用不同的数据类型进行实例化
    Arr<float> b(10);
}