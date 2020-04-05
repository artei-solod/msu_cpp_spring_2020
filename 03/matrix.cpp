#include <iostream>
#include "mxtlib.h"
using namespace std;


Matrix::Matrix(size_t row, size_t col)
{
    Row = row;  //���������� Row � Col ����������� �������� �������� ����� ����� � �������� �������
    Col = col;
    Value = new double* [row];  //����������� ������� ��������� ������������ ������
    for (int i = 0; i < row; i++) Value[i] = new double[col];
}

Matrix::Matrix(const Matrix& m) //���������� ����������� - ������� ����� ������� m
    :Row(m.Row), Col(m.Col)
{
    Value = new double* [Row];
    for (size_t i = 0; i < Row; i++)  Value[i] = new double[Col];
    for (size_t i = 0; i < Row; i++)
    {
        for (size_t j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } // �������� ��������� ������� ����� ������ ��, ��� � ������� m
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



size_t Matrix::GetRow() //������� �������� �������� ����� �����
{
    return (Row);
}

size_t Matrix::GetCol() //������� �������� �������� ����� ��������
{
    return (Col);
}

istream& operator>>(istream& istr, Matrix& m) // ���������� ��������� ����� �������
{
    for (size_t i = 0; i < m.GetRow(); i++)
        for (size_t j = 0; j < m.GetCol(); j++)
            istr >> m(i, j);
    return(istr);
}

ostream& operator<<(ostream& ostr, Matrix& m) //���������� ��������� ������ �������
{
    for (size_t i = 0; i < m.GetRow(); i++)
    {
        for (size_t j = 0; j < m.GetCol(); j++)
            ostr << m(i, j) << "\t";
        ostr << "\n";
    }
    return(ostr);
}

Matrix operator+(Matrix& m1, Matrix& m2) //���������� ��������� ���� (��������)
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

Matrix operator-(Matrix& m1, Matrix& m2) //���������� ��������� ����� (��������)
{
    Matrix temp1(m1.GetRow(), m1.GetCol());
    for (size_t i = 0; i < m1.GetRow(); i++)
        for (size_t j = 0; j < m1.GetCol(); j++)
            temp1(i, j) = m1(i, j) - m2(i, j);
    return(temp1);
}

double& Matrix::operator()(size_t row, size_t col)//���������� ������� ������ ��� �������.
{                             // ���� m - �������, �� m(i,j) �����
    return (Value[row][col]);  //�������� i,j-��� ������� �������
}

double Matrix::operator()(size_t row, size_t col) const//���������� ������� ������ ��� �������.
{                             // ���� m - �������, �� m(i,j) �����
    return (Value[row][col]);  //�������� i,j-��� ������� �������
}
Matrix& Matrix::operator*=(size_t n) {
    for (size_t i = 0; i < this->Row; ++i) {
        for (size_t j = 0; j < this->Col; ++j) {
            Value[i][j] *= n;
        }
    }
    return *this;
}

Matrix::~Matrix() //����������
{
    for (size_t i = 0; i < Row; i++)
        delete[] Value[i]; //���������� ������� �� ������ ������������ ������, ��������� �������������
    delete[] Value;
}
