#include "matrix.h"
#include <iostream>

Matrix::Matrix() : rows(2), cols(2) {
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    assert(r > 0 && c > 0);
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const std::vector<std::vector<int>>& vec) : rows(vec.size()), cols(vec.empty() ? 0 : vec[0].size()) {
    assert(rows > 0 && cols > 0);
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        assert(vec[i].size() == cols);
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = vec[i][j];
        }
    }
}

Matrix::Matrix(const int** arr, int r, int c) : rows(r), cols(c) {
    assert(r > 0 && c > 0);
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = arr[i][j];
        }
    }
}


Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int Matrix::get_elem(int row, int col) const {
    assert(row >= 0 && row < rows && col >= 0 && col < cols);
    return data[row][col];
}

Matrix Matrix::getMatrix() const {
    return Matrix(*this);
}

int* Matrix::get_row(int row) const {
    assert(row >= 0 && row < rows);
    int* rowData = new int[cols];
    for (int j = 0; j < cols; ++j) {
        rowData[j] = data[row][j];
    }
    return rowData;
}

int* Matrix::get_column(int col) const {
    assert(col >= 0 && col < cols);
    int* colData = new int[rows];
    for (int i = 0; i < rows; ++i) {
        colData[i] = data[i][col];
    }
    return colData;
}

void Matrix::setElement(int row, int col, int value) {
    assert(row >= 0 && row < rows && col >= 0 && col < cols);
    data[row][col] = value;
}

void Matrix::setRow(int row, const std::vector<int>& newRow) {
    assert(row >= 0 && row < rows && newRow.size() == cols);
    for (int j = 0; j < cols; ++j) {
        data[row][j] = newRow[j];
    }
}

void Matrix::set_column(const std::vector<int>& newCol, int col) {
    assert(col >= 0 && col < cols && newCol.size() == rows);
    for (int i = 0; i < rows; ++i) {
        data[i][col] = newCol[i];
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    if (rows != other.rows || cols != other.cols) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

int& Matrix::operator()(int row, int col) {
    assert(row >= 0 && row < rows && col >= 0 && col < cols);
    return data[row][col];
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

Matrix Matrix::operator*(int scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(int scalar) const {
    assert(scalar != 0);
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    assert(rows == other.rows && cols == other.cols);
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    assert(rows == other.rows && cols == other.cols);
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator*(const Matrix& other) const {
    assert(cols == other.rows);
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}


Matrix& Matrix::operator+=(const Matrix& other) {
    assert(rows == other.rows && cols == other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    assert(rows == other.rows && cols == other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    assert(cols == other.rows);
    Matrix temp = *this * other;
    *this = temp;
    return *this;
}
Matrix& Matrix::operator*=(int scalar) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] *= scalar;
        }
    }
    return *this;
}


Matrix& Matrix::operator++() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp = *this;
    ++(*this);
    return temp;
}

Matrix& Matrix::operator--() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            --data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp = *this;
    --(*this);
    return temp;
}

int* Matrix::operator[](int row) {
    assert(row >= 0 && row < rows);
    return data[row];
}

Matrix operator*(int scalar, const Matrix& matrix) {
    return matrix * scalar;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    int r, c;
    std::cout << "Enter matrix format (row column a1 a2 ...):\n";
    is >> r >> c;
    if (r != matrix.rows || c != matrix.cols) {
        std::cerr << "Error: Input dimensions do not match matrix dimensions.\n";
        return is;
    }
    std::cout << "Enter matrix elements (" << matrix.rows << "x" << matrix.cols << "):\n";
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}
