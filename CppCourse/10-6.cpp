#include <iostream>
#include <cstring>
#include <list>
#include <iterator>
#include<stack>
using namespace std;
template <class T>
void exchange(list<T> &l1, typename list<T>::iterator p1, list<T> &l2, typename list<T>::iterator p2)
{
     list<T> l3;
     l3.splice(l3.begin(), l1, p1, l1.end());
     l1.splice(l1.end(), l2, p2, l2.end());
     l2.splice(l2.end(), l3, l3.begin(), l3.end());
}
int main()
{

     int a[5] = {11, 22, 33, 44, 55};
     int b[5] = {1, 2, 3, 4, 5};
     list<int> l1(a, a + 5), l2(b, b + 5);
     list<int>::iterator it1 = l1.begin();
     list<int>::iterator it2 = l2.begin();
     cout << "l1的第四位置开始和l2的第四位置开始交换" << endl;
     cout << "Before exchange:" << endl
          << "p1: ";
     copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
     cout << endl
          << "p2: ";
     copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, " "));
     cout << endl;
     advance(it1, 3);
     advance(it2, 3);
     exchange(l1, it1, l2, it2);
     cout << "After exchange:" << endl
          << "p1: ";
     copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
     cout << endl
          << "p2: ";
     copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, " "));
     cout << endl;
}