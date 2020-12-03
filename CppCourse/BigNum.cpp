#include <iostream>
#include <cstring>
using namespace std;
class BigNum
{
private:
    int a[500];
    int len;

public:
    BigNum(const char *s = "");
    BigNum(const BigNum &);
    BigNum &operator=(const BigNum &);      //重载赋值运算符，大数之间进行赋值运算
    BigNum operator+(const BigNum &) const; //重载加法运算符，两个大数之间的相加运算
    BigNum operator-(const BigNum &) const; //重载减法运算符，两个大数之间的相减运算
    BigNum operator*(const BigNum &)const;  //重载乘法运算符，两个大数之间的相乘运算
    BigNum operator/(const BigNum &) const; //重载除法运算符，大数除以一个数
    bool operator>(const BigNum &T) const;
    friend istream &operator>>(istream &, BigNum &); //重载输入运算符
    friend ostream &operator<<(ostream &, BigNum &); //重载输出运算符
};
BigNum::BigNum(const char *s) //构造函数
{
    len = 0;
    memset(a, 0, sizeof(a));
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        a[i] = s[i] - '0';
        len++;
    }
}
BigNum::BigNum(const BigNum &rhs) //复制构造
{
    len = 0;
    for (int i = 0; i < rhs.len; i++)
    {
        a[i] = rhs.a[i];
        len++;
    }
}
BigNum &BigNum::operator=(const BigNum &rhs) //重载赋值运算符
{
    len = 0;
    for (int i = 0; i < rhs.len; i++)
    {
        a[i] = rhs.a[i];
        len++;
    }
    return *this;
}
BigNum BigNum::operator+(const BigNum &rhs) const
{
    BigNum result;
    int i = 0;
    while (i < len || i < rhs.len)
    {
        result.a[i] += a[i] + rhs.a[i];
        if (result.a[i] >= 10)
        {
            result.a[i] -= 10;
            result.a[i + 1]++;
        }
        result.len++;
        i++;
    }
    while (i < len)
    {
        result.a[i] = a[i];
        i++;
        result.len++;
    }
    while (i < rhs.len)
    {
        result.a[i] = rhs.a[i];
        i++;
        result.len++;
    }
    return result;
}
BigNum BigNum::operator-(const BigNum &rhs) const
{
    BigNum result;
    BigNum temp(*this);
    int i = 0;
    while (i < temp.len)
    {
        result.a[i] = temp.a[i] - rhs.a[i];
        if (result.a[i] < 0)
        {
            temp.a[i + 1]--;
            result.a[i] += 10;
        }
        if (temp.a[temp.len - 1] == 0)
            temp.len--;
        result.len++;
        i++;
    }
    while (i < temp.len)
    {
        result.a[i] = temp.a[i];
        i++;
    }
    return result;
}
BigNum BigNum::operator*(const BigNum &rhs) const
{
    BigNum result;
}
istream &operator>>(istream &in, BigNum &b) //重载输入
{
    char ch[205];
    in >> ch;
    int len1 = strlen(ch);
    for (int i = len1 - 1, j = 0; i >= 0; i--, j++)
    {
        int n = ch[i] - '0';
        b.a[j] = n;
        b.len++;
    }
    return in;
}
ostream &operator<<(ostream &out, BigNum &b) //重载输出
{
    for (int i = b.len - 1; i >= 0; i--)
    {
        out << b.a[i];
    }
    cout << endl;
    return out;
}
bool BigNum::operator>(const BigNum &T) const
{
    int ln;
    if (len > T.len)
        return true;
    else if (len == T.len)
    {
        ln = len - 1;
        while (a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if (ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    int T;
    cin >> T;
    BigNum a;
    BigNum b = "100000000000000000000";
    BigNum c = "1";
    for (int i = 0; i < T; i++)
    {
        cin >> a;
        if (a > b)
            cout << "Zhang San will never have girlfriend!" << endl;
        else
        {
            BigNum d = a - c;
            cout << d << endl;
        }
    }
}
