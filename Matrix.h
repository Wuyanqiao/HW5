//#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
using namespace std;
class Matrix {
    double** array;
    size_t N;
    size_t M;
public:
    Matrix();
    Matrix(size_t n, size_t m);
    Matrix(const Matrix& a);
    ~Matrix();
    Matrix& operator=(const Matrix& a);
    Matrix operator+(const Matrix& b);
    Matrix operator*(const Matrix& b);
    Matrix& operator+=(const Matrix& b);
    Matrix& operator*=(const Matrix& b);
    Matrix& operator++();
    Matrix operator++(int);
    bool operator==(const Matrix& b);
    bool operator!=(const Matrix& b);
    friend ostream& operator<<(ostream& os, const Matrix& a);
    friend istream& operator>>(istream& os, Matrix& a);
};
#endif

