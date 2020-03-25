#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#ifndef	_MTXLIB_H_
#define	_MTXLIB_H_


class matrix
{
    int Row, Col;  //������ � �������
    double **Value;  // �������� �������
public:

    matrix(int, int);  //�����������
    matrix(const matrix&); //���������� ����������� - ������� ����� ������� m
    int GetRow(); //����� �������� �������� ����� �����
    int GetCol(); //����� �������� �������� ����� ��������
    double& operator()(int, int); //���������� ������ ��� �������
    double operator()(int, int) const; //���������� ������ ��� �������
    matrix& operator*=(int n);
    friend istream& operator>>(istream& istr, matrix& m);//���������� ��������� �����
    friend ostream& operator<<(ostream& ostr, matrix& m);//���������� ��������� ������
    friend matrix operator+(matrix& m1, matrix& m2);//���������� ��������� ���� (��������)
    friend matrix operator-(matrix& m1, matrix& m2);//���������� ��������� ����� (��������) 
    class Vec
    {
        int vn;
        double* v;
    public:
        Vec(double*, int);
        double& operator[](const int);
    };
    Vec operator[](int) const;
    
    ~matrix(); //����������
};
#endif
