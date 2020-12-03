#include <iostream>
using namespace std;
void input(int *x, int start, int end);
void ShowMenu();
int main()
{
    int choice;
    
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

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
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
    cout << "*******************I Love JLJ***************************" << endl;
    cout << endl;
    cout << "***************Sequence List Basic System***************" << endl;
    cout << "*                                                      *" << endl;
    cout << "*                                                      *" << endl;
    cout << "********************************************************" << endl;
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
