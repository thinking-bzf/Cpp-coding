#include <iostream>
#include <random>
#include <ctime>
#include "SparseMatrix.h"
using namespace std;
void input(int *x, int start, int end);
void ShowMenu();
void CreateSM(SparseMatrix &SM);
void Transpose(SparseMatrix &);
void SetElement(SparseMatrix &SM);
void GetElement(SparseMatrix &SM);
void SetRandomValues(SparseMatrix &SM);
int main()
{
    SparseMatrix SM;
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
            // 创建稀疏数组
            CreateSM(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();

            break;
        case 2:
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
            {
                SM.Show();
                cout << "The Total Element of the Sparse Matrix is: " << SM.GetMaxterm() << endl
                     << " Amout of None Zero Elements of the Sparse Matrix is : " << SM.GetTerms() << endl
                     << " The Sparse Factor of the Sparse Matrix is : ";
                printf("%.2f%%\n", SM.GetTerms() * 1.0 / SM.GetMaxterm() * 100);
                cout << "The Compression Ratio of the Triangular Matrix is : ";
                printf("%.2f%%\n", (SM.GetMaxterm() - SM.GetTerms() * 3) * 1.0 / SM.GetMaxterm() * 100);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;

        case 3:
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
            {
                SM.Show();
                cout << "The None Zero Elements of the Sparse Matrix are:\n";
                SM.ShowTriples();
            }

            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 4:
            // 4. Clear Matrix(置空稀疏矩阵)
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
            {
                SM.ClearMatrix();
                cout << "The Sparse Matrix has been cleared \n"
                     << "The Total Element of the Sparse Matrix is: " << SM.GetMaxterm() << endl
                     << "Amout of None Zero Elements of the Sparse Matrix is: " << SM.GetTerms() << endl;
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            break;
        case 5:
            // 5. Clear None Zero Elements(清空非零值)
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is already Empty\n";
            else
            {
                SM.Clearterms();
                cout << "The Sparse Matrix has been cleared " << endl;
                SM.Show();
                cout << "The Total Element of the Sparse Matrix is: " << SM.GetMaxterm() << endl
                     << " Amout of None Zero Elements of the Sparse Matrix is : " << SM.GetTerms() << endl
                     << " The Sparse Factor of the Sparse Matrix is : ";
                printf("%.2f%%\n", SM.GetTerms() * 1.0 / SM.GetMaxterm() * 100);
                cout << "The Compression Ratio of the Triangular Matrix is : ";
                printf("%.2f%%\n", (SM.GetMaxterm() - SM.GetTerms() * 3) * 1.0 / SM.GetMaxterm() * 100);
            }
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 6:
            // 6. Set Random Values(设置非零随机值)
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
                SetRandomValues(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 7:
            // 7. Get Element(获取矩阵元素值)
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
                GetElement(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 8:
            // 8. Set Element(设置矩阵元素值)
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
                SetElement(SM);
            cout << endl
                 << "Press any key to return Menu" << endl;
            getchar();
            getchar();
            /* code */
            break;
        case 9:
            // 9. Transpose of Matrix(矩阵转置)
            if (SM.GetMaxterm() == 0)
                cout << "The Sparse Matrix is Empty\n";
            else
                Transpose(SM);

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
    cout << "*******************I Love JLJ***********************" << endl;
    cout << endl;
    cout << "***************** Sparse Matrix System *****************" << endl;
    cout << "*                                                      *" << endl;
    cout << "*   1. Create Sparse Matrix     2. Show Matrix Status  *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*   3. Show None Zero Triples   4. Clear Matrix        *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*   5. Clear None Zero Elements 6. Set Random Values   *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*   7. Get Element              8. Set Element         *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*   9. Transpose of Matrix      10. Exit               *" << endl;
    cout << "*                                                      *" << endl;
    cout << "********************************************************" << endl;
}
void input(int *x, int start = 0, int end = 2333)
{
    while (!(cin >> *x) || (*x < start) || (*x > end))
    {
        // 确保获取的是整数
        cout << "InputError:please input again";
        cin.clear(); //恢复错误的状态
        cin.sync();  //清楚之前的输入数据
    }
}

void CreateSM(SparseMatrix &SM)
{
    default_random_engine random(time(NULL));
    static uniform_int_distribution<int> Matrix(3, 10);
    int row = Matrix(random);
    int col = Matrix(random);
    static uniform_int_distribution<int> Count(3, row * col / 2);
    int len = Count(random);
    SM.init(row, col, len);
    cout << "row\tcol\tnum" << endl;
    cout << row << "\t" << col << "\t" << len << endl;
    cout << "The Matrix is:" << endl;
    SM.Show();
}

void Transpose(SparseMatrix &SM)
{
    SparseMatrix B;
    SM.TransposeTo(B);
}

void SetRandomValues(SparseMatrix &SM)
{
    cout << "The original Matrix:" << endl;
    SM.Show();
    default_random_engine random(time(NULL));
    static uniform_int_distribution<int> Row(1, SM.GetRow());
    static uniform_int_distribution<int> Col(1, SM.GetCol());
    static std::uniform_int_distribution<int> nums(11, 30);
    int count;
    input(&count);
    cout << "row\tcol\tnum\n";
    for (int i = 0; i < count; i++)
    {
        int row = Row(random);
        int col = Col(random);
        int num = nums(random);
        SM.SetElement(row, col, num);
        cout << row << "\t" << col << "\t" << num << endl;
    }
    cout << "The Matrix is:" << endl;
    SM.Show();
}

void GetElement(SparseMatrix &SM)
{
    int row, col;
    cout << "Please input the row number: ";
    input(&row, 1, SM.GetRow());
    cout << "Please input the column number: ";
    input(&col, 1, SM.GetCol());
    int temp;
    SM.GetElement(row, col, temp);
    cout << "The Element is " << temp;
}

void SetElement(SparseMatrix &SM)
{
    int row, col, value;
    cout << "Please input the row number: ";
    input(&row, 1, SM.GetRow());
    cout << "Please input the column number: ";
    input(&col, 1, SM.GetCol());
    cout << "Please input the values to be set: ";
    input(&value);
    SM.SetElement(row, col, value);
    cout << "The Element " << value << " is set successfully" << endl;
    SM.Show();
}