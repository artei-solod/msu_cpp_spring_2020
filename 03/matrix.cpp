#include <iostream>
#include "mxtlib.h"
using namespace std;


Matrix::Matrix(size_t row, size_t col)
{
    Row = row;  //переменным Row и Col присваиются вводимые значения числа строк и столбцов матрицы
    Col = col;
    Value = new double* [row];  //конструктор создает двумерный динамический массив
    for (int i = 0; i < row; i++) Value[i] = new double[col];
}

Matrix::Matrix(const Matrix& m) //копирующий конструктор - создает копию матрицы m
    :Row(m.Row), Col(m.Col)
{
    Value = new double* [Row];
    for (size_t i = 0; i < Row; i++)  Value[i] = new double[Col];
    for (size_t i = 0; i < Row; i++)
    {
        for (size_t j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } // значения элементов матрицы будут такими же, как у матрицы m
}
Matrix::Vec::Vec(double * mas, size_t sz)
{
    vn = sz;
    v = mas;
}

double& Matrix::Vec::operator[](const size_t i)
{
    if (i >= vn) throw std::out_of_range("Size Error!");
    return (this->v)[i];
}

Matrix::Vec Matrix::operator[](size_t i) const
{
    if (i >= Row) throw std::out_of_range("Size Error!");
    Vec r(Value[i], Col);
    return r;
}



size_t Matrix::GetRow() //функция получает значение числа строк
{
    return (Row);
}

size_t Matrix::GetCol() //функция получает значение числа столбцов
{
    return (Col);
}

istream& operator>>(istream& istr, Matrix& m) // перегрузка оператора ввода матрицы
{
    for (size_t i = 0; i < m.GetRow(); i++)
        for (size_t j = 0; j < m.GetCol(); j++)
            istr >> m(i, j);
    return(istr);
}

ostream& operator<<(ostream& ostr, Matrix& m) //перегрузка оператора вывода матрицы
{
    for (size_t i = 0; i < m.GetRow(); i++)
    {
        for (size_t j = 0; j < m.GetCol(); j++)
            ostr << m(i, j) << "\t";
        ostr << "\n";
    }
    return(ostr);
}

Matrix operator+(Matrix& m1, Matrix& m2) //перегрузка оператора плюс (бинарный)
{
    if (m1.GetRow() != m2.GetRow() || m1.GetCol() != m2.GetCol()) {
        cout << "Inappropriate size";
        return m1;
    }
    Matrix temp(m1.GetRow(), m1.GetCol());
    for (size_t i = 0; i < m1.GetRow(); i++)
        for (size_t j = 0; j < m1.GetCol(); j++)
            temp(i, j) = m1(i, j) + m2(i, j);
    return(temp);
}

Matrix operator-(Matrix& m1, Matrix& m2) //перегрузка оператора минус (бинарный)
{
    Matrix temp1(m1.GetRow(), m1.GetCol());
    for (size_t i = 0; i < m1.GetRow(); i++)
        for (size_t j = 0; j < m1.GetCol(); j++)
            temp1(i, j) = m1(i, j) - m2(i, j);
    return(temp1);
}

double& Matrix::operator()(size_t row, size_t col)//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    return (Value[row][col]);  //означать i,j-тый элемент матрицы
}

double Matrix::operator()(size_t row, size_t col) const//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
    return (Value[row][col]);  //означать i,j-тый элемент матрицы
}
Matrix& Matrix::operator*=(size_t n) {
    for (size_t i = 0; i < this->Row; ++i) {
        for (size_t j = 0; j < this->Col; ++j) {
            Value[i][j] *= n;
        }
    }
    return *this;
}

Matrix::~Matrix() //деструктор
{
    for (size_t i = 0; i < Row; i++)
        delete[] Value[i]; //деструктор удаляет из памяти динамический массив, созданный конструктором
    delete[] Value;
}
