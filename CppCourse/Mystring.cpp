#include <iostream>
#include <string.h>
using namespace std;
class MyString
{
    char *ptr;
    int size;

public:
    static int m;
    MyString(void);
    MyString(const char *a);
    MyString(const MyString &rhs);
    MyString operator+(const MyString &rhs);
    MyString &operator=(const MyString &rhs);
    friend ostream &operator<<(ostream &out, const MyString &rhs);
    void display();
    ~MyString()
    {
        size = 0;
        delete[] ptr;
    }
};
int MyString::m = 1;
MyString::MyString(void)
{
    size = 0;
    ptr = new char[size + 1];
    strcpy(ptr, "");
}
MyString::MyString(const char *a)
{
    size = strlen(a);
    ptr = new char[size + 1];
    strcpy(ptr, a);
}
MyString::MyString(const MyString &rhs)
{
    size = rhs.size;
    ptr = new char[size + 1];
    strcpy(ptr, rhs.ptr);
}
MyString MyString::operator+(const MyString &rhs)
{
    // MyString temp;
    // temp.size = size + rhs.size;
    // temp.ptr = new char[size + 1];
    // strcpy(temp.ptr, strcat(ptr, rhs.ptr));
    // return temp;
    char temp[size];
    strcpy(temp, ptr);
    delete[] ptr;
    size = size + rhs.size;
    ptr = new char[size + 1];
    strcpy(ptr, temp);
    strcat(ptr, rhs.ptr);
    return *this;
}
MyString &MyString::operator=(const MyString &rhs)
{
    if (size != rhs.size)
    {
        delete[] ptr;
        size = rhs.size;
        ptr = new char[size + 1];
    }
    strcpy(ptr, rhs.ptr);
    return *this;
}

ostream &operator<<(ostream &out, const MyString &rhs)
{
    for (int i = 0; i < rhs.size; i++)
        out << rhs.ptr[i];
    return out;
}

int main()
{
    static int *ptr;
    MyString S1("good"), S2(" morning");
    MyString S;
    cout << S1 << endl
         << S2 << endl;
    S = S1 + S2;
    cout << S << endl;
    int i=1;
    ptr = &MyString::m;

    return 0;
}