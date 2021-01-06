#ifndef _TRIANGULARMATRIX_H_
#define _TRIANGULARMATRIX_H_
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class TriangularMatrix
{
private:
    int *data;
    int rank;
    int mode; //0表示上三角矩阵，1表示下三角矩阵，2表示对称矩阵
    int count;

public:
    TriangularMatrix(int r = 4, int m = -1);
    ~TriangularMatrix();
    void show();
    int Isempty() { return mode == -1; }
    int GetCount() { return count; }
    int GetRank() { return rank; }
    int GetMaxsize() { return rank * rank; }
    void Transpose();
    void Clear();
    bool GetElement(int, int, int &);
    bool SetElement(int, int, int &);
    void init(int, int);
    int Sum();
};
TriangularMatrix::TriangularMatrix(int r, int m)
{
    init(r, m);
}

TriangularMatrix::~TriangularMatrix()
{
    mode = -1;
    if (data)
        delete data;
}
void TriangularMatrix::Clear()
{
    rank = 0;
    mode = -1;
}
void TriangularMatrix::init(int r, int m)
{
    rank = r;
    mode = m;
    if (mode != 2)
        count = (rank + 1) * rank / 2 + 1;
    else
        count = (rank + 1) * rank / 2;
    data = new int[count];
    static std::uniform_int_distribution<int> nums(11, 30);
    static std::default_random_engine random(time(NULL));
    data[rank * rank] = nums(random);
    for (int i = 0; i < count; i++)
        data[i] = nums(random);
}
void TriangularMatrix::show()
{
    std::cout << std::endl;
    if (mode == 0)
    {
        std::cout << "This is a Upper Matrix\n";
        for (int i = 1; i <= rank; i++)
        {
            for (int j = 1; j <= rank; j++)
            {
                if (i <= j)
                    std::cout << data[(i - 1) * (2 * rank - i + 2) / 2 + j - i] << "\t";
                else
                    std::cout << data[(rank + 1) * rank / 2] << "\t";
            }
            std::cout << std::endl;
        }
    }
    else if (mode == 1)
    {
        std::cout << "This is a Lower Matrix\n";
        for (int i = 1; i <= rank; i++)
        {
            for (int j = 1; j <= rank; j++)
            {
                if (i >= j)
                    std::cout << data[(i - 1) * i / 2 + j - 1] << "\t";
                else
                    std::cout << data[(rank + 1) * rank / 2] << "\t";
            }
            std::cout << std::endl;
        }
    }
    else if (mode == 2)
    {
        std::cout << "This is a Symmetric Matrix\n";
        for (int i = 1; i <= rank; i++)
        {
            for (int j = 1; j <= rank; j++)
            {
                if (i > j)
                    std::cout << data[(j - 1) * (2 * rank - j + 2) / 2 + i - j] << "\t";
                else if (i <= j)
                    std::cout << data[(i - 1) * (2 * rank - i + 2) / 2 + j - i] << "\t";
                // else if (i == j)
                //     std::cout << data[(rank + 1) * rank / 2 + i - 1] << "\t";
            }
            std::cout << std::endl;
        }
    }
    else
        std::cout << "The Matrix is empty" << std::endl;
}

void TriangularMatrix::Transpose()
{
    if (mode != 2)
        mode = 1 - mode;
}
bool TriangularMatrix::GetElement(int i, int j, int &out)
{
    if (mode == 0)
    {
        if (i <= j)
        {
            out = data[(i - 1) * (2 * rank - i + 2) / 2 + j - i];
            return true;
        }
        else
        {
            out = data[(rank + 1) * rank / 2];
            return true;
        }
    }
    else if (mode == 1)
    {
        if (i >= j)
        {
            out = data[(i - 1) * i / 2 + j - 1];
            return true;
        }
        else
        {
            out = data[(rank + 1) * rank / 2];
            return true;
        }
    }
    else if (mode == 2)
    {
        if (i > j)
        {
            out = data[(j - 1) * (2 * rank - j + 2) / 2 + i - j];
            return true;
        }
        else if (i <= j)
        {
            out = data[(i - 1) * (2 * rank - i + 2) / 2 + j - i];
            return true;
        }
    }
    return false;
}
bool TriangularMatrix::SetElement(int i, int j, int &in)
{
    if (mode == 0)
    {
        if (i <= j)
        {
            data[(i - 1) * (2 * rank - i + 2) / 2 + j - i] = in;
            return true;
        }
        else
        {
            data[(rank + 1) * rank / 2] = in;
            return true;
        }
    }
    else if (mode == 1)
    {
        if (i >= j)
        {
            data[(i - 1) * i / 2 + j - 1] = in;
            return true;
        }
        else
        {
            data[(rank + 1) * rank / 2] = in;
            return true;
        }
    }
    else if (mode == 2)
    {
        if (i > j)
        {
            data[(j - 1) * (2 * rank - j + 2) / 2 + i - j] = in;
            return true;
        }
        else if (i <= j)
        {
            data[(i - 1) * (2 * rank - i + 2) / 2 + j - i] = in;
            return true;
        }
    }
    return false;
}
int TriangularMatrix::Sum()
{
    int sum = 0;
    if (mode == 0 || mode == 1)
    {
        for (int i = 0; i < count - 1; i++)
            sum += data[i];
        sum += (rank - 1) * rank / 2 * data[count - 1];
    }
    else if (mode == 2)
    {
        int temp = 0;
        int temprank = rank;
        for (int i = 1; i <= count;)
        {
            temp += data[i - 1];
            i += temprank;
            temprank--;
        }
        for (int i = 0; i < count; i++)
            sum += data[i];
        sum *= 2;
        sum -= temp;
    }
    return sum;
}

#endif