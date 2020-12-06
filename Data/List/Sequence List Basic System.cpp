#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include "SqList.h"
using namespace std;
default_random_engine random(time(NULL));
void ShowMenu();
void ListSort(SqList<int> &);
void ShowList(SqList<int> &);
void CreateList(SqList<int> &);
void ReverseList(SqList<int> &);
void MaxPlatform(SqList<int> &);
void ExporttoFile(SqList<int> &);
void PartitionList(SqList<int> &);
void DeletebyValue(SqList<int> &);
void SearchByValue(SqList<int> &);
void ImportfromFile(SqList<int> &);
void DeleteDuplicate(SqList<int> &);
void DeletebyLocation(SqList<int> &);
void InsertByLocation(SqList<int> &);
void SearchByLocation(SqList<int> &);
void input(int *x, int start = 0, int end = 999);
int main()
{
    int choice;
    SqList<int> list(60);
    while (1)
    {
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 16 for choice:";
        input(&choice, 1, 16);
        if (choice == 16)
            break;
        switch (choice)
        {
        case 1:
            // 1-Create new SqList
            CreateList(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            // 2-Show SqList
            ShowList(list);
            cout << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            // 3 - Clear SqList
            list.Clear();
            cout << "The current sequence list has been cleared" << endl;
            cout << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            // 4 - Sort SqList
            cout << "Please choose the mode of sort (0 for descending, 1 for ascending):";
            ListSort(list);
            list.Show();
            cout << endl;
            cout << "Press any key to return Menu" << endl;
            getchar();
            getchar();

            break;
        case 5:
            // 5 -Search by Location
            SearchByLocation(list);
            cout << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 6:
            // 6 - Search by Value
            SearchByValue(list);
            cout << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 7:
            // 7 - Insert by Location
            InsertByLocation(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();

            break;
        case 8:
            // 8 - Delete by Location
            DeletebyLocation(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 9:
            // 9 - Delete by Value
            DeletebyValue(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();

            break;
        case 10:
            // 10 - Delete Duplicate
            DeleteDuplicate(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 11:
            // 11 - Reverse List
            ReverseList(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 12:
            // 12 - Partition SqList
            PartitionList(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 13:
            // 13 - Import from File
            ImportfromFile(list);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 14:
            // 14 - Export to File
            ExporttoFile(list);

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 15:
            // 15 - Max Platform
            MaxPlatform(list);
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
    cout << "*     1-Create new List       2-Show List              *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     3-Clear List            4-Sort List              *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     5-Search by Location    6-Search by Value        *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     7-Insert by Location    8-Delete by Location     *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     9-Delete by Value       10-Delete Duplicate      *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     11-Reverse List         12-Partition List        *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     13-Import from File     14-Export to File        *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     15-Max Platform         16-Exit                  *" << endl;
    cout << "*                                                      *" << endl;
    cout << "********************************************************" << endl;
}
void input(int *x, int start, int end)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << endl
             << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}
void ListSort(SqList<int> &list)
{
    int mode;
    // 创建临时变量，和记录最大值最小值的索引与值变量
    int temp1, temp2, MaxIndex, MaxNum, MinIndex, MinNum;
    // 选择排序的模式
    input(&mode, 0, 1);
    if (!list.IsEmpty())
        if (!mode)
        {
            // 选择排序
            for (int i = 0; i < list.Length() - 1; i++)
            {
                MaxIndex = i;
                for (int k = i + 1; k < list.Length(); k++)
                {
                    list.GetElem(temp1, k + 1);
                    list.GetElem(MaxNum, MaxIndex + 1);
                    if (temp1 > MaxNum)
                        MaxIndex = k;
                }

                if (MaxIndex != i)
                {
                    int temp1, temp2;
                    list.GetElem(temp1, MaxIndex + 1);
                    list.GetElem(temp2, i + 1);
                    list.SetElem(temp1, i + 1);
                    list.SetElem(temp2, MaxIndex + 1);
                }
            }
        }
        else
        {
            for (int i = 0; i < list.Length() - 1; i++)
            {
                MinIndex = i;
                for (int k = i + 1; k < list.Length(); k++)
                {
                    list.GetElem(temp1, k + 1);
                    list.GetElem(MinNum, MinIndex + 1);
                    if (temp1 < MinNum)
                        MinIndex = k;
                }

                if (MinIndex != i)
                {
                    int temp1, temp2;
                    list.GetElem(temp1, MinIndex + 1);
                    list.GetElem(temp2, i + 1);
                    list.SetElem(temp1, i + 1);
                    list.SetElem(temp2, MinIndex + 1);
                }
            }
        }
}

void CreateList(SqList<int> &list)
{
    // 设置5-150的随机数
    static uniform_int_distribution<int> nums(5, 150);
    if (list.IsEmpty())
    {
        for (int i = 0; i < 60; i++)
            list.Append(nums(random));
    }
    else
    {
        list.Clear();
        for (int i = 0; i < 60; i++)
            list.Append(nums(random));
    }
    cout << "The sequence list has been created and initiated by " << list.Length() << " random numbers" << endl;
    list.Show();
}

void ShowList(SqList<int> &list)
{
    if (!list.IsEmpty())
    {
        list.Show();
        cout << endl
             << "The lenght of sequence is " << list.Length() << endl;
    }
    else
        cout << "The sequence SqList is empty" << endl;
}
void SearchByLocation(SqList<int> &list)
{
    // 寻找指定索引的值
    int index;
    if (!list.IsEmpty())
    {
        cout << "Please a location to search(1 <= index < " << list.Length() << "):";
        input(&index, 0, list.Length());
        int result;
        list.GetElem(result, index);
        if (result != -1)
            cout << "The value of " << index << " in the sequence SqList is " << result << endl;
    }
    else
        cout << "The list is empty." << endl;
}
void SearchByValue(SqList<int> &list)
{
    // 寻找指定值的索引
    int value;
    if (!list.IsEmpty())
    {
        cout << "Please a value to search :";
        while (!(cin >> value))
        {
            // 确保获取的是整数
            cout << "InputError:please input again";
            cin.clear(); //恢复错误的状态
            cin.sync();  //清楚之前的输入数据
        }
        int result;
        result = list.LocateElem(value);
        if (result != -1)
        {
            cout << "The first location of " << value << " in the sequence SqList is " << result << "(start from 1)" << endl;
        }
        else
            cout << "The " << value << " is not in the sequence SqList." << endl;
    }
    else
        cout << "The list is empty." << endl;
}
void InsertByLocation(SqList<int> &list)
{
    int index, value;
    if (!list.IsEmpty())
    {
        cout << "Please input the location to insert:";
        input(&index, 1, list.Length());
        cout << "Please input the value to insert:";
        input(&value);
        list.Insert(value, index);
        cout << "Insert successfully" << endl;
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}

void DeletebyLocation(SqList<int> &list)
{
    int index;
    if (!list.IsEmpty())
    {
        int result;
        cout << "Please input the location to delete:";
        input(&index, 0, list.Length());
        list.Delete(result, index);
        cout << "Delete successfully,the deleted item is " << result << endl;
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}
void DeletebyValue(SqList<int> &list)
{
    int value;
    if (!list.IsEmpty())
    {
        cout << "Please input the value to delete:";
        input(&value);
        int temp;
        int count;
        // 先找到某个值在顺序表中的位置
        int locate = list.LocateElem(value);
        // 如果该值存在于表中，则返回的值不为-1，然后按照索引来删除所选元素
        while (locate != -1)
        {
            list.Delete(temp, locate);
            locate = list.LocateElem(value);
            count++;
        }
        cout << "Delete successfully, There is " << count << " \'" << value << "\'" << endl;
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}

void DeleteDuplicate(SqList<int> &list)
{
    if (!list.IsEmpty())
    {
        cout << "Please input any key to delete duplication:" << endl;
        getchar();
        int value, check, temp;
        for (int i = 1; i <= list.Length(); i++)
        {
            // 如果该索引值合法，找到的值存在value中
            if (list.GetElem(value, i))
                for (int j = i + 1; j <= list.Length(); j++)
                {
                    // 从找该值的索引开始到末尾查找是否存在于value一样的值，如果存在，将该索引的值删除
                    list.GetElem(check, j);
                    if (check == value)
                    {
                        list.Delete(temp, j);
                        // 删除一个值后需要将索引向前移动一位
                        j--;
                    }
                }
        }
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}
void ReverseList(SqList<int> &list)
{
    if (!list.IsEmpty())
    {
        cout << "The sequence before reversing is:" << endl;
        list.Show();
        cout << "Please input any key to delete duplication:";
        getchar();
        int temp1, temp2;
        // 从开始到列表的中心于其相对镜像的位置互换值
        for (int i = 1; i < list.Length() / 2; i++)
        {
            list.GetElem(temp1, i);
            list.GetElem(temp2, list.Length() - i + 1);
            list.SetElem(temp2, i);
            list.SetElem(temp1, list.Length() - i + 1);
        }
        cout << "The sequence after reversing is:" << endl;
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}

void PartitionList(SqList<int> &list)
{
    if (!list.IsEmpty())
    {
        int partiton;
        cout << "The sequence before partition is:" << endl;
        list.Show();
        cout << endl
             << "Please input a number as partition:";
        input(&partiton);
        getchar();
        int low = 1, high = list.Length();
        int Lvalue, Hvalue, temp1, temp2;
        // low，high初始值为头和尾，low从前往后找，high从后往前找
        // low表示第一个找到比分割线大的索引，high表示第一个找到比分割线小的值
        // 如果low在high的左边，两者的值交换，
        // 重复上面的循环，直到low>=high为止
        while (low < high)
        {
            list.GetElem(Lvalue, low);
            list.GetElem(Hvalue, high);
            while (Lvalue <= partiton)
            {
                low++;
                list.GetElem(Lvalue, low);
            }
            while (Hvalue > partiton)
            {
                high--;
                list.GetElem(Hvalue, high);
            }
            if (low < high)
            {
                list.GetElem(temp1, low);
                list.GetElem(temp2, high);
                list.SetElem(temp2, low);
                list.SetElem(temp1, high);
            }
        }
        cout << "The sequence after partition is:" << endl;
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}

void ImportfromFile(SqList<int> &list)
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
    if (!list.IsEmpty())
        list.Clear();

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
    // 如果
    while (!ImportFile.eof() && (ImportFile >> temp))
        list.Append(temp);
    ImportFile.close();
    cout << "Import successfully." << endl;
    cout << "The sequence is as follow:" << endl;
    list.Show();
}
void ExporttoFile(SqList<int> &list)
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
    if (!list.IsEmpty())
    {
        fstream outFile(Path, ios_base::out | ios_base::trunc);

        for (int i = 1; i < list.Length(); i++)
        {
            int temp;
            list.GetElem(temp, i);
            outFile << temp << "\t";
            if (!((i + 1) % 10))
                outFile << endl;
        }
        outFile.close();
        cout << "Export successfully." << endl;
        cout << "The sequence is as follow:" << endl;
        list.Show();
    }
    else
        cout << "The list is empty." << endl;
}
void MaxPlatform(SqList<int> &list)
{
    if (!list.IsEmpty())
    {
        int temp1, temp2, count = 1, max = 1, maxValue;
        for (int i = 1; i <= list.Length(); i++)
        {
            // 同时查找两个连续索引的值，如果两者相等，则计数++
            list.GetElem(temp1, i);
            list.GetElem(temp2, i + 1);
            if (temp1 == temp2)
                count++;
            else
            {
                // 记录最大值
                if (count > max)
                {
                    max = count;
                    maxValue = temp1;
                }
                count = 1;
            }
        }
        if (max != 1)
            cout << "The Max Platform is " << max << " The number is " << maxValue << endl;
        else
            cout << "The Max Platform is " << max << endl;
    }
    else
        cout << "The list is empty." << endl;
}