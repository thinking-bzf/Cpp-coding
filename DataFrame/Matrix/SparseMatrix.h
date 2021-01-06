#ifndef _SPARSEMATRIX_H_
#define _SPARSEMATRIX_H_
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <cstdlib>

struct Trituple
{
    int row, col;
    int item;
};
bool compare(Trituple a, Trituple b)
{
    if (a.row == b.row)
        return a.col < b.col;
    return a.row < b.row;
}

class SparseMatrix
{
private:
    Trituple *data;
    int rows, cols, terms; //矩阵的行数、列数、非零元素个数
    int maxterms;

public:
    SparseMatrix(int r = 0, int c = 0, int item = 0);
    SparseMatrix(SparseMatrix &);
    ~SparseMatrix();
    void Clearterms() { terms = 0; };
    void ClearMatrix() { rows = cols = terms = maxterms = 0; };
    int GetRow() { return rows; }
    int GetCol() { return cols; }
    int GetMaxterm() { return maxterms; }
    int GetTerms() { return terms; }
    void init(int r, int c, int item);       //初始化
    bool TransposeTo(SparseMatrix &);        // 转置
    bool TransposeTo_Faster(SparseMatrix &); // 快速转置
    void AddTo(const SparseMatrix &);        // 加运算
    bool Input();                            // 输入稀疏矩阵
    void Show();
    void ShowTriples();
    bool GetElement(int, int, int &); // 获取指定行列元素
    bool SetElement(int, int, int &); //设置指定行列元素
};

SparseMatrix::SparseMatrix(int r, int c, int item)
{
    init(r, c, item);
}
void SparseMatrix::init(int r, int c, int item)
{
    rows = r;
    cols = c;
    terms = item;
    maxterms = r * c;
    data = new Trituple[item];
    srand((unsigned)time(NULL));

    // static std::uniform_int_distribution<int> Row(1, rows);
    // static std::uniform_int_distribution<int> Col(1, cols);
    static std::uniform_int_distribution<int> nums(11, 30);
    static std::default_random_engine random(time(NULL));
    int col = 0, row = 0, term = 0;
    for (int i = 0; i < item; i++)
    {
        int flag = 0;
        while (!flag)
        {
            // col = Col(random);
            // row = Row(random);
            col = (rand() % (cols)) + 1;
            row = (rand() % (rows)) + 1;
            term = nums(random);
            flag = 1;
            for (int j = 0; j <= i; j++)
            {
                if (data[j].col == col && data[j].row == row)
                {
                    flag = 0;
                    break;
                }
            }
        }

        data[i].col = col;
        data[i].row = row;
        data[i].item = term;
    }
    std::sort(data, data + item, compare);
}
SparseMatrix::SparseMatrix(SparseMatrix &rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;
    maxterms = rhs.maxterms;
    terms = rhs.terms;
    data = new Trituple[terms];
    for (int i = 0; i < terms; i++)
    {
        data[i].col = rhs.data[i].col;
        data[i].row = rhs.data[i].row;
        data[i].item = rhs.data[i].item;
    }
}

SparseMatrix::~SparseMatrix()
{
    ClearMatrix();
    if (data)
        delete data;
}
void SparseMatrix::Show()
{
    int count = 0;
    int flag = 1;
    if (terms == 0)
        flag = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (flag == 1)
                if (data[count].row - 1 == i && data[count].col - 1 == j)
                {
                    std::cout << data[count].item << "\t";
                    count++;
                }
                else
                    std::cout << 0 << "\t";
            else
            {
                std::cout << 0 << "\t";
            }
        }
        std::cout << std::endl;
    }
}
bool SparseMatrix::TransposeTo(SparseMatrix &B)
{
    B.cols = rows;
    B.rows = cols;
    if (B.terms != terms)
    {
        delete[] B.data;
        B.data = new Trituple[terms];
    }
    B.terms = terms;
    for (int i = 0; i < terms; i++)
    {
        B.data[i].col = data[i].row;
        B.data[i].row = data[i].col;
        B.data[i].item = data[i].item;
    }
    std::sort(B.data, B.data + B.terms, compare);
    B.Show();
    return true;
}

void SparseMatrix::ShowTriples()
{
    std::cout << "Row\tCol\titem\n";
    for (int i = 0; i < terms; i++)
    {
        std::cout << data[i].row << "\t" << data[i].col << "\t" << data[i].item << std::endl;
    }
}

bool SparseMatrix::GetElement(int row, int col, int &out)
{
    if (row > rows || row < 0 || col < 0 || col > cols)
        return false;
    for (int i = 0; i < terms; i++)
        if (data[i].col == col && data[i].row == row)
        {
            out = data[i].item;
            return true;
        }
    out = 0;
    return true;
}

bool SparseMatrix::SetElement(int row, int col, int &in)
{
    if (row > rows || row < 0 || col < 0 || col > cols)
        return false;
    // int flag = 1;
    for (int i = 0; i < terms; i++)
        if (data[i].col == col && data[i].row == row)
        {
            data[i].item = in;
            return true;
        }
    data[terms].col = col;
    data[terms].row = row;
    data[terms].item = in;
    terms++;
    std::sort(data, data + terms, compare);
    return true;
}
#endif