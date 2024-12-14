#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

// Default constructor
Matrix::Matrix() : array(nullptr), N(0), M(0) {}

// Parameterized constructor
Matrix::Matrix(size_t n, size_t m) : N(n), M(m) {
    array = new double* [N];
    for (size_t i = 0; i < N; ++i) {
        array[i] = new double[M]();
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& a) : N(a.N), M(a.M) {
    array = new double* [N];
    for (size_t i = 0; i < N; ++i) {
        array[i] = new double[M];
        for (size_t j = 0; j < M; ++j) {
            array[i][j] = a.array[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (size_t i = 0; i < N; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& a) {
    if (this == &a) return *this;

    for (size_t i = 0; i < N; ++i) {
        delete[] array[i];
    }
    delete[] array;

    N = a.N;
    M = a.M;

    array = new double* [N];
    for (size_t i = 0; i < N; ++i) {
        array[i] = new double[M];
        for (size_t j = 0; j < M; ++j) {
            array[i][j] = a.array[i][j];
        }
    }
    return *this;
}

// Addition operator
Matrix Matrix::operator+(const Matrix& b) {
    if (N != b.N || M != b.M) {
        throw invalid_argument("Matrix dimensions do not match for addition.");
    }
    Matrix result(N, M);
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            result.array[i][j] = array[i][j] + b.array[i][j];
        }
    }
    return result;
}

// Multiplication operator
Matrix Matrix::operator*(const Matrix& b) {
    if (M != b.N) {
        throw invalid_argument("Matrix dimensions do not match for multiplication.");
    }
    Matrix result(N, b.M);
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < b.M; ++j) {
            result.array[i][j] = 0;
            for (size_t k = 0; k < M; ++k) {
                result.array[i][j] += array[i][k] * b.array[k][j];
            }
        }
    }
    return result;
}

// Compound addition operator
Matrix& Matrix::operator+=(const Matrix& b) {
    if (N != b.N || M != b.M) {
        cout << "Warning: Dimension mismatch for += operation. Skipping operation." << endl;
        return *this;
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            array[i][j] += b.array[i][j];
        }
    }
    return *this;
}

// Compound multiplication operator
Matrix& Matrix::operator*=(const Matrix& b) {
    if (M != b.N) {
        cout << "Warning: Dimension mismatch for *= operation. Skipping operation." << endl;
        return *this;
    }
    *this = *this * b;
    return *this;
}

// Prefix increment operator
Matrix& Matrix::operator++() {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            ++array[i][j];
        }
    }
    return *this;
}

// Postfix increment operator
Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    ++(*this);
    return temp;
}

// Equality operator
bool Matrix::operator==(const Matrix& b) {
    if (N != b.N || M != b.M) {
        return false;
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (array[i][j] != b.array[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Inequality operator
bool Matrix::operator!=(const Matrix& b) {
    return !(*this == b);
}

// Output stream operator
ostream& operator<<(ostream& os, const Matrix& a) {
    for (size_t i = 0; i < a.N; ++i) {
        for (size_t j = 0; j < a.M; ++j) {
            os << setw(8) << a.array[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

// Input stream operator
istream& operator>>(istream& is, Matrix& a) {
    for (size_t i = 0; i < a.N; ++i) {
        for (size_t j = 0; j < a.M; ++j) {
            is >> a.array[i][j];
        }
    }
    return is;
}
