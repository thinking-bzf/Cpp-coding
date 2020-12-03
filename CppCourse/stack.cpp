#define MAX 100
#include <iostream>
using namespace std;
class stack_
{
    int num[MAX] = {0};
    int top; //栈元素个数

public:
    void init(void);
    void push(int x);
    void pop(void);
    bool empty_(void);
    int front_(void);
};

void stack_::init(void) //初始化
{
    top = 0;
}
void stack_::push(int x) //进栈
{
    if (top == MAX)
    {
        cout << "Stack is full!" << endl;
    }
    else
    {
        top++;
        num[top] = x;
    }
}

int stack_::front_(void) //取栈顶元素
{
    if (top <= 0)
    {
        cout << "Stack is underflow!" << endl;
        return 0;
    }

    return num[top];
}

bool stack_::empty_(void) //判栈空
{
    if (top > 0)
        return 1;
    return 0;
}
void stack_::pop(void) //出栈
{
    top--;
    int *p;
    p = (num + top + 1);
    *p = NULL;
}
int main()
{
    stack_ a, b;
    a.init();
    b.init();
    int v, x;
    while (cin >> v >> x)
    {
        if (v == 1) //连等号
            a.push(x);
        if (v == 2)
            b.push(x);
    }
    while (a.empty_())
    {
        int y;
        y = a.front_();
        a.pop();
        cout << y << " ";
    }
    cout << endl;
    while (b.empty_())
    {
        int y;
        y = b.front_();
        b.pop();
        cout << y << " ";
    }
}