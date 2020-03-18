//
// Created by alik on 17.03.2020.
//

#ifndef LINAL_MATRIX_H
#define LINAL_MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
private:
    int n;  //количество строк
    int m;  //колиечство столбцов
    double  value[50][50];  //надеюсь, 50 хватит

public:
    Matrix(int n, int m);
    Matrix(int n, int m, double value[50][50]);
    ~Matrix();

    void cinValue();
    void setValue(int i, int j, double value);
    double getValue(int n1, int m1) const;
    int getN() const;
    int getM() const;

    Matrix operator + (const Matrix &a);
    Matrix operator - (const Matrix &a);
    Matrix operator * (const double a);
    Matrix operator / (const double a);
    Matrix operator * (const Matrix &a);

    Matrix operator += (const Matrix &a);
    Matrix operator -= (const Matrix &a);
    Matrix operator *= (const double a);
    Matrix operator /= (const double a);

    Matrix transpose(const Matrix &a);

};
std::ostream &operator << (std::ostream &os, const Matrix &a);
std::istream &operator>>(std::istream &is, Matrix &a);

#endif //LINAL_MATRIX_H
