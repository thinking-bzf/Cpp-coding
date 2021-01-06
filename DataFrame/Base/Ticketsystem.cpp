#include <iostream>
using namespace std;
void ShowMenu();
void CreateTheater();
void input(int *x, int start, int end);
class Ticketsystem
{
private:
    // 0表示空闲，1表示被买，2表示被预定
    int **ptr;
    int Columns;
    int Row;
    int Available;
    int Sold;
    int Reserved;

public:
    Ticketsystem(int row, int col);
    // 卖票
    void SellTicket(int row, int col);
    // 显示状态
    void ShowStatus();
    // 退票
    void Refund(int row, int col);
    // 订票
    void BookTicket(int row, int col);
    // 退订
    void Cancelatation(int row, int col);
    // 查票
    void Search(int row, int col);

    ~Ticketsystem();
};

Ticketsystem::Ticketsystem(int row, int col)
{
    ptr = new int *[row];
    for (int i = 0; i < row; i++)
        ptr[i] = new int[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            ptr[i][j] = 0;
    Columns = col;
    Row = row;
    Available = Columns * Row;
    Sold = 0;
    Reserved = 0;
}
void Ticketsystem::ShowStatus()
{
    cout << "0: " << Available << " Available   "
         << "1: " << Sold << " Sold   "
         << "2: " << Reserved << " Reserved" << endl;
    cout << '\t';
    for (int i = 1; i <= Columns; i++)
        cout << i << "\t";
    cout << endl;
    for (int i = 1; i <= Row; i++)
    {
        cout << i << "\t";
        for (int j = 1; j <= Columns; j++)
            cout << ptr[i - 1][j - 1] << "\t";
        cout << endl;
    }
}
void Ticketsystem::SellTicket(int row, int col)
{

    if (ptr[row - 1][col - 1] == 1)
        cout << "The seat is Sold" << endl;
    else if (ptr[row - 1][col - 1] == 2)
        cout << "The seat is Reserved" << endl;
    else
    {
        ptr[row - 1][col - 1] = 1;
        Sold++;
        Available--;
        printf("Ticket:<%d:%d> is sold successfully.\n", row, col);
    }
    this->ShowStatus();
    cout << "Press any key to return Menu" << endl;
    getchar();
    getchar();
}
void Ticketsystem::BookTicket(int row, int col)
{

    if (ptr[row - 1][col - 1] == 1)
        cout << "The seat is Sold" << endl;
    else if (ptr[row - 1][col - 1] == 2)
        cout << "The seat is Reserved" << endl;
    else
    {
        ptr[row - 1][col - 1] = 2;
        Available--;
        Reserved++;
        printf("Ticket:<%d:%d> is booked successfully.\n", row, col);
    }
    this->ShowStatus();
    cout << "Press any key to return Menu" << endl;
    getchar();
    getchar();
}
void Ticketsystem::Search(int row, int col)
{

    if (ptr[row - 1][col - 1] == 1)
        printf("Ticket:<%d:%d> is sold\n", row, col);
    else if (ptr[row - 1][col - 1] == 2)
        printf("Ticket:<%d:%d> is Reserved\n", row, col);
    else
        printf("Ticket:<%d:%d> is Available\n", row, col);
    this->ShowStatus();
    cout << "Press any key to return Menu" << endl;
    getchar();
    getchar();
}
void Ticketsystem::Cancelatation(int row, int col)
{

    if (ptr[row - 1][col - 1] == 2)
    {
        ptr[row - 1][col - 1] = 0;
        Available++;
        Reserved--;
        printf("Ticket:<%d:%d> cancel book successfully.\n", row, col);
    }
    else
        printf("Ticket:<%d:%d> is not booked.\n", row, col);
    this->ShowStatus();
    cout << "Press any key to return Menu" << endl;
    getchar();
    getchar();
}
void Ticketsystem::Refund(int row, int col)
{

    if (ptr[row - 1][col - 1] == 1)
    {
        ptr[row - 1][col - 1] = 0;
        Available++;
        Sold--;
        printf("Ticket:<%d:%d> is refunded successfully.\n", row, col);
    }
    else
        printf("Ticket:<%d:%d> is not sold.\n", row, col);
    this->ShowStatus();
    cout << "Press any key to return Menu" << endl;
    getchar();
    getchar();
}

Ticketsystem::~Ticketsystem()
{
    for (int i = 0; i < Row; i++)
        delete[] ptr[i];
    delete[] ptr;
}

int main()
{
    int choice;
    Ticketsystem *TS = NULL;
    while (1)
    {
        int x, y, columns, row;
        ShowMenu();
        cout << "\nPlease input a integer from 1 to 6 for choice:";
        input(&choice, 1, 8);
        switch (choice)
        {
        case 1:
            cout << "Please input the row of theater:";
            input(&row, 5, 20);
            cout << "Please input the columns of theater:";
            input(&columns, 5, 20);
            TS = new Ticketsystem(row, columns);
            cout << "Create a theater sucessfully." << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            TS->ShowStatus();
            cout << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            // cout << "Multiplication" << endl;
            TS->ShowStatus();
            cout << "Please input the row:";
            input(&x, 1, row);
            cout << "Please input the columns:";
            input(&y, 1, columns);
            TS->SellTicket(x, y);
            break;
        case 4:
            // cout << "Division" << endl;
            TS->ShowStatus();
            cout << "Please input the row:";
            input(&x, 1, row);
            cout << "Please input the columns:";
            input(&y, 1, columns);
            TS->Refund(x, y);
            break;
        case 5:
            // cout << "Mixed" << end;;
            TS->ShowStatus();
            cout << "Please input the row:";
            input(&x, 1, row);
            cout << "Please input the columns:";
            input(&y, 1, columns);
            TS->BookTicket(x, y);
            break;
        case 6:
            // cout << "Division" << endl;
            TS->ShowStatus();
            cout << "Please input the row:";
            input(&x, 1, row);
            cout << "Please input the columns:";
            input(&y, 1, columns);
            TS->Cancelatation(x, y);
            break;
        case 7:
            // cout << "Mixed" << end;;
            cout << "Please input the row:";
            input(&x, 1, row);
            cout << "Please input the columns:";
            input(&y, 1, columns);
            TS->Search(x, y);
            break;
        }
        if (choice == 8)
        {
            if (TS)
                delete TS;
            break;
        }
    }
}

void ShowMenu()
{
    cout << "*******************I love jlj***********************" << endl;
    cout << endl;
    cout << "*******************Tickets System*******************" << endl;
    cout << "*                                                  *" << endl;
    cout << "*     1-Create Theater          2-Show Status      *" << endl;
    cout << "*                                                  *" << endl;
    cout << "*     3-Sell Ticket             4-Refund           *" << endl;
    cout << "*                                                  *" << endl;
    cout << "*     5-Book Ticket             6-Cancellation     *" << endl;
    cout << "*                                                  *" << endl;
    cout << "*     7-Search                  8-Exit             *" << endl;
    cout << "****************************************************" << endl;
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
