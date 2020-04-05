#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#ifndef	_MTXLIB_H_
#define	_MTXLIB_H_


class Matrix
{
    size_t Row, Col;  //������ � �������
    double **Value;  // �������� �������
public:

    Matrix(size_t, size_t);  //�����������
    Matrix(const Matrix&); //���������� ����������� - ������� ����� ������� m
    size_t GetRow(); //����� �������� �������� ����� �����
    size_t GetCol(); //����� �������� �������� ����� ��������
    double& operator()(size_t, size_t); //���������� ������ ��� �������
    double operator()(size_t, size_t) const; //���������� ������ ��� �������
    Matrix& operator*=(size_t n);
    friend istream& operator>>(istream& istr, Matrix& m);//���������� ��������� �����
    friend ostream& operator<<(ostream& ostr, Matrix& m);//���������� ��������� ������
    friend Matrix operator+(Matrix& m1, Matrix& m2);//���������� ��������� ���� (��������)
    friend Matrix operator-(Matrix& m1, Matrix& m2);//���������� ��������� ����� (��������) 
    class Vec
    {
        size_t vn;
        double* v;
    public:
        Vec(double*, size_t);
        double& operator[](const size_t);
    };
    Vec operator[](size_t) const;
    
    ~Matrix(); //����������
};
#endif
