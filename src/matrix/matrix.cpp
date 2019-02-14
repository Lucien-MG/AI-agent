#include <iostream>
#include "matrix/matrix.hpp"

using namespace std;
using namespace mtrx;     

// Constructor:

Matrix::
Matrix() {}

Matrix::
Matrix(unsigned long nbRows, unsigned long nbColumns) 
{
    this -> numberOfRows = nbRows;
    this -> numberOfColumns = nbColumns;

    this -> matrix = new float[nbColumns * nbRows];
}

Matrix::
Matrix(float values[], unsigned long nbRows, unsigned long nbColumns) 
{
    this -> numberOfRows = nbRows;
    this -> numberOfColumns = nbColumns;

    this -> matrix = new float[nbColumns * nbRows];

    unsigned long i, j;
    for(i = 0; i < numberOfRows; ++i)
    {
        for (j = 0; j < numberOfColumns; ++j) {
            matrix[i * numberOfColumns + j] = 
            values[i * numberOfColumns + j];
        }
    }    
}

// Destructor:

Matrix::
~Matrix() 
{
    delete[] this -> matrix;
}

// Getter section:

unsigned long Matrix::
get_number_of_rows() const
{
    return numberOfRows;
}

unsigned long Matrix::
get_number_of_columns() const
{
    return numberOfColumns;
}

float Matrix::
get_matrix_value(unsigned long line, unsigned long column) const
{
    if (line < 0 || column < 0 || line >= numberOfRows || column >= numberOfColumns)
        throw invalid_argument("get_matrix_value: invalid args");

    return matrix[line * numberOfColumns + column];
}

float Matrix::
get_array_value(unsigned long pos) const
{
    if (pos < 0 || pos >= numberOfColumns * numberOfRows)
        throw invalid_argument("get_array_value: invalid pos");

    return matrix[pos];
}

// Setter section:
void Matrix::
set_matrix_value(unsigned long line, unsigned long column, float value)
{
    if (line < 0 || column < 0 || line >= numberOfRows || column >= numberOfColumns) 
        throw invalid_argument("set_matrix_value: invalid args");

    matrix[line * numberOfColumns + column] = value;
}

// Procedur section:

void Matrix::
print_matrix()
{
    unsigned long i, j;
    for(i = 0; i < numberOfRows; ++i)
    {
        for (j = 0; j < numberOfColumns; ++j)
            cout << matrix[i * numberOfColumns + j] << " ";

        cout << endl;
    }
}

bool Matrix::
size_is_equal_to(const Matrix& a)
{
    return numberOfColumns == a.get_number_of_columns() &&
        numberOfRows == a.get_number_of_rows();
}

// Method section:

void Matrix::
transpose() {

    float swap_value;
    unsigned long swap;
    unsigned long i, j;

    for(i = 0; i < numberOfRows; ++i)
    {
        for(j = 0; j < numberOfColumns; ++j)
        {
            swap_value = this -> matrix[j * numberOfRows + i];

            this -> matrix[j * numberOfRows + i] =
            this -> matrix[i * numberOfColumns + j];

            this -> matrix[i * numberOfColumns + j] =
            swap_value;
        }
    }

    swap = numberOfRows;
    this -> numberOfRows = numberOfColumns;
    this -> numberOfColumns = swap;
}

// Self operators section:

Matrix& Matrix::
operator+=(const Matrix& a)
{
    if (!this -> size_is_equal_to(a)) 
        throw invalid_argument("Matrix size not equal.");

    unsigned long i, j;
    for(i = 0; i < numberOfRows; ++i)
    {
        for(j = 0; j < numberOfColumns; ++j)
        {
            matrix[i * numberOfColumns + j] += 
            a.get_matrix_value(i,j);
        }
    }

    return *this;
}

Matrix& Matrix::
operator-=(const Matrix& a)
{
    if (!this -> size_is_equal_to(a)) 
        throw invalid_argument("Matrix size not equal.");

    unsigned long i, j;
    for(i = 0; i < numberOfRows; ++i)
    {
        for(j = 0; j < numberOfColumns; ++j)
        {
            matrix[i * numberOfColumns + j] -= 
            a.get_matrix_value(i,j);
        }
    }

    return *this;
}

Matrix& Matrix::
operator*=(const Matrix& a)
{
    if (numberOfColumns != a.get_number_of_rows())
        throw invalid_argument("operator*=: invalid size.");

    unsigned long i, j, k, new_nbC = a.get_number_of_columns();
    float* result = new float[numberOfRows * new_nbC];
    float sum = 0.0;

    for(i = 0; i < numberOfRows; ++i)
    {
        for(j = 0; j < new_nbC; ++j)
        {
            for(k = 0; k < numberOfColumns; ++k)
                sum += matrix[i * new_nbC + k] * a.get_matrix_value(k,j);

            result[i * new_nbC + j] = sum;
            sum = 0;
        }
    }

    numberOfColumns = new_nbC;
    delete[] matrix;
    matrix = result;

    return *this;
}

Matrix& Matrix::
operator=(const Matrix& a)
{
    this -> numberOfRows = a.get_number_of_rows();
    this -> numberOfColumns = a.get_number_of_columns();

    this -> matrix = new float[numberOfColumns * numberOfRows];
    
    unsigned long i, j;
    for(i = 0; i < numberOfRows; ++i)
    {
        for(j = 0; j < numberOfColumns; ++j)
        {
            matrix[i * numberOfColumns + j] = 
            a.get_matrix_value(i,j);
        }
    }

    return *this;
}

// Free operators section:

Matrix 
mtrx::operator+(Matrix const &a, Matrix const &b)
{
    Matrix r;
    r = a;
    r += b;
    return r;
}

Matrix 
mtrx::operator-(Matrix const &a, Matrix const &b)
{
    Matrix r;
    r = a;
    r -= b;
    return r;
}

Matrix 
mtrx::operator*(Matrix const &a, Matrix const &b)
{
    Matrix r;
    r = a;
    r *= b;
    return r;
}
