#include <iostream>
#include <math.h>
using namespace std;

void ShowMenu();
void Goldbach();
void Collatz();
void NicoChester();
void FourSquare();
void Eratosthenes();
void BrideGroom();
void TruthorLie();
int IsPrime(int x);
int main()
{
    int choice;
    while (1)
    {
        ShowMenu();

        cout << "\nPlease input a integer from 1 to 7 for choice,8 for exiting:";
        while (!(cin >> choice) || (choice <= 0) || (choice > 8))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }

        switch (choice)
        {
        case 1:
            Goldbach();
            break;
        case 2:
            // cout << "You select 2..." << endl;
            Collatz();
            break;
        case 3:
            // cout << "You select 2..." << endl;
            NicoChester();
            break;
        case 4:
            // cout << "You select 2..." << endl;
            FourSquare();
            break;
        case 5:
            // cout << "You select 2..." << endl;
            Eratosthenes();
            break;
        case 6:
            // cout << "You select 2..." << endl;
            BrideGroom();
            break;
        case 7:
            // cout << "You select 2..." << endl;
            TruthorLie();
            break;
        case 8:
            cout << "bye~" << endl;
            break;

        default:
            cout << "valid input" << endl;
            break;
        }

        if (choice == 8)
            break;
    }
    return 0;
}

//
void ShowMenu()
{
    cout << "***************I love jlj*************" << endl;
    cout << endl;
    cout << "**************************************" << endl;
    cout << "*                                    *" << endl;
    cout << "*         1.Goldbach's Conjecture    *" << endl;
    cout << "*         2.CollatzConjecture        *" << endl;
    cout << "*         3.Nico Chester Theorem     *" << endl;
    cout << "*         4.Four Square Theorem      *" << endl;
    cout << "*         5.Sieve of Eratosthenes    *" << endl;
    cout << "*         6.Bride & Groom            *" << endl;
    cout << "*         7.Truth or Lie             *" << endl;
    cout << "*                                    *" << endl;
    cout << "*         8.exit                     *" << endl;
    cout << "*                                    *" << endl;
    cout << "**************************************" << endl;
}
int IsPrime(int x)
{
    int flag = 1;
    if (x == 2)
        return 1;
    if (x % 2 == 0)
        return 0;
    for (int i = 2; i <= sqrt(x); i += 2)
        if (!(x % i))
        {
            flag = 0;
            break;
        }
    return flag;
}
// Goldbach's Conjecture(哥德巴赫猜想)
void Goldbach()
{
    int n;

    while (1)
    {
        cout << "For any even number N greater than or equal to 4, " << endl
             << "there exists at least one pair of prime numbers p1 and p2 such that N = p1 + p2.";
        cout << "Notice:Input 8888 to exit." << endl;
        cout << "Please input a even:";
        while (!(cin >> n) || (n < 4) || (n % 2 != 0))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (n == 8888)
        {
            cout << "bye~" << endl;
            break;
        }
        cout << ".....Begin to solve the Goldbach conjecture....." << endl;
        int count = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            if (IsPrime(i))
            {
                if (IsPrime(n - i))
                {
                    cout << n << " = " << i << " + " << n - i << endl;
                    count++;
                }
            }
        }
        if (count == 1)
            cout << "There are" << count << "posibility" << endl;
        else
            cout << "There are" << count << "posibilities" << endl;
    }
}
// CollatzConjecture(考拉兹猜想)
void Collatz()
{
    int n;

    while (1)
    {
        cout << "Take any positive number: if it's even you divide it by 2 and if it's odd multiply it by 3 and add 1. " << endl
             << "Repeat this process indefinitely, no matter what number you start with, you will always end up at 1. " << endl
             << "The conjecture remains stubbornly unproven. Mathematics is not yet ready for such problems." << endl;
        cout << "Notice:Input 8888 to exit." << endl;
        cout << "Please input a integer:";
        while (!(cin >> n) || (n <= 1))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (n == 8888)
        {
            cout << "bye~" << endl;
            break;
        }

        cout << ".....Begin to solve the Collatz conjecture....." << endl;
        int step = 0;
        cout << n << " -> ";
        while (n != 1)
        {
            if (n % 2)
                n = 3 * n + 1;
            else
                n /= 2;
            cout << n << " -> ";
            step++;
        }
        if (step == 1)
            cout << "It needs " << step << "step" << endl;
        else
            cout << "It needs " << step << "steps" << endl;
    }
}

// Nico Chester Theorem(尼彻斯特定理)
void NicoChester()
{
    int n;
    while (1)
    {
        cout << "Any integer to the third power can be represented as the sum of a series of consecutive odd Numbers." << endl;
        cout << "Notice:Input 8888 to exit." << endl;
        cout << "Please input a integer:";
        while (!(cin >> n) || (n <= 1))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (n == 8888)
        {
            cout << "bye~" << endl;
            break;
        }

        for (int i = 2; i <= n * n; i++)
        {

            int start = (n * n * n - i * (i - 1)) / i;
            if (start % 2 && start > 0)
            {
                cout << n * n * n << " = ";
                for (int j = 0; j < i; j++)
                {
                    if (j != i - 1)
                        cout << start + 2 * j << " + ";
                    else
                        cout << start + 2 * j;
                }
                cout << endl;
            }
        }
    }
}
// Four Square Theorem(四平方数和定理)
void FourSquare()
{
    int n;
    while (1)
    {
        cout << "Four-square Theorem: Each positive integer may be expressed as the sum of the squares of four integers." << endl;
        cout << "Notice:Input 8888 to exit." << endl;
        cout << "Please input a integer:";
        while (!(cin >> n) || (n <= 1))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (n == 8888)
        {
            cout << "bye~" << endl;
            break;
        }
        for (int i = 0; i * i <= n; i++)
        {
            for (int j = i; i * i + j * j <= n; j++)
            {
                for (int k = j; i * i + j * j + k * k <= n; k++)
                {
                    int x = int(sqrt(n - i * i - j * j - k * k));
                    if ((x * x + i * i + j * j + k * k) == n && (x >= k))
                    {
                        cout << n << "=" << i << "*" << i << "+" << j << "*" << j << "+" << k << "*" << k << "+" << x << "*" << x << endl;
                    }
                }
            }
        }
    }
}
// Sieve of Eratosthenes(埃拉托斯特尼筛选法找质数)
void Eratosthenes()
{
    int n;
    while (1)
    {

        cout << "Began with 1, input a integer as end :";
        while (!(cin >> n) || (n <= 1))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (n == 8888)
        {
            cout << "bye~" << endl;
            break;
        }
        int IntField[n + 1] = {0};
        int x = sqrt(n);
        int cnt = n;
        IntField[1] = 1;
        for (int i = 2; i <= x; i++)
        {
            if (IntField[i] == 1)
                continue;
            else
                for (int j = 2; j * i <= n; j++)
                {
                    cnt--;
                    IntField[j * i] = 1;
                }
        }
        cout << "There is " << cnt << " prime number between " << 1 << n << endl;
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (IntField[i] == 0)
            {
                cout << i << "\t";
                count = (count + 1) % 10;
                if (!count)
                    cout << endl;
            }
        }
        cout << endl;
    }
}

void BrideGroom()
{
    cout << "There are 3 brides (A, B, C) and 3 grooms (X, Y, Z)." << endl
         << "A: I will marry X." << endl
         << "X: My fiance is C." << endl
         << "C: I will marry Z." << endl
         << "It is known that they are all kidding." << endl
         << "Then, do you know who and who are a couple?"
         << endl
         << "Press any key to show the anwser" << endl;
    getchar();
    getchar();
    int A = 1,
        B = 2, C = 3;
    int X, Y, Z;
    int couple[3];
    char Bride[4] = "ABC";
    char Groom[4] = "XYZ";
    // 三个新娘全排列枚举判断
    for (X = 1; X <= 3; X++)
        for (Y = 1; Y <= 3; Y++)
            for (Z = 1; Z <= 3; Z++)
            {
                if (A != X && X != C && C != Z && X != Z && X != Y && Y != Z)
                {
                    // 将得到的结果放在couple数组指定新娘的新郎
                    couple[0] = X;
                    couple[1] = Y;
                    couple[2] = Z;
                }
            }
    // 输出新郎和新娘
    for (int i = 0; i < 3; i++)
        cout << "The groom: " << Groom[i] << " 's brode is " << Bride[couple[i] - 1] << endl;
}

void TruthorLie()
{
    cout << "Ben says that Bob is lying." << endl
         << "Bob says that Bill is lying." << endl
         << "Bill says that they are all lying." << endl
         << "Then, do you know who is lying?" << endl
         << endl
         << "Press any key to show the anwser" << endl;
    getchar();
    getchar();
    int A, B, C;
    for (A = 0; A < 2; A++)
        for (B = 0; B < 2; B++)
            for (C = 0; C < 2; C++)
            {
                if (((A && !B) || (!A && B)) && ((B && !C) || (!B && C)) && ((C && (!A && !B)) || (!C && (A + B))))
                {
                    if (A)
                        cout << "Ben is true" << endl;
                    else
                        cout << "Ben is lying" << endl;
                    if (B)
                        cout << "Bob is true" << endl;
                    else
                        cout << "Bob is lying" << endl;
                    if (C)
                        cout << "Bill is true" << endl;
                    else
                        cout << "Bill is lying" << endl;
                }
            }
}
