#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <functional>
#include <algorithm>
using namespace std;

template <class T>
class shape
{
public:
    virtual ~shape() { cout << "shape" << endl; }
    virtual void display() const {};
};
template <typename T>
class circle : public shape<T>
{
private:
    static T PI;
    T R;

public:
    circle(T r) : R(r){};
    void display() const { cout << PI * R * R << endl; }
};

template <typename T>
T circle<T>::PI = 3.14;

template <typename T>
class rect : public shape<T>
{
private:
    T w, h;

public:
    rect(T a, T b) : w(a), h(b){};
    void display() const { cout << w * h << endl; }
};

class obj
{
private:
    int index;

public:
    obj(int x) : index(x){};
    int getindex() { return index; }
    bool cmp(obj a, int b) { return a.index > b; }
};

class comp
{
public:
    bool cmp(obj a, int b) { return a.getindex() > b; }
};

int main()
{

    // vector<shape<float> *> vec; //存放的是一个地址
    // vec.push_back(new circle<float>(1.5));
    // vec.push_back(new rect<float>(1.5, 2.5));
    // for (vector<shape<float> *>::iterator it = vec.begin(); it != vec.end(); it++)
    // {
    //     (*it)->display();
    // }
    // return 0;

    //倒序输出单词
    // stack<char> S;
    // string str;
    // cin >> str;
    // for (string::iterator it = str.begin(); it != str.end(); it++)
    // {
    //     S.push(*it);
    // }
    // while (!S.empty())
    // {
    //     cout << S.top();
    //     S.pop();
    // }
    // cout << endl;

    //找到第一个符合条件的值
    // int intArr[] = {1, 2, 3, 4, 5, 6};
    // const int S = sizeof(intArr) / sizeof(int);
    // vector<int> a(intArr, intArr + S);
    // vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 4)); //find_if:遍历得到第一个符合第三个函数对象 bind2nd:固定参数放在第二参数
    // //vector<int>::iterator p = find(a.begin(), a.end(), 40);
    // if (p == a.end())
    //     cout << "NO";
    // else
    //     cout << *p << endl;
    // return 0;

    vector<obj *> vec;
    vec.push_back(new obj(22));
    vec.push_back(new obj(44));
    vec.push_back(new obj(33));
    int num;
    num = count_if(vec.begin(), vec.end(), bind2nd(mem_fun_ref(obj::cmp), 20));
}
