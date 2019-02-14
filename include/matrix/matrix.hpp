#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace mtrx {

    class Matrix {

        public:

            // Constructor:
            Matrix();

            Matrix(
                unsigned long nbRow,
                unsigned long nbColumns
            );

            Matrix(
                float values[],
                unsigned long nbRows, 
                unsigned long nbColumns
            );
            
            // Destructor:
            ~Matrix();

            // Getter section:
            unsigned long get_number_of_rows() const;
            unsigned long get_number_of_columns() const;

            float get_matrix_value(
                unsigned long line, 
                unsigned long column
            ) const;

            float get_array_value(
                unsigned long pos
            ) const;

            // Setter section:
            void set_matrix_value(
                unsigned long line, 
                unsigned long column,
                float value
            );

            // Procedur section:
            void print_matrix();

            bool size_is_equal_to(const Matrix& a);

            // Method section:
            void transpose();

            // Self operator section:
            Matrix& operator+=(const Matrix& a);
            Matrix& operator-=(const Matrix& a);
            Matrix& operator*=(const Matrix& a);

            Matrix& operator=(const Matrix& a);

        private:

            // private variable 
            unsigned long numberOfRows;
            unsigned long numberOfColumns; 

            float* matrix;
    };

    // Free operators section:
    Matrix operator+(Matrix const &a, Matrix const &b);
    Matrix operator-(Matrix const &a, Matrix const &b);
    Matrix operator*(Matrix const &a, Matrix const &b);
}

#endif 