#include <iostream>
#include <random>
#include <ctime>
using namespace std;
void ShowMenu();
int Add();
void Addition();
int Subtract();
void Subtraction();
int Multiply();
void Multiplication();
int Divide();
void Division();
void Mixed();
int main()
{

    int choice;
    while (1)
    {
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 6 for choice:";
        while (!(cin >> choice) || (choice <= 0) || (choice > 8))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }

        if (choice == 6)
        {
            cout << "bye~" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            // cout << "addition" << endl;
            Addition();
            break;
        case 2:
            // cout << "Subtraction" << endl;
            Subtraction();
            break;
        case 3:
            // cout << "Multiplication" << endl;
            Multiplication();
            break;
        case 4:
            // cout << "Division" << endl;
            Division();
            break;
        case 5:
            // cout << "Mixed" << endl;
            Mixed();
            break;

        default:
            break;
        }
    }
}

void ShowMenu()
{
    cout << "*******************I love jlj********************" << endl;
    cout << endl;
    cout << "*******************Calculator********************" << endl;
    cout << "*                                               *" << endl;
    cout << "*     1-Addition<+>          2-Subtraction<->   *" << endl;
    cout << "*                                               *" << endl;
    cout << "*     3-Multiplication<*>    4-Division</>      *" << endl;
    cout << "*                                               *" << endl;
    cout << "*     5-Mixed                6-Exit             *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
}
// 加法
int Add()
{
    static default_random_engine random(time(NULL));
    static uniform_int_distribution<int> dis1(10, 30);
    static uniform_int_distribution<int> dis2(10, 30);
    int add1 = dis1(random);
    int add2 = dis2(random);
    int result = add1 + add2;
    cout << add1 << " + " << add2 << " = ";
    int UserResult;
    int Flag = 1;
    while (!(cin >> UserResult))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
        cout << endl;
        cout << add1 << " + " << add2 << " = ";
    }
    while (result != UserResult)
    {
        cout << "--warning,Try again" << endl;
        cout << add1 << " + " << add2 << " = ";
        cin >> UserResult;
        Flag = 0;
    }
    if (!Flag)
        cout << "You're right!" << endl;
    return Flag;
}
// 减法
int Subtract()
{
    static default_random_engine random(time(NULL));
    static uniform_int_distribution<int> dis1(10, 30);
    static uniform_int_distribution<int> dis2(10, 30);
    int Subtraction1 = dis1(random);
    int Subtraction2 = dis2(random);
    int result;
    int Flag = 1;
    if (Subtraction1 >= Subtraction2)
    {
        result = Subtraction1 - Subtraction2;
        cout << Subtraction1 << " - " << Subtraction2 << " = ";
    }
    else
    {
        result = Subtraction2 - Subtraction1;
        cout << Subtraction2 << " - " << Subtraction1 << " = ";
    }
    int UserResult;
    while (!(cin >> UserResult))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
        cout << endl;
        if (Subtraction1 >= Subtraction2)
        {
            result = Subtraction1 - Subtraction2;
            cout << Subtraction1 << " - " << Subtraction2 << " = ";
        }
        else
        {
            result = Subtraction2 - Subtraction1;
            cout << Subtraction2 << " - " << Subtraction1 << " = ";
        }
    }
    while (result != UserResult)
    {
        cout << "--warning,Try again" << endl;
        if (Subtraction1 >= Subtraction2)
        {
            result = Subtraction1 - Subtraction2;
            cout << Subtraction1 << " - " << Subtraction2 << " = ";
        }
        else
        {
            result = Subtraction2 - Subtraction1;
            cout << Subtraction2 << " - " << Subtraction1 << " = ";
        }
        cin >> UserResult;
        Flag = 0;
    }
    if (Flag == 0)
        cout << "You're rihgt!" << endl;
    return Flag;
}

int Multiply()
{
    static default_random_engine random(time(NULL));
    static uniform_int_distribution<int> dis1(2, 10);
    static uniform_int_distribution<int> dis2(2, 10);
    int Multiplication1 = dis1(random);
    int Multiplication2 = dis2(random);
    int Flag = 1;
    int result = Multiplication1 * Multiplication2;
    cout << Multiplication1 << " * " << Multiplication2 << " = ";
    int UserResult;
    while (!(cin >> UserResult))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
        cout << endl;
        cout << Multiplication1 << " * " << Multiplication2 << " = ";
    }
    while (result != UserResult)
    {
        cout << "--warning,Try again" << endl;
        cout << Multiplication1 << " * " << Multiplication2 << " = ";
        cin >> UserResult;
        Flag = 0;
    }
    if (Flag == 0)
        cout << "You're rihgt!" << endl;
    return Flag;
}
// 除法
int Divide()
{
    static default_random_engine random(time(NULL));
    static uniform_int_distribution<int> dis1(2, 10);
    static uniform_int_distribution<int> dis2(2, 10);
    int Division1 = dis1(random);
    int Division2 = dis2(random);
    int result = Division1 * Division2;
    int Flag = 1;
    cout << result << " / " << Division2 << " = ";
    int UserResult;
    while (!(cin >> UserResult))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
        cout << endl;
        cout << result << " / " << Division2 << " = ";
    }
    while (Division1 != UserResult)
    {
        cout << "--warning,Try again" << endl;
        cout << result << " / " << Division2 << " = ";
        cin >> UserResult;
        Flag = 0;
    }
    if (Flag == 0)
        cout << "You're rihgt!" << endl;
    return Flag;
}
void Addition()
{
    while (1)
    {
        int count;
        cout << "------Notice:Input 888 to end the practice-----" << endl;
        cout << "Set the count of tests(1-100):";

        while (!(cin >> count) || (count < 0) || (count > 100))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (count == 888)
        {
            cout << "Bye~" << endl;
            break;
        }
        // 奖励计数
        int n = 0;
        int WarningCnt = 0;
        for (int i = 0; i < count; i++)
        {
            int Flag = Add();
            if (!Flag)
            {
                WarningCnt++;
                n = 0;
            }
            else
            {
                n++;
                if (n == 1)
                    cout << "--Right." << endl;
                else if (n == 2)
                    cout << "--Good Job." << endl;
                else if (n == 3)
                    cout << "--Excellent!" << endl;
                else if (n == 4)
                    cout << "--Amazing!!!" << endl;
                else if (n >= 5)
                    cout << "--Prefect!!!!!" << endl;
            }
        }
        cout << " Right: " << count - WarningCnt << " Waring: " << WarningCnt << " Accuracy: ";
        printf("%.2f%%\n", (count - WarningCnt) * 1.0 / count * 100);
    }
}

void Subtraction()
{
    while (1)
    {
        int count;
        cout << "------Notice:Input 888 to end the practice-----" << endl;
        cout << "Set the count of tests:";

        while (!(cin >> count) || (count < 0))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (count == 888)
        {
            cout << "Bye~" << endl;
            break;
        }
        // 奖励计数
        int n = 0;
        int WarningCnt = 0;
        for (int i = 0; i < count; i++)
        {
            int Flag = Subtract();
            if (!Flag)
            {
                WarningCnt++;
                n = 0;
            }
            else
            {
                n++;
                if (n == 1)
                    cout << "--Right." << endl;
                else if (n == 2)
                    cout << "--Good Job." << endl;
                else if (n == 3)
                    cout << "--Excellent!" << endl;
                else if (n == 4)
                    cout << "--Amazing!!!" << endl;
                else if (n >= 5)
                    cout << "--Prefect!!!!!" << endl;
            }
        }
        cout << " Right: " << count - WarningCnt << " Waring: " << WarningCnt << " Accuracy: ";
        printf("%.2f%%\n", (count - WarningCnt) * 1.0 / count * 100);
    }
}

void Multiplication()
{
    while (1)
    {
        int count;
        cout << "------Notice:Input 888 to end the practice-----" << endl;
        cout << "Set the count of tests:";

        while (!(cin >> count) || (count < 0))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (count == 888)
        {
            cout << "Bye~" << endl;
            break;
        }
        // 奖励计数
        int n = 0;
        int WarningCnt = 0;
        for (int i = 0; i < count; i++)
        {
            int Flag = Multiply();
            if (!Flag)
            {
                WarningCnt++;
                n = 0;
            }
            else
            {
                n++;
                if (n == 1)
                    cout << "--Right." << endl;
                else if (n == 2)
                    cout << "--Good Job." << endl;
                else if (n == 3)
                    cout << "--Excellent!" << endl;
                else if (n == 4)
                    cout << "--Amazing!!!" << endl;
                else if (n >= 5)
                    cout << "--Prefect!!!!!" << endl;
            }
        }
        cout << " Right: " << count - WarningCnt << " Waring: " << WarningCnt << " Accuracy: ";
        printf("%.2f%%\n", (count - WarningCnt) * 1.0 / count * 100);
    }
}
void Division()
{
    while (1)
    {
        int count;
        cout << "------Notice:Input 888 to end the practice-----" << endl;
        cout << "Set the count of tests:";

        while (!(cin >> count) || (count < 0))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (count == 888)
        {
            cout << "Bye~" << endl;
            break;
        }
        // 奖励计数
        int n = 0;
        int WarningCnt = 0;
        for (int i = 0; i < count; i++)
        {
            int Flag = Divide();
            if (!Flag)
            {
                WarningCnt++;
                n = 0;
            }
            else
            {
                n++;
                if (n == 1)
                    cout << "--Right." << endl;
                else if (n == 2)
                    cout << "--Good Job." << endl;
                else if (n == 3)
                    cout << "--Excellent!" << endl;
                else if (n == 4)
                    cout << "--Amazing!!!" << endl;
                else if (n >= 5)
                    cout << "--Prefect!!!!!" << endl;
            }
        }
        cout << " Right: " << count - WarningCnt << " Waring: " << WarningCnt << " Accuracy: ";
        printf("%.2f%%\n", (count - WarningCnt) * 1.0 / count * 100);
    }
}

void Mixed()
{
    default_random_engine random(time(NULL));
    uniform_int_distribution<int> dis(10, 49);
    while (1)
    {
        int count;
        cout << "------Notice:Input 888 to end the practice-----" << endl;
        cout << "Set the count of tests:";

        while (!(cin >> count) || (count < 0))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        if (count == 888)
        {
            cout << "Bye~" << endl;
            break;
        }
        // 奖励计数
        int n = 0;
        int WarningCnt = 0;
        for (int i = 0; i < count; i++)
        {
            int Flag;
            int Mode = dis(random);
            switch (Mode / 10)
            {
            case 1:
                Flag = Add();
                break;
            case 2:
                Flag = Subtract();
                break;
            case 3:
                Flag = Multiply();
                break;
            case 4:
                Flag = Divide();
                break;
            }
            if (!Flag)
            {
                WarningCnt++;
                n = 0;
            }
            else
            {
                n++;
                if (n == 1)
                    cout << "--Right." << endl;
                else if (n == 2)
                    cout << "--Good Job." << endl;
                else if (n == 3)
                    cout << "--Excellent!" << endl;
                else if (n == 4)
                    cout << "--Amazing!!!" << endl;
                else if (n >= 5)
                    cout << "--Prefect!!!!!" << endl;
            }
        }
        cout << " Right: " << count - WarningCnt << " Waring: " << WarningCnt << " Accuracy: ";
        printf("%.2f%%\n", (count - WarningCnt) * 1.0 / count * 100);
    }
}
