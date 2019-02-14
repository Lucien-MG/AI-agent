#include <iostream>
#include "matrix/matrix.hpp"

using namespace std;
using namespace mtrx;

int test_constructor();

int main() {
    test_constructor();
}

int test_constructor() {
    /* Test all constructors of AImatrix class. */

    Matrix A = Matrix(10,10);

    if (A.get_number_of_columns() != 10)
        return 0;

    if (A.get_number_of_rows() != 10)
        return 0;

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
                return 0;
        }
    }

    cout << "[OK] test_constructor" << endl;
    return 1;
}