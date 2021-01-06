#include <iostream>
#include "TriangularMatrix.h"
using namespace std;
void input(int *x, int start, int end);
void ShowMenu();
void CreateUpperMatrix(TriangularMatrix &);
void CreateLowerMatrix(TriangularMatrix &);
void CreateSymmetricMatrix(TriangularMatrix &);
void ShowMatrixStatus(TriangularMatrix &);
void TransposeOfMatrix(TriangularMatrix &);
void ClearMatrix(TriangularMatrix &);
void GetElement(TriangularMatrix &);
void SetElement(TriangularMatrix &);
void GetSumofMatrix(TriangularMatrix &);
int main()
{
    TriangularMatrix SM;
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
            CreateUpperMatrix(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 2:
            CreateLowerMatrix(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 3:
            CreateSymmetricMatrix(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 4:
            if (SM.Isempty())
                cout << "The Matrix is Empty." << endl;
            else
                ShowMatrixStatus(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 5:
            if (SM.Isempty())
                cout << "The Matrix is Empty." << endl;
            else
                TransposeOfMatrix(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            if (SM.Isempty())
                cout << "The Matrix is Empty." << endl;
            else
                ClearMatrix(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            if (SM.Isempty())
                cout << "The Matrix is Empty." << endl;
            else
                GetElement(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            if (SM.Isempty())
                cout << "The Matrix is Empty." << endl;
            else
                SetElement(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            if (SM.Isempty())
                cout << "The Matrix is Empty." << endl;
            else
                GetSumofMatrix(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        }
        if (choice == 10)
            break;
    }
    return 0;
}
void ShowMenu()
{
    cout << "************************I Love JLJ*************************" << endl;
    cout << endl;
    cout << "*******************Triangular Matrix System****************" << endl;
    cout << "*                                                         *" << endl;
    cout << "*   1. Create Upper Matrix      2. Create Lower Matrix    *" << endl;
    cout << "*                                                         *" << endl;
    cout << "*   3. Create Symmetric Matrix  4. Show Matrix Status     *" << endl;
    cout << "*                                                         *" << endl;
    cout << "*   5. Transpose of Matrix      6. Clear Matrix           *" << endl;
    cout << "*                                                         *" << endl;
    cout << "*   7. Get Element              8. Set Element            *" << endl;
    cout << "*                                                         *" << endl;
    cout << "*   9. Get Sum of Matrix        10. Exit                  *" << endl;
    cout << "*                                                         *" << endl;
    cout << "***********************************************************" << endl;
}
void input(int *x, int start = 1, int end = 2333)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}

void CreateUpperMatrix(TriangularMatrix &SM)
{
    int rank;
    // cout << "Please input the mode of Martix(0-Upper;1-Lower;3-Symmetric):";
    // input(&mode, 0, 2);
    cout << "Please input the rank of Upper Matrix(2-10):";
    input(&rank, 2, 10);
    SM.init(rank, 0);
    SM.show();
}
void CreateLowerMatrix(TriangularMatrix &SM)
{
    int rank;
    cout << "Please input the rank of Lower Matrix(2-10):";
    input(&rank, 2, 10);
    SM.init(rank, 1);
    SM.show();
}
void CreateSymmetricMatrix(TriangularMatrix &SM)
{
    int rank;
    cout << "Please input the rank of Symmetric Matrix(2-10):";
    input(&rank, 2, 10);
    SM.init(rank, 2);
    SM.show();
}
void ShowMatrixStatus(TriangularMatrix &SM)
{
    SM.show();
    cout << "The Total Elements of the Triangular Matrix is:" << SM.GetMaxsize() << endl;
    cout << "he Memory Spaces for the Triangular Matrix is:" << SM.GetCount() << endl;
    cout << "The Compression Ratio of the Triangular Matrix is:";
    printf("%.2f%%\n", SM.GetCount() * 1.0 / SM.GetMaxsize() * 100);
}
void TransposeOfMatrix(TriangularMatrix &SM)
{
    SM.Transpose();
    SM.show();
}
void ClearMatrix(TriangularMatrix &SM)
{

    SM.Clear();
    cout << "The Matrix is Cleared." << endl;
}
void GetElement(TriangularMatrix &SM)
{
    int row, col;
    cout << "Please input the row number(1-" << SM.GetRank() << "):";
    input(&row, 1, SM.GetRank());
    cout << "Please input the col number(1-" << SM.GetRank() << "):";
    input(&col, 1, SM.GetRank());
    int temp;
    if (SM.GetElement(row, col, temp))
        cout << "The Element is " << temp << endl;
}
void SetElement(TriangularMatrix &SM)
{
    SM.show();
    int row, col;
    cout << "Please input the row number(1-" << SM.GetRank() << "):";
    input(&row, 1, SM.GetRank());
    cout << "Please input the col number(1-" << SM.GetRank() << "):";
    input(&col, 1, SM.GetRank());
    int value;
    cout << "Please input the values to be set:";
    input(&value, 1);
    if (SM.SetElement(row, col, value))
        cout << "The e lement " << value << " is set successfully" << endl;
    SM.show();
}
void GetSumofMatrix(TriangularMatrix &SM)
{
    SM.show();
    cout << "The sum of the Matrix is:" << SM.Sum() << endl;
}