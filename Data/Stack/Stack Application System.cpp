#include <iostream>
#include "SqStack.h"
#include <string.h>
#include <string>
#include <map>
using namespace std;
// 记录进制中每个字符代表的数值
map<char, int> Map1;
map<int, char> Map2;

void input(int *x, int start, int end);
void ShowMenu();
void CreateStack(SqStack<int> &s);
void PushToStack(SqStack<int> &s);
void PopformStack(SqStack<int> &s);
void GetTopofStack(SqStack<int> &s);
void ClearStack(SqStack<int> &s);
void PalindromeString();
void NumberSystemConversion();
void PalindromeNumber();
int main()
{
    int choice;
    SqStack<int> stack(60);
    while (1)
    {
        int size;
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 16 for choice:";
        input(&choice, 1, 16);
        if (choice == 16)
            break;
        switch (choice)
        {
        case 1:
            CreateStack(stack);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            if (!stack.IsEmpty())
            {
                cout << "The length of stack is " << stack.GetLength() << endl;
                stack.Show();
            }
            else
                cout << "The stack is empty.";
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            PushToStack(stack);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            PopformStack(stack);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            GetTopofStack(stack);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            ClearStack(stack);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            PalindromeString();
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            NumberSystemConversion();
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            PalindromeNumber();
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 10:
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 11:
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 12:
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 13:
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 14:
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 15:
            /* code */
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        }
    }
    return 0;
}
void ShowMenu()
{
    cout << "*******************I Love JLJ********************************" << endl;
    cout << endl;
    cout << "*******************Stack Application System******************" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     1. Create Stack         2. Show Stack                 *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     3. Push to stack        4. Pop form Stack             *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     5. Get Top of Stack     6. Clear Stack                *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     7. Palindrome String    8. Number System Conversion   *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     9. Palindrome Number    10. Brackets Matching         *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     11. Hanoi Tower         12. Expression alues          *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     13. Backpack Problem    14. N Queens Problem          *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*     15. Maze Problem        16. Exit                      *" << endl;
    cout << "*                                                           *" << endl;
    cout << "*************************************************************" << endl;
}
void input(int *x, int start, int end)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}

void CreateStack(SqStack<int> &s)
{
    if (s.IsEmpty())
        for (int i = 1; i <= 60; i++)
            s.Push(i);
    else
    {
        s.Clear();
        for (int i = 1; i <= 60; i++)
            s.Push(i);
    }
    cout << "Create sucessfully." << endl;
    s.Show();
}

void PushToStack(SqStack<int> &s)
{
    int temp;
    cout << "Please input a number to push:";
    input(&temp, 1, 2333);
    s.Push(temp);
    cout << "Push successfully." << endl;
    s.Show();
}

void PopformStack(SqStack<int> &s)
{
    if (s.IsEmpty())
        cout << "The stack is empty" << endl;
    else
    {
        int temp;
        s.pop(temp);
        cout << "Pop data " << temp << " successfully. The current stack is:" << endl;
        s.Show();
    }
}

void GetTopofStack(SqStack<int> &s)
{
    if (s.IsEmpty())
        cout << "The stack is empty" << endl;
    else
    {
        int temp;
        s.GetTop(temp);
        cout << "The top data is " << temp << endl;
    }
}

void ClearStack(SqStack<int> &s)
{
    if (s.IsEmpty())
        cout << "The stack is empty." << endl;
    else
    {
        s.Clear();
        cout << "The current stack has been cleared." << endl;
    }
}
bool IsPalindrome(string str)
{
    SqStack<char> s;
    int len = str.length();
    // 将字符串堆栈
    for (int i = 0; i < len; i++)
        s.Push(str[i]);
    char temp;
    bool flag = true;
    // 栈出 判断每次出栈之后的元素和字符串取出的元素是否一样
    for (int i = 0; i < len; i++)
    {
        s.pop(temp);
        if (temp != str[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void PalindromeString()
{
    string str;
    while (1)
    {
        cout << "Please input a string to judge:(Press 0 to return menu.)";
        // scanf("%s", str);
        cin >> str;
        if (str == "0")
            break;
        if (IsPalindrome(str))
            cout << "It is Palindrome string." << endl;
        else
            cout << "It is not Palindrome String." << endl;
    }
}
// 对map的初始化
void InitMap()
{
    for (int i = '0', j = 0; i <= '9'; i++)
        Map1[i] = j++;
    for (char i = 'a', j = 10; i <= 'z'; i++)
        Map1[i] = j++;
    for (char i = 'A', j = 36; i <= 'Z'; i++)
        Map1[i] = j++;
    for (int i = 0, j = '0'; i <= 9; i++)
        Map2[i] = j++;
    for (int i = 10, j = 'a'; i <= 35; i++)
        Map2[i] = j++;
    for (int i = 36, j = 'A'; i <= 61; i++)
        Map2[i] = j++;
}
// 将进制转换封装成一个函数
SqStack<char> Numbertranslation(string value, int sbase, int obase, int &temp)
{
    InitMap();
    SqStack<char> s;
    SqStack<char> s2;
    SqStack<char> result;
    int base10;
    int power = 1;

    for (int i = 0; i < value.length(); i++)
        s2.Push(value[i]);
    while (!s2.IsEmpty())
    {
        char str;
        s2.pop(str);
        base10 += Map1[str] * power;
        power *= sbase;
    }
    temp = base10;
    // 将十进制的数字转换成n进制
    while (base10)
    {
        s.Push(Map2[base10 % obase]);
        base10 /= obase;
    }
    return s;
}
void NumberSystemConversion()
{
    cout << "To convert a number from source base to objective base. Each base of a number is" << endl
         << "between 2 and 62. Characters a-z stand for 10-35 and A-Z stand for 36-61" << endl;
    int sbase, obase;
    cout << "Please input the sourse base<2-62>:";
    input(&sbase, 2, 62);
    cout << "Please input the objective base<2-62>:";
    input(&obase, 2, 62);
    // 将字符和对应的权值存入map中
    // InitMap();
    cout << "Please input the number Base " << sbase << ":";
    string value;
    int flag = 0;
    // 判断输入的数值是否合法
    while (!flag)
    {
        cin >> value;
        int len = value.length();
        for (int i = 0; i < len; i++)
        {
            // 如果超出进制就退出 并进入下一次输入循环
            if (Map1[value[i]] > sbase)
            {
                flag = 0;
                cout << "The number is over sourse base, please input again:";
                break;
            }
            flag = 1;
        }
    }
    int temp;
    char str;
    SqStack<char> s = Numbertranslation(value, sbase, obase, temp);
    cout << "The decimal number of " << value << "<" << sbase << "> is " << temp << endl;
    cout << "The number " << value << "<" << sbase << "> in base " << obase << " is ";
    while (!s.IsEmpty())
    {
        s.pop(str);
        cout << str;
    }
    cout << "<" << obase << ">" << endl;
}

void PalindromeNumber()
{
    cout << "A palindrome number reads the same backward as forward, such as 121 and 232. " << endl
         << "Of course, the property depends on the basis in which the number is represented." << endl
         << "For example,the number 75457 is a palindrome.The number 17 is not a palindrome in base 10, " << endl
         << "but its representation in base 2(10001)is a palindrome." << endl
         << "The objective of this program is to verify if a given number is palindrome in any base from 2 to 62. " << endl;
    cout << "Please input a number:";
    string number;
    while (cin >> number)
    {
        if (number == "888")
            break;
        cout << number << "'s palindrome number at base :";
        for (int i = 2; i <= 61; i++)
        {
            int temp;
            SqStack<char> translated = Numbertranslation(number, 10, i, temp);
            string strnum;
            char str;
            while (!translated.IsEmpty())
            {
                translated.pop(str);
                strnum += str;
            }
            if (IsPalindrome(strnum))
                cout << strnum << "<" << i << "> ";
        }
        cout << endl;
    }
}