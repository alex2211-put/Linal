//
// Created by alik on 17.03.2020.
//

#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
};

Matrix::Matrix(int n, int m, double value[50][50])
{
    this->n = n;
    this->m = m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            this->value[i][j] = value[i][j];
};

Matrix::~Matrix()
{
    n = 0;
    m = 0;
};

void Matrix::cinValue()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> value[i][j];

};

void Matrix::setValue(int i, int j, double value)
{
    this->value[i][j] = value;
};

double Matrix::getValue(int n1, int m1) const
{
    return this->value[n1][m1];
};

int Matrix::getN() const
{
    return n;
}

int Matrix::getM() const
{
    return m;
}

Matrix Matrix::operator*(const double a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] * a;
    return Matrix(n, m, value);
};

Matrix Matrix::operator/(const double a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] / a;
    return Matrix(n, m, value);
};

Matrix Matrix::operator+(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] + a.getValue(i, j);
    return Matrix(n, m, value);
};

Matrix Matrix::operator-(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] - a.getValue(i, j);
    return Matrix(n, m, value);
};

Matrix Matrix::operator+=(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] + a.getValue(i, j);
    return Matrix(n, m, value);
};

Matrix Matrix::operator-=(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] - a.getValue(i, j);
    return Matrix(n, m, value);
};

Matrix Matrix::operator*=(const double a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] * a;
    return Matrix(n, m, value);
};

Matrix Matrix::operator/=(const double a)
{
    int n = this->n;
    int m = this->m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = this->value[i][j] / a;
    return Matrix(n, m, value);
};

Matrix Matrix::transpose(const Matrix &a)
{
    int m = this->n;
    int n = this->m;
    double value[50][50];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            value[i][j] = this->value[j][i];
    return Matrix(n, m, value);
};

Matrix Matrix::operator*(const Matrix &a)
{
    int n = this->n;
    int m = a.m;
    double value[50][50];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            double sum = 0;
            for (int k = 0; k < a.m; k++)
                sum += this->value[k][j] * a.value[i][k];
            value[i][j] = sum;
        }
    return Matrix(n, m, value);
}

std::ostream &operator<<(std::ostream &os, const Matrix &a)
{
    for (int i = 0; i < a.getN(); i++)
    {
        for (int j = 0; j < a.getM(); j++)
            os << a.getValue(i, j) << " ";
        os << std::endl;
    }

    return os;
}

std::istream &operator>>(std::istream &is, Matrix &a)
{
    for (int i = 0; i < a.getN(); i++)
        for (int j = 0; j < a.getM(); j++)
        {
            double b;
            is >> b;
            a.setValue(i, j, b);
        }
    return is;
}
