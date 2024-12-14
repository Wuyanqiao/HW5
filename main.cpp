#include "Matrix.h"
#include <iostream>
#include <complex>

using namespace std;

// Main function to test each operator
int main() {
    size_t rowsA, colsA, rowsB, colsB;

    // Input the dimensions and elements of the first matrix
    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> rowsA >> colsA;
    Matrix A(rowsA, colsA);
    cout << "Enter the elements of the first matrix: \n";
    cin >> A;

    // Input the dimensions and elements of the second matrix
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> rowsB >> colsB;
    Matrix B(rowsB, colsB);
    cout << "Enter the elements of the second matrix: \n";
    cin >> B;

    // Test addition
    try {
        Matrix C = A + B;
        cout << "Result of A + B: \n" << C;
    }
    catch (const exception& e) {
        cout << "Addition error: " << e.what() << endl;
    }

    // Test multiplication
    try {
        Matrix D = A * B;
        cout << "Result of A * B: \n" << D;
    }
    catch (const exception& e) {
        cout << "Multiplication error: " << e.what() << endl;
    }

    // Test compound addition
    try {
        A += B;
        cout << "Result of A += B: \n" << A;
    }
    catch (const exception& e) {
        cout << "Compound addition error: " << e.what() << endl;
    }

    // Test compound multiplication
    try {
        A *= B;
        cout << "Result of A *= B: \n" << A;
    }
    catch (const exception& e) {
        cout << "Compound multiplication error: " << e.what() << endl;
    }

    // Test prefix increment
    ++A;
    cout << "Result of ++A: \n" << A;

    // Test postfix increment
    A++;
    cout << "Result of A++: \n" << A;

    // Test equality operator
    if (A == B) {
        cout << "Matrix A and B are equal." << endl;
    }
    else {
        cout << "Matrix A and B are not equal." << endl;
    }

    // Test inequality operator
    if (A != B) {
        cout << "Matrix A and B are not equal." << endl;
    }
    else {
        cout << "Matrix A and B are equal." << endl;
    }

    return 0;
}

