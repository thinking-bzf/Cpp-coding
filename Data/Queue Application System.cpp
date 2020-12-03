#include <iostream>
#include "SqQueue.h"
#include <cstring>
#include <string>
#include <map>
#include <fstream>
using namespace std;
// 记录进制中每个字符代表的数值
map<char, int> Map1;
map<int, char> Map2;

void input(int *x, int start, int end);
void ShowMenu();
void CreateQueue(SqQueue<int> &);
void Enqueue(SqQueue<int> &);
void Dequeue(SqQueue<int> &);
void ImportfromFile(SqQueue<int> &);
void ExporttoFile(SqQueue<int> &);
void TrainProblem();
void GameProgram();
void ParternProblem();
int main()
{
    int choice;
    SqQueue<int> Queue(60);
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
            CreateQueue(Queue);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            
            break;
        case 2:
            if (!Queue.IsEmpty())
            {
                cout << "The length of stack is " << Queue.Length() << endl;
                Queue.Show();
            }
            else
                cout << "The stack is empty.";
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            Enqueue(Queue);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            Dequeue(Queue);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            if (Queue.IsEmpty())
                cout << "The Queue is empty." << endl;
            else
            {
                Queue.Clear();
                cout << "The Queue is cleared successfully." << endl;
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            if (Queue.IsEmpty())
                cout << "The Queue is empty." << endl;
            else
            {
                cout << "The head of Queue is " << Queue.GetHead() << endl;
            }

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            // 从文件导入
            if (Queue.IsEmpty())
                ImportfromFile(Queue);
            else
            {
                Queue.Clear();
                ImportfromFile(Queue);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            // 导出文件
            if (Queue.IsEmpty())
                // ImportfromFile(Queue);
                cout << "The Queue is empty." << endl;
            else
            {

                ExporttoFile(Queue);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            // PalindromeNumber();
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
    cout << "*******************I Love JLJ*******************" << endl;
    cout << endl;
    cout << "*************Queue Application System***********" << endl;
    cout << "*                                              *" << endl;
    cout << "*     1. Create Queue      2. Show Queue       *" << endl;
    cout << "*                                              *" << endl;
    cout << "*     3. EnQueue           4. DeQueue          *" << endl;
    cout << "*                                              *" << endl;
    cout << "*     5. Clear Queue       6. Get Head         *" << endl;
    cout << "*                                              *" << endl;
    cout << "*     7. Import from File  8. Export to File   *" << endl;
    cout << "*                                              *" << endl;
    cout << "*     9. Partern Problem   10. Game Program    *" << endl;
    cout << "*                                              *" << endl;
    cout << "*     11. Train Problem    12. Exit            *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
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

void CreateQueue(SqQueue<int> &Qu)
{
    if (Qu.IsEmpty())
        for (int i = 1; i <= 60; i++)
            Qu.Append(i);
    else
    {
        Qu.Clear();
        for (int i = 1; i <= 60; i++)
            Qu.Append(i);
    }
    cout << "Create sucessfully." << endl;
    Qu.Show();
}

void Enqueue(SqQueue<int> &Qu)
{
    int temp;
    cout << "Please input a number to Append:";
    input(&temp, 1, 2333);
    Qu.Append(temp);
    cout << "Push successfully." << endl;
    Qu.Show();
}

void Dequeue(SqQueue<int> &Qu)
{
    if (Qu.IsEmpty())
        cout << "The Queue is empty" << endl;
    else
    {
        int temp;
        temp = Qu.GetHead();
        Qu.Remove();
        cout << "Remove data " << temp << " successfully. The current Queue is:" << endl;
        Qu.Show();
    }
}

void ImportfromFile(SqQueue<int> &Qu)
{
    string Path;
    cout << "Please input the path of file:";
    while (!(cin >> Path))
    {
        // 确保获取的是字符串
        cout << endl
             << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }

    fstream ImportFile(Path);
    while (!ImportFile)
    {
        cout << "FileExitError :dictionary or file is not exit: " << Path << endl;
        cout << "Please input a valid file name:";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
        cin >> Path;
        ImportFile.open(Path);
    }
    int temp;
    while (!ImportFile.eof() && (ImportFile >> temp))
        Qu.Append(temp);
    ImportFile.close();
    cout << "Import successfully." << endl;
    cout << "The sequence is as follow:" << endl;
    Qu.Show();
}

void ExporttoFile(SqQueue<int> &Qu)
{
    string Path;
    cout << "Please input the path of file:";
    while (!(cin >> Path))
    {
        // 确保获取的是字符串
        cout << endl
             << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
    if (!Qu.IsEmpty())
    {
        fstream outFile(Path, ios_base::out | ios_base::trunc);
        int i = 0;
        while (!Qu.IsEmpty())
        {
            int temp;
            // list.GetElem(temp, i);
            temp = Qu.GetHead();
            Qu.Remove();
            outFile << temp << "\t";
            if (!((i + 1) % 10))
                outFile << endl;
            i++;
        }
        outFile.close();
        cout << "Export successfully." << endl;
        cout << "The Queue is as follow:" << endl;
        fstream ImportFile(Path);
        int temp;
        while (!ImportFile.eof() && (ImportFile >> temp))
            Qu.Append(temp);
        ImportFile.close();
        Qu.Show();
    }
    else
        cout << "The list is empty." << endl;
}