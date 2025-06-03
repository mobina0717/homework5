#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cassert>

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const std::vector<std::vector<int>>& vec);
    Matrix(const int** arr, int r, int c);
    Matrix(const Matrix& other);

    ~Matrix();

    int get_elem(int row, int col) const;
    Matrix getMatrix() const;
    int* get_row(int row) const;
    int* get_column(int col) const;
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void setElement(int row, int col, int value);
    void setRow(int row, const std::vector<int>& newRow);
    void set_column(const std::vector<int>& newCol, int col);

    Matrix& operator=(const Matrix& other);
    int& operator()(int row, int col);
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    Matrix operator*(int scalar) const;
    Matrix operator/(int scalar) const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(int scalar);

    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);

    int* operator[](int row);

    friend Matrix operator*(int scalar, const Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif // MATRIX_H
