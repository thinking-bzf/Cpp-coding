#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b)//计算最大公约数
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
class Num
{
private:
    int num; //分子
    int den; //分母

public:
    Num(int n = 1, int d = 1);
    Num(const Num &);
    Num operator+(const Num &) const;
    Num operator-(const Num &) const;
    Num operator*(const Num &)const;
    Num operator/(const Num &) const;
    Num &operator=(Num &&) noexcept;
    void Display();
};
Num::Num(int n, int d)
{
    num = n;
    den = d;
    int temp = gcd(abs(den), abs(num));
    num = num / temp;
    den = den / temp;
}
Num::Num(const Num &rhs)
{
    num = rhs.num;
    den = rhs.den;
}
void Num::Display()
{
    cout << num;
    if (den != 1)
    {
        cout << "/" << den;
    }
}
Num Num::operator*(const Num &rhs) const
{
    Num result(*this);
    result.num *= rhs.num;
    result.den *= rhs.den;
    int temp = gcd(abs(result.den), abs(result.num));
    if (result.den < 0 && result.num < 0)
    {
        result.den = -result.den;
        result.num = -result.num;
    }
    result.den /= temp;
    result.num /= temp;
    return result;
}
Num Num::operator/(const Num &rhs) const
{
    Num result(*this);
    result.num *= rhs.den;
    result.den *= rhs.num;
    int temp = gcd(abs(result.den), abs(result.num));
    if (result.den < 0 && result.num < 0)
    {
        result.den = -result.den;
        result.num = -result.num;
    }
    result.den /= temp;
    result.num /= temp;

    return result;
}
Num Num::operator+(const Num &rhs) const
{
    Num result(*this);
    int m = rhs.num * result.den;
    result.den *= rhs.den;
    result.num *= rhs.den;
    result.num += m;
    int temp = gcd(abs(result.den), abs(result.num));
    result.den /= temp;
    result.num /= temp;
    return result;
}
Num Num::operator-(const Num &rhs) const
{
    Num result(*this);
    int m = rhs.num * result.den;
    result.den *= rhs.den;
    result.num *= rhs.den;
    result.num -= m;
    int temp = gcd(abs(result.den), abs(result.num));
    result.den /= temp;
    result.num /= temp;
    return result;
}
Num &Num::operator=(Num &&rhs) noexcept
{
    this->den = rhs.den;
    this->num = rhs.num;
    return *this;
}
int main()
{

    int m, n;
    cin >> m >> n;
    Num n1(m, n);
    cin >> m >> n;
    Num n2(m, n);
    n1.Display();
    cout << endl;
    n2.Display();
    cout << endl;
    Num a, b, c, d;
    a = n1 + n2;
    b = n1 - n2;
    c = n1 * n2;
    d = n1 / n2;
    a.Display();
    cout << "\t";
    b.Display();
    cout << "\t";
    c.Display();
    cout << "\t";
    d.Display();
}