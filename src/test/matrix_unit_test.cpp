#include <iostream>
#include "matrix/matrix.hpp"
#include "test/libtest.hpp"

using namespace std;
using namespace mtrx;

int constructor();

int main() {
    constructor();
}

int constructor() {
    /* Test all constructors of AImatrix class. */

    // Test reference:
    char* name = "constructor";
    int result = 1;

    Matrix A = Matrix(10,10);

    if (A.get_number_of_columns() != 10) 
        result = 0;

    if (A.get_number_of_rows() != 10)
        result = 0;

    unsigned long i, j;
    for(i = 0; i < A.get_number_of_rows(); ++i)
    {
        for (j = 0; j < A.get_number_of_columns(); ++j)
            A.set_matrix_value(i,j,5);
    }

    for(i = 0; i < A.get_number_of_rows(); ++i)
    {
        for (j = 0; j < A.get_number_of_columns(); ++j)
        {
            if (A.get_matrix_value(i,j) != 5)
                result = 0;
        }
    }

    print_result_test(result, name);
    return 1;
}