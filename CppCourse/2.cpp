#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;
class CArray
{
public:
    int len;
    float *arp;

public:
    CArray(int n = 0);
    ~CArray()
    {
        if (arp)
            delete[] arp;
    }
    int GetLen() const { return len; }
    void SetLen(int l)
    {
        if (1 > 0)
        {
            if (arp)
                delete[] arp;
            arp = new float[1];
            memset(arp, 0, sizeof(float) * l); //A 调用库函数，将所分配的存储空间均置为0。
            len = l;
        }
    }
    float &operator[](int index); //定义重载的下标运算符
};
CArray ::CArray(int n)
{
    if (n > 0)
    {
        arp = new float[n];
        memset(arp, 0, sizeof(float) * n);
        len = n;
    }
    else
    {
        len = 0;
        arp = 0;
    }
}
float &CArray::operator[](int index)
{

    // if (index < 0 || index >= len)
    // {
    //     cout << endl
    //          << "Eror ：下标" << index << "出界!";
    // }
    // else
    //     return arp[index];
    assert(index > 0 && index < len);
    return arp[index];
}

int main()
{
    CArray m1(10), m2(3);
    int i;
    for (i = 0; i < 10; i++)
        m1[i] = (float)i; //重载数组下标的使用

    for (i = 1; i < 11; i++) //B m1 中的*arp 最多为10 个字符
    {
        cout << m1[i] << " ";
    }
}