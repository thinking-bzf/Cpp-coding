#include <iostream>
#include <string.h>
#include <algorithm>
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
            memset(arp, 0, sizeof(float) * l);
            len = l;
        }
    }
    float &operator[](int index);
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
    if (index >= 0 && index < len)
    {
        return arp[index];
    }
    else
        throw(index);
}
int main(void)
{
    CArray m1(10), m2(3);
    int i;
    for (i = 0; i < 10; i++)
        m1[i] = (float)i;
    try
    {
        for (i = 1; i < 11; i++)
            cout << m1[i] << " ";
    }
    catch (int i)
    {
        cout << "\nEror ：下标" << i << "出界！" << endl;
    }
    return 0;
} 