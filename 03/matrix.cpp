#include <iostream>
#include "mxtlib.h"
using namespace std;


matrix::matrix(int row, int col)
{
    Row = row;  //переменным Row и Col присваиются вводимые значения числа строк и столбцов матрицы
    Col = col;
    Value = new double* [row];  //конструктор создает двумерный динамический массив
    for (int i = 0; i < row; i++) Value[i] = new double[col];
}

matrix::matrix(const matrix& m) //копирующий конструктор - создает копию матрицы m
    :Row(m.Row), Col(m.Col)
{
    Value = new double* [Row];
    for (int i = 0; i < Row; i++)  Value[i] = new double[Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } // значения элементов матрицы будут такими же, как у матрицы m
}
matrix::Vec::Vec(double * mas, int sz)
{
    vn = sz;
    v = mas;
}

double& matrix::Vec::operator[](const int i)
{
    if (i >= vn) throw std::out_of_range("Size Error!");
    return (this->v)[i];
}

matrix::Vec matrix::operator[](int i) const
{
    if (i >= Row) throw std::out_of_range("Size Error!");
    Vec r(Value[i], Col);
    return r;
}



int matrix::GetRow() //функция получает значение числа строк
{
    return (Row);
}

int matrix::GetCol() //функция получает значение числа столбцов
{
    return (Col);
}

istream& operator>>(istream& istr, matrix& m) // перегрузка оператора ввода матрицы
{
    for (int i = 0; i < m.GetRow(); i++)
        for (int j = 0; j < m.GetCol(); j++)
            istr >> m(i, j);
    return(istr);
}

ostream& operator<<(ostream& ostr, matrix& m) //перегрузка оператора вывода матрицы
{
    for (int i = 0; i < m.GetRow(); i++)
    {
        for (int j = 0; j < m.GetCol(); j++)
            ostr << m(i, j) << "\t";
        ostr << "\n";
    }
    return(ostr);
}

matrix operator+(matrix& m1, matrix& m2) //перегрузка оператора плюс (бинарный)
{
    matrix temp(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
        for (int j = 0; j < m1.GetCol(); j++)
            temp(i, j) = m1(i, j) + m2(i, j);
    return(temp);
}

matrix operator-(matrix& m1, matrix& m2) //перегрузка оператора минус (бинарный)
{
    matrix temp1(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
        for (int j = 0; j < m1.GetCol(); j++)
            temp1(i, j) = m1(i, j) - m2(i, j);
    return(temp1);
}

double& matrix::operator()(int row, int col)//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    return (Value[row][col]);  //означать i,j-тый элемент матрицы
}

double matrix::operator()(int row, int col) const//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    return (Value[row][col]);  //означать i,j-тый элемент матрицы
}
matrix& matrix::operator*=(int n) {
    for (int i = 0; i < this->Row; ++i) {
        for (int j = 0; j < this->Col; ++j) {
            Value[i][j] *= n;
        }
    }
    return *this;
}

matrix::~matrix() //деструктор
{
    for (int i = 0; i < Row; i++)
        delete[] Value[i]; //деструктор удаляет из памяти динамический массив, созданный конструктором
    delete[] Value;
}
