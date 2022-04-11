#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

namespace zich
{
    class Matrix
    {
    private:
        std::vector<double> vec_of_mat;
        size_t rows;
        size_t columns;
        double matrix_multipy_helper(const size_t, const Matrix &, const size_t);
        double get_values_sum() const;

    public:
        friend std::ostream &operator<<(std::ostream &, const Matrix &);
        friend std::istream &operator>>(std::istream &, Matrix &);
        friend Matrix operator*(const double, Matrix &);
        friend Matrix operator-(Matrix &);
        friend Matrix operator+(Matrix &);
        friend bool operator==(const Matrix &, const Matrix &);

        Matrix &operator-=(const Matrix &);
        Matrix &operator--();
        Matrix operator--(const int);
        Matrix &operator+=(const Matrix &);

        Matrix &operator++();
        Matrix operator+(const Matrix &);
        Matrix operator++(const int);

        Matrix operator-(const Matrix &);
        Matrix operator*(const Matrix &);
        Matrix operator*(const double);
        Matrix &operator*=(const Matrix &);
        Matrix &operator*=(const double);

        bool operator>(const Matrix &);
        bool operator>=(const Matrix &);
        bool operator<(const Matrix &);
        bool operator!=(const Matrix &);
        bool operator==(const Matrix &);
        bool operator<=(const Matrix &);

        void compare_size(const Matrix &) const;

        Matrix(const std::vector<double> &, const int, const int);

        
    };

    std::vector<std::string> string_to_vector(const std::string &, const char);
    std::string make_string(std::istream &);
};
