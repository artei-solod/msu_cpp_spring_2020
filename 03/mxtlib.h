#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#ifndef	_MTXLIB_H_
#define	_MTXLIB_H_


class matrix
{
    int Row, Col;  //строки и столбцы
    double **Value;  // элементы матрицы
public:

    matrix(int, int);  //конструктор
    matrix(const matrix&); //копирующий конструктор - создает копию объекта m
    int GetRow(); //метод получает значение числа строк
    int GetCol(); //метод получает значение числа столбцов
    double& operator()(int, int); //перегрузка скобок для матрицы
    double operator()(int, int) const; //перегрузка скобок для матрицы
    matrix& operator*=(int n);
    friend istream& operator>>(istream& istr, matrix& m);//перегрузка оператора ввода
    friend ostream& operator<<(ostream& ostr, matrix& m);//перегрузка оператора вывода
    friend matrix operator+(matrix& m1, matrix& m2);//перегрузка оператора плюс (бинарный)
    friend matrix operator-(matrix& m1, matrix& m2);//перегрузка оператора минус (бинарный) 
    class Vec
    {
        int vn;
        double* v;
    public:
        Vec(double*, int);
        double& operator[](const int);
    };
    Vec operator[](int) const;
    
    ~matrix(); //деструктор
};
#endif
