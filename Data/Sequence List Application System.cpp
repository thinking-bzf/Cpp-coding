#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <cstring>
#include "SqList.h"
using namespace std;
default_random_engine random(time(NULL));
void input(int *x, int start = 0, int end = 999);
void ShowMenu();
void Intersections(SqList<int> &, SqList<int> &);
void Subtraction(SqList<int> &, SqList<int> &);
void UnionofTwoLists(SqList<int> &, SqList<int> &);
void Merge(SqList<int> &, SqList<int> &);
void SubsetAndComplement(SqList<int> &, SqList<int> &);
void SumOfX(SqList<int> &);
void OrderListInsert(SqList<int> &);
void IntervalDelete(SqList<int> &list1);
void JosephusProblem(SqList<int> &);
int main()
{
    int choice;
    SqList<int> list1(50);
    SqList<int> list2(50);
    SqList<int> list3;
    static uniform_int_distribution<int> nums(5, 150);
    for (int i = 0; i < 50; i++)
        list1.Append(nums(random));
    for (int i = 0; i < 50; i++)
        list2.Append(nums(random));
    while (1)
    {
        ShowMenu();
        cout << endl
             << "Please input a integer from 1 to 10 for choice:";
        input(&choice, 1, 10);
        if (choice == 10)
            break;

        switch (choice)
        {
        case 1:
            // 两个集合交集
            Intersections(list1, list2);
            list3.Clear();
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            // 差集
            Subtraction(list1, list2);
            list3.Clear();
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            UnionofTwoLists(list1, list2);
            list3.Clear();
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            Merge(list1, list2);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 5:
            SubsetAndComplement(list1, list2);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 6:
            SumOfX(list1);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            // 有序表中插入元素
            OrderListInsert(list1);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 8:
            IntervalDelete(list1);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            JosephusProblem(list3);
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
    cout << "*******************I Love JLJ************************" << endl;
    cout << endl;
    cout << "***************Sequence List Basic System************" << endl;
    cout << "*                                                   *" << endl;
    cout << "*     1-Intersections         2-Subtraction         *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*     3-Union of Two Lists    4-Merge Two Lists     *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*     5-Subset & Complement   6-Sum of x            *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*     7-Order List Insert     8-Interval Delete     *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*     9-Josephus Problem      10-Exit               *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*****************************************************" << endl;
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
void DeleteDuplicate(SqList<int> &list)
{
    if (!list.IsEmpty())
    {
        int value, check, temp;
        for (int i = 1; i <= list.Length(); i++)
        {
            if (list.GetElem(value, i))
                for (int j = i + 1; j <= list.Length(); j++)
                {
                    list.GetElem(check, j);
                    if (check == value)
                    {
                        list.Delete(temp, j);
                        j--;
                    }
                }
        }
    }
}
void Intersections(SqList<int> &list1, SqList<int> &list2)
{
    cout << "The first sequence list is:" << endl;
    list1.Show();
    cout << endl;
    cout << "The second sequence list is:" << endl;
    list2.Show();
    cout << endl;
    // 列表去重变集合
    DeleteDuplicate(list1);
    DeleteDuplicate(list2);
    int value;
    SqList<int> list3;
    for (int i = 1; i <= list1.Length(); i++)
    {
        // 先找第一个集合的值，如果在第二个集合中存在，添加到目标集合中
        list1.GetElem(value, i);
        if (list2.LocateElem(value) != -1)
            list3.Append(value);
    }
    cout << "The Intersection sequence list is:" << endl;
    list3.Show();
}
void Subtraction(SqList<int> &list1, SqList<int> &list2)
{

    cout << "The first sequence list is:" << endl;
    list1.Show();
    cout << endl;
    cout << "The second sequence list is:" << endl;
    list2.Show();
    cout << endl;
    DeleteDuplicate(list1);
    DeleteDuplicate(list2);
    // 先把集合1复制给目标集合
    SqList<int> list3(list1);
    int value;
    for (int i = 1; i <= list1.Length(); i++)
    {
        // 寻找第一个集合中的元素是否在第二个集合中，如果存在，删除目标集合中该元素
        list1.GetElem(value, i);
        int index;
        do
        {
            index = list2.LocateElem(value);
            list3.Delete(value, index);
        } while (index != -1);
    }
    cout << "The different set of sequence list is:" << endl;
    list3.Show();
}
void UnionofTwoLists(SqList<int> &list1, SqList<int> &list2)
{
    cout << "The first sequence list is:" << endl;
    list1.Show();
    cout << endl;
    cout << "The second sequence list is:" << endl;
    list2.Show();
    cout << endl;
    DeleteDuplicate(list1);
    DeleteDuplicate(list2);
    SqList<int> list3(list1);
    int value;
    // 将所有的元素都添加到目标集合中，并且删除目标集合中的重复值
    for (int i = 1; i <= list2.Length(); i++)
    {
        list1.GetElem(value, i);
        list3.Append(value);
    }
    DeleteDuplicate(list3);
    cout << "The union sequence list is:" << endl;
    list3.Show();
}
void SortList(SqList<int> &list)
{
    int temp1, temp2, MinIndex, MinNum;
    for (int i = 1; i <= list.Length(); i++)
    {
        MinIndex = i;
        for (int k = i + 1; k <= list.Length(); k++)
        {
            list.GetElem(temp1, k);
            list.GetElem(MinNum, MinIndex);
            if (temp1 < MinNum)
                MinIndex = k;
        }

        if (MinIndex != i)
        {
            int temp1, temp2;
            list.GetElem(temp1, MinIndex);
            list.GetElem(temp2, i);
            list.SetElem(temp1, i);
            list.SetElem(temp2, MinIndex);
        }
    }
}
void Merge(SqList<int> &list1, SqList<int> &list2)
{
    
    SortList(list1);
    SortList(list2);
    cout << "The first ascending sequence list is:" << endl;
    list1.Show();
    cout << endl;
    cout << "The second ascending sequence list is:" << endl;
    list2.Show();
    cout << endl;
    int first = 1, second = 1;
    int Fvalue, Svalue;
    SqList<int> list3;
    // 先将列表排序，然后根据值的大小依次插入，first和second分别记录列表1和列表2的所在索引
    while (first <= list1.Length() && second <= list2.Length())
    {
        list1.GetElem(Fvalue, first);
        list2.GetElem(Svalue, second);

        if (Fvalue >= Svalue)
        {
            list3.Append(Svalue);
            second++;
        }
        else
        {
            list3.Append(Fvalue);
            first++;
        }
    }
    int temp;
    // 如果某个列表还没遍历完成，则依次添加进去
    if (first == list1.Length() - 1)
        while (second <= list2.Length())
        {
            list2.GetElem(temp, second);
            list3.Append(temp);
            second++;
        }

    else if (second == list2.Length() - 1)
        while (first <= list1.Length())
        {
            list1.GetElem(temp, first);
            list3.Append(temp);
            first++;
        }
    cout << "The merge ascending sequence list is:" << endl;
    list3.Show();
}
void ImportFromFile(SqList<int> &list, string Path)
{
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
    if (!list.IsEmpty())
        list.Clear();
    int temp;
    while (!ImportFile.eof() && (ImportFile >> temp))
        list.Append(temp);
    ImportFile.close();
}
void SubsetAndComplement(SqList<int> &list1, SqList<int> &list2)
{
    // 由于随机数计算是否是子集有点困难，所以使用文件导入的自定义方式
    cout << "The first sequence list is:" << endl;
    // 分别导入两个列表并去重
    ImportFromFile(list1, "Data/Subset1.txt");
    DeleteDuplicate(list1);
    list1.Show();
    cout << endl
         << "The second sequence list is:" << endl;
    ImportFromFile(list2, "Data/Subset2.txt");
    DeleteDuplicate(list2);
    list2.Show();
    SqList<int> list3(list1);
    // list3 = list1;
    int SubsetFlag = 1;
    int value;
    for (int i = 1; i <= list2.Length(); i++)
    {
        // 依次遍历第一个列表，判断该元素是否在另一个列表中，并用flag记录，如果不在直接跳出循环
        list2.GetElem(value, i);
        if (list3.LocateElem(value) == -1)
        {
            SubsetFlag = 0;
            break;
        }
        else
        {
            int temp = list3.LocateElem(value);
            while (temp != -1)
            {
                list3.Delete(value, temp);
                temp = list3.LocateElem(value);
            }
        }
    }
    if (SubsetFlag == 0)
        cout << endl
             << "The second sequence is not the subset of the first sequence." << endl;
    else
    {
        cout << endl
             << "The second sequence is the subset of the first sequence." << endl;
        cout << "The supplementtary list is:" << endl;
        list3.Show();
    }
}

void SumOfX(SqList<int> &list1)
{
    int sum;
    cout << "Find two Nunbers inthe list : x plus y that are exactly equal to A." << endl;
    list1.Show();
    cout << "Please input a numbers as sum:\n";
    input(&sum);
    int count = 0;
    int x, temp1, temp2;
    for (int i = 1; i <= list1.Length(); i++)
    {
        // 查找sum-x是否在列表中即可
        list1.GetElem(x, i);
        if (list1.LocateElem(sum - x) != -1)
        {
            cout << "There is : " << x << " +" << sum - x << " = " << sum << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "There is no example for sum." << endl;
}

void OrderListInsert(SqList<int> &list1)
{
    int insertion;
    SortList(list1);
    cout << "The sorted list before insertion:" << endl;
    list1.Show();
    cout << endl
         << "Please input a number to insert:";
    input(&insertion);
    int temp;
    for (int i = 1; i <= list1.Length(); i++)
    {
        // 找到第一个符合插入条件的值
        list1.GetElem(temp, i);
        if (insertion < temp)
        {
            list1.Insert(insertion, i);
            break;
        }
    }
    cout << "The sorted list after insertion:" << endl;
    list1.Show();
}

void IntervalDelete(SqList<int> &list1)
{
    int low, high;
    // 先将列表排序
    SortList(list1);
    cout << "The sorted list before Delete:" << endl;
    list1.Show();
    cout << endl
         << "Please input the lower bound of the interval:";
    input(&low);
    cout << "Please input the upper bound of the interval:";
    input(&high);
    int lowIndex = 1;
    int highIndex = list1.Length();
    int lowvalue, highvalue;
    list1.GetElem(lowvalue, lowIndex);
    list1.GetElem(highvalue, highIndex);
    while (lowvalue < low)
    {
        lowIndex++;
        list1.GetElem(lowvalue, lowIndex);
    }
    while (highvalue > high)
    {
        highIndex--;
        list1.GetElem(highvalue, highIndex);
    }
    int temp;
    for (int i = lowIndex, j = highIndex - lowIndex + 1; j > 0; j--)
        list1.Delete(temp, i);
    if (list1.IsEmpty())
        cout << "The list is empty." << endl;
    else
    {
        cout << "The sorted list after Delete:" << endl;
        list1.Show();
    }
}

void JosephusProblem(SqList<int> &list)
{
    cout << "There are n people" << endl;
    cout << "standing in a circle waiting to be executed." << endl;

    cout << "The counting out begins at some point in the circle and " << endl
         << "proceeds around thecircle in a fixed direction. In each step," << endl
         << "a certain nunber of peoplea reskipped and the nextperson is executed." << endl
         << "The elimination proceeds aroundthe circle <which is becoming smaller " << endl
         << "and smaller as the executed people are removed>, until only the last " << endl
         << "person remains, who is given freedom." << endl
         << endl
         << "Given the total number of persons n and a nunber k which indicates that k-1 " << endl
         << "persons are skipped and kth person is killed in circle.The task is to " << endl
         << "choose the place in the initial circle so that you are the last " << endl
         << "one remaining and so survive." << endl;
    static uniform_int_distribution<int> nums(5, 150);
    int total, reporting, start;
    cout << "Please input the total number of Monkeys:";
    input(&total);
    for (int i = 0; i < total; i++)
        list.Append(nums(random));
    DeleteDuplicate(list);
    cout << "Please input the reporting value:";
    input(&reporting);
    cout << "Please input the position to start counting:";
    input(&start);
    list.Show();
    // 使用%取余实现循环
    start = (start - 1) % list.Length();
    int temp;
    while (list.Length() > 1)
    {
        // 如果列表的长度>1 ,则一直循环
        int i = 1;
        while (i < reporting)
        {
            // 如果报的数比预设值小，则已知累加，并取余，实现围成圈的功能
            start = (start + 1) % list.Length();
            i++;
        }
        // 找到后将该索引的值删除
        list.Delete(temp, start);
    }
    int winner;
    list.GetElem(winner, 1);
    cout << "The winner is No." << winner;
}