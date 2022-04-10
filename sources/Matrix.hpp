#include <iostream>
#include <vector>
#include <stdexcept>

namespace zich
{
    class Matrix
    {
    private:
        std::vector<double> vec;
        int row;
        int column;
        double multiply_matrices(const int, const Matrix &matrix, const int);
        double sum_this_matrix() const;

    public:
        Matrix(const std::vector<double> &vec, const int row, const int column);
        Matrix operator+(const Matrix &matrix); // check
        Matrix operator+(const double);
        Matrix operator+(const int);
        Matrix &operator++();                           // check
        Matrix operator++(const int);                   // check
        Matrix &operator+=(const Matrix &other_matrix); // check

        friend istream &operator>>(std::istream &is, Matrix &this_matrix);     // check
        friend ostream &operator<<(ostream &COUT, const Matrix &matrix);       // check
        friend Matrix operator*(const double, Matrix &matrix);                 // check
        friend Matrix operator-(Matrix &matrix);                               // check
        friend Matrix operator+(Matrix &matrix);                               // check
        friend bool operator==(Matrix &matrix1, Matrix &matrix2);              // check
        friend Matrix operator*(const Matrix &matrix1, const Matrix &matrix2); // check

        Matrix operator-(const Matrix &other_matrix); // check
        Matrix operator-(const double);
        Matrix operator-(const int);
        Matrix &operator--();                           // check
        Matrix operator--(const int);                   // check
        Matrix &operator-=(const Matrix &other_matrix); // check

        bool operator>(const Matrix &matrix);  // check
        bool operator<(const Matrix &matrix);  // check
        bool operator!=(const Matrix &matrix); // check
        bool operator==(const Matrix &matrix); // check
        bool operator>=(const Matrix &matrix); // check
        bool operator<=(const Matrix &matrix); // check

        Matrix operator*(const Matrix &matrix);   // check
        Matrix operator*(const double);           // check
        Matrix &operator*=(const Matrix &matrix); // check
        Matrix &operator*=(const double);         // check

        friend std::istream &operator>>(std::istream &is, Matrix &self);
    };

};