#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#ifndef	_MTXLIB_H_
#define	_MTXLIB_H_


class Matrix
{
    size_t Row, Col;  //строки и столбцы
    double **Value;  // элементы матрицы
public:

    Matrix(size_t, size_t);  //конструктор
    Matrix(const Matrix&); //копирующий конструктор - создает копию объекта m
    size_t GetRow(); //метод получает значение числа строк
    size_t GetCol(); //метод получает значение числа столбцов
    double& operator()(size_t, size_t); //перегрузка скобок для матрицы
    double operator()(size_t, size_t) const; //перегрузка скобок для матрицы
    Matrix& operator*=(size_t n);
    friend istream& operator>>(istream& istr, Matrix& m);//перегрузка оператора ввода
    friend ostream& operator<<(ostream& ostr, Matrix& m);//перегрузка оператора вывода
    friend Matrix operator+(Matrix& m1, Matrix& m2);//перегрузка оператора плюс (бинарный)
    friend Matrix operator-(Matrix& m1, Matrix& m2);//перегрузка оператора минус (бинарный) 
    class Vec
    {
        size_t vn;
        double* v;
    public:
        Vec(double*, size_t);
        double& operator[](const size_t);
    };
    Vec operator[](size_t) const;
    
    ~Matrix(); //деструктор
};
#endif
