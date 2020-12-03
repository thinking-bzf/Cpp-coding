#include <iostream>
using namespace std;
class Counter
{
private:
    int c;

public:
    Counter() { c = 0; }
    Counter(int x) : c(x) {}
    Counter operator+(const Counter);
    Counter operator+(int x);
    friend ostream &operator<<(ostream &out, Counter &rhs);
};
Counter Counter::operator+(const Counter rhs)
{
    return Counter(c + rhs.c);
}
Counter Counter::operator+(int x)
{
    return Counter(c + x);
}
ostream &operator<<(ostream &out, Counter &rhs)
{
    out << rhs.c;
    return out;
}
int main()
{
    Counter c1(1), c2(2), c3;
    c3 = c1 + c2;
    cout << "c1 = 1,c2 = 2" << endl;
    cout << "c3 = c1 + c2 ->c3 = " << c3 << endl;
    c1 = c3 + 3;
    cout << "c1 = c3 + 3 ->c1 = " << c1 << endl;
}
