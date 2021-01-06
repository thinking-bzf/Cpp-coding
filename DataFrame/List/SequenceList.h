#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;
default_random_engine random(time(NULL));
class List
{
private:
    int length;
    int *ptr;
    int SortedFlag;

public:
    List(int len = 0);
    List(List &rhs);
    bool IsEmpty()
    {
        if (length != 0)
            return false;
        return true;
    }
    int GetLength()
    {
        if (this)
            return length;
        else
            return -1;
    };
    void Clear();
    void Sort(int mode);
    void Show();
    int ValueCount(int value);
    int SearchbyLocation(int index)
    {
        if (index >= 0 && index < length)
            return ptr[index];
        else
            return -1;
    };
    int SearchbyValue(int value);
    void InsertbyLocation(int value, int index = -1);
    void DeletebyLocation(int index);
    int DeletebyValue(int value);
    int DeleteDuplicate();
    void ReverseList();
    void PartitionList(int partition);
    bool ImportFromFile(string path);
    bool ExportToFile(string path);
    int MaxPlatform();
    ~List();
};

List::List(int len)
{
    length = len;
    if (length > 0)
    {
        ptr = new int[length];
        static uniform_int_distribution<int> nums(5, 150);
        for (int i = 0; i < length; i++)
            ptr[i] = nums(random);
        SortedFlag = 0;
    }
    else
    {
        ptr = NULL;
        SortedFlag = 0;
    }
}
List::List(List &rhs)
{
    length = rhs.length;
    if (length > 0)
    {
        ptr = new int[length];
        for (int i = 0; i < length; i++)
            ptr[i] = rhs.ptr[i];
        SortedFlag = rhs.SortedFlag;
    }
    else
        ptr = NULL;
}
void List::Clear()
{
    if (ptr)
        delete[] ptr;
    length = 0;
}
void List::Show()
{
    if (length)
        for (int i = 0; i < length; i++)
        {
            cout << ptr[i] << "\t";
            if (!((i + 1) % 10))
                cout << endl;
        }
}
void List::Sort(int mode)
{
    if (ptr)
        if (!mode)
        {
            for (int i = 0; i < length - 1; i++)
            {
                int max = i;
                for (int k = i + 1; k < length; k++)
                    if (ptr[k] > ptr[max])
                        max = k;
                if (max != i)
                {
                    int temp = ptr[i];
                    ptr[i] = ptr[max];
                    ptr[max] = temp;
                }
            }
            SortedFlag = 1;
        }
        else
        {
            for (int i = 0; i < length - 1; i++)
            {
                int min = i;
                for (int k = i + 1; k < length; k++)
                    if (ptr[k] < ptr[min])
                        min = k;
                if (min != i)
                {
                    int temp = ptr[i];
                    ptr[i] = ptr[min];
                    ptr[min] = temp;
                }
            }
            SortedFlag = 1;
        }
}
int List::SearchbyValue(int value)
{
    for (int i = 0; i < length; i++)
        if (ptr[i] == value)
            return i;
    return -1;
}
int List::ValueCount(int value)
{
    int count = 0;
    for (int i = 0; i < length; i++)
        if (ptr[i] == value)
            count++;
    return count;
}
void List::InsertbyLocation(int value, int index)
{
    if (index == -1)
        index = length;
    length++;
    int *newptr = new int[length];
    for (int i = 0; i < index; i++)
        newptr[i] = ptr[i];
    newptr[index] = value;
    for (int i = index + 1; i < length + 1; i++)
        if (ptr)
            newptr[i] = ptr[i - 1];
    if (ptr)
        delete ptr;
    ptr = newptr;
}
void List::DeletebyLocation(int index)
{
    int *newptr = new int[length - 1];
    int i = 0, j = 0;
    while (i < length)
    {
        if (i != index)
        {
            newptr[j] = ptr[i];
            i++, j++;
        }
        else
            i++;
    }
    length--;
    delete ptr;
    ptr = newptr;
}
int List::DeletebyValue(int value)
{
    int count = this->ValueCount(value);
    int *newptr = new int[length - count];
    int i = 0, j = 0;
    while (i < length)
    {
        if (ptr[i] != value)
        {
            newptr[j] = ptr[i];
            i++, j++;
        }
        else
            i++;
    }
    delete ptr;
    length -= count;
    ptr = newptr;
    return count;
}
int List::DeleteDuplicate()
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        while (this->ValueCount(ptr[i]) > 1)
        {

            this->DeletebyLocation(this->SearchbyValue(ptr[i]));
            count++;
        }
    }
    return count;
}
void List::ReverseList()
{

    for (int i = 0; i < length / 2; i++)
    {
        int temp = ptr[i];
        ptr[i] = ptr[length - 1 - i];
        ptr[length - i - 1] = temp;
    }
}
void List::PartitionList(int partition)
{

    if (!SortedFlag)
    {
        int low = 0, high = length - 1;
        while (low < high)
        {
            while (ptr[low] <= partition)
            {
                low++;
            }
            while (ptr[high] > partition)
            {
                high--;
            }
            if (low < high)
            {
                int temp = ptr[high];
                ptr[high] = ptr[low];
                ptr[low] = temp;
            }
        }
    }
    else
    {
        int index;
        for (int i = 0; i < length; i++)
            if (ptr[i] > partition)
            {
                index = i;
                break;
            }
        for (int i = index; i < (index + length + 1) / 2; i++)
        {
            int temp = ptr[i];
            ptr[i] = ptr[(length + index) - i - 1];
            ptr[(length + index) - i - 1] = temp;
        }
    }
}
int List::MaxPlatform()
{
    int max = 1;
    int count = 1;
    for (int i = 0; i < length - 1; i++)
    {

        if (ptr[i] == ptr[i + 1])
            count++;
        else
        {
            if (count > max)
                max = count;
            count = 1;
        }
    }
    return max;
}
bool List::ImportFromFile(string path)
{
    fstream ImportFile(path);
    while (!ImportFile)
    {
        cout << "FileExitError :dictionary or file is not exit: " << path << endl;
        cout << "Please input a valid file name:";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
        cin >> path;
        ImportFile.open(path);
    }
    int temp;
    int count = 0;
    if (length != 0)
    {
        delete ptr;
        ptr = NULL;
        length = 0;
    }
    while (!ImportFile.eof() && (ImportFile >> temp))
    {
        this->InsertbyLocation(temp);
        count++;
    }
    this->length = count;
    ImportFile.close();
    return true;
}
bool List::ExportToFile(string path)
{
    fstream outFile(path, ios_base::out | ios_base::trunc);
    if (!outFile)
    {
        cout << "Failed." << endl;
        return false;
    }
    if (length)
        for (int i = 0; i < length; i++)
        {
            outFile << ptr[i] << "\t";
            if (!((i + 1) % 10))
                outFile << endl;
        }
    outFile.close();
    return true;
}
List::~List()
{
    if (ptr)
        delete[] ptr;
}
