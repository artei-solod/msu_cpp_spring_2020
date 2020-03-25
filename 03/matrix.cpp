#include <iostream>
#include "mxtlib.h"
using namespace std;


matrix::matrix(int row, int col)
{
    Row = row;  //���������� Row � Col ����������� �������� �������� ����� ����� � �������� �������
    Col = col;
    Value = new double* [row];  //����������� ������� ��������� ������������ ������
    for (int i = 0; i < row; i++) Value[i] = new double[col];
}

matrix::matrix(const matrix& m) //���������� ����������� - ������� ����� ������� m
    :Row(m.Row), Col(m.Col)
{
    Value = new double* [Row];
    for (int i = 0; i < Row; i++)  Value[i] = new double[Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } // �������� ��������� ������� ����� ������ ��, ��� � ������� m
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



int matrix::GetRow() //������� �������� �������� ����� �����
{
    return (Row);
}

int matrix::GetCol() //������� �������� �������� ����� ��������
{
    return (Col);
}

istream& operator>>(istream& istr, matrix& m) // ���������� ��������� ����� �������
{
    for (int i = 0; i < m.GetRow(); i++)
        for (int j = 0; j < m.GetCol(); j++)
            istr >> m(i, j);
    return(istr);
}

ostream& operator<<(ostream& ostr, matrix& m) //���������� ��������� ������ �������
{
    for (int i = 0; i < m.GetRow(); i++)
    {
        for (int j = 0; j < m.GetCol(); j++)
            ostr << m(i, j) << "\t";
        ostr << "\n";
    }
    return(ostr);
}

matrix operator+(matrix& m1, matrix& m2) //���������� ��������� ���� (��������)
{
    matrix temp(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
        for (int j = 0; j < m1.GetCol(); j++)
            temp(i, j) = m1(i, j) + m2(i, j);
    return(temp);
}

matrix operator-(matrix& m1, matrix& m2) //���������� ��������� ����� (��������)
{
    matrix temp1(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
        for (int j = 0; j < m1.GetCol(); j++)
            temp1(i, j) = m1(i, j) - m2(i, j);
    return(temp1);
}

double& matrix::operator()(int row, int col)//���������� ������� ������ ��� �������.
{                             // ���� m - �������, �� m(i,j) �����
    return (Value[row][col]);  //�������� i,j-��� ������� �������
}

double matrix::operator()(int row, int col) const//���������� ������� ������ ��� �������.
{                             // ���� m - �������, �� m(i,j) �����
    return (Value[row][col]);  //�������� i,j-��� ������� �������
}
matrix& matrix::operator*=(int n) {
    for (int i = 0; i < this->Row; ++i) {
        for (int j = 0; j < this->Col; ++j) {
            Value[i][j] *= n;
        }
    }
    return *this;
}

matrix::~matrix() //����������
{
    for (int i = 0; i < Row; i++)
        delete[] Value[i]; //���������� ������� �� ������ ������������ ������, ��������� �������������
    delete[] Value;
}
