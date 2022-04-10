#include "Matrix.hpp"

namespace zich
{

    Matrix::Matrix(const std::vector<double> &vec, const int row, const int column)
    {
        if (row <= 0 || column <= 0)
        {
            throw std::runtime_error("The size must be positive");
        }
        if (row * column != vec.size())
        {
            throw std::runtime_error("The size must match the size of the vector inserter");
        }
        if (vec.empty())
        {
            throw std::runtime_error("empty");
        }

        this->vec = vec;
        this->row = row;
        this->column = column;
    }
    Matrix Matrix::operator+(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw std::runtime_error("diffrent size");
        }

        unsigned int length = (unsigned int)(row * column);
        std::vector<double> temp_vector;
        temp_vector.resize(length);
        for (unsigned int i = 0; i < length; i++)
        {
            temp_vector[i] = this->vec[i] + matrix.vec[i];
        }
        return Matrix(temp_vector, row, this->column);
    }
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int number)
    {
        Matrix duplicated = *this;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] += 1;
            }
        }
        return duplicated;
    }
    Matrix &Matrix::operator+=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw std::runtime_error("The matrices are diffrent");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] += matrix.vec[(unsigned int)(i * column + j)];
            }
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw std::runtime_error("diffrent size");
        }
        unsigned int length = (unsigned int)(row * column);
        std::vector<double> temp_vector;
        temp_vector.resize(length);
        for (unsigned int i = 0; i < length; i++)
        {
            temp_vector[i] = this->vec[i] - matrix.vec[i];
        }
        return Matrix(temp_vector, row, column);
    }
    Matrix &Matrix::operator--()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(const int number)
    {
        Matrix duplicated = *this;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] -= 1;
            }
        }
        return duplicated;
    }
    Matrix &Matrix::operator-=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw std::runtime_error("diffrent size");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] -= matrix.vec[(unsigned int)(i * column + j)];
            }
        }
        return *this;
    }

    double Matrix::multiply_matrices(const int row_param, const Matrix &matrix, const int column_param)
    {
        double sum = 0;
        for (int i = 0; i < this->column; i++)
        {
            sum += this->vec[(unsigned int)(this->column * row_param + i)] * matrix.vec[(unsigned int)(matrix.column * i + column_param)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &matrix)
    {
        if (this->column != matrix.row)
        {
            throw std::runtime_error("The sizes of the matrices do not match");
        }
        std::vector<double> n;
        Matrix newMatrix(n, row, matrix.column);
        for (int i = 0; i < newMatrix.row; i++)
        {
            for (int j = 0; j < newMatrix.column; j++)
            {
                newMatrix.vec[(unsigned int)(i * newMatrix.column + j)] = multiply_matrices(i, matrix, j);
            }
        }
        return newMatrix;
    }
    Matrix Matrix::operator*(const double a)
    {
        Matrix newMatrix = *this;
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < column; j++)
            {
                newMatrix.vec[(unsigned int)(column)*i + j] *= a;
            }
        }
        return newMatrix;
    }
    Matrix &Matrix::operator*=(const Matrix &matrix)
    {
        *this = (*this * matrix);
        return *this;
    }
    Matrix &Matrix::operator*=(const double number)
    {
        *this = (*this * number);
        return *this;
    }
    double Matrix::sum_this_matrix() const
    {
        double sum = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                sum += vec[(unsigned int)(i * (this->column) + j)];
            }
        }
        return sum;
    }
    bool Matrix::operator>(const Matrix &matrix)
    {
        return (*this).sum_this_matrix() > matrix.sum_this_matrix();
    }
    bool Matrix::operator<(const Matrix &matrix)
    {
        return (*this).sum_this_matrix() < matrix.sum_this_matrix();
    }
    bool Matrix::operator!=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            return false;
        }
        unsigned int size = (unsigned int)(row * column);
        for (unsigned int i = 0; i < size; i++)
        {
            if (this->vec[i] != matrix.vec[i])
            {
                return true;
            }
        }
        return false;
    }
    bool Matrix::operator==(const Matrix &matrix)
    {
        return !((*this) != matrix);
    }
    bool Matrix::operator>=(const Matrix &matrix)
    {
        return ((*this) > matrix) || ((*this) == matrix);
    }
    bool Matrix::operator<=(const Matrix &matrix)
    {
        return ((*this) < matrix) || ((*this) == matrix);
    }

    std::ostream &operator<<(std::ostream &COUT, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.row; i++)
        {
            COUT << '[';
            for (int j = 0; j < matrix.column; j++)
            {
                COUT << matrix.vec[(unsigned int)(matrix.column * i + j)] << " ";
            }
            COUT << "]" << std::endl;
        }
        return COUT;
    }

    Matrix operator*(const double number, Matrix &matrix)
    {
        return matrix * number;
    }
    Matrix operator-(Matrix &matrix)
    {
        return matrix *= -1;
    }
    Matrix Matrix::operator-(const double number)
    {
        return *this;
    };
    Matrix Matrix::operator-(const int number)
    {
        return *this;
    };
    Matrix Matrix::operator+(const double number)
    {
        return *this;
    };
    Matrix Matrix::operator+(const int number)
    {
        return *this;
    };

    bool operator==(const Matrix &matrix1, const Matrix &matrix2)
    {
        return true;
    };

    Matrix operator*(const Matrix &matrix1, const Matrix &matrix2)
    {
        return matrix1;
    }

    Matrix operator+( Matrix &matrix)
    {
        return matrix;
    }

    std::istream &operator>>(std::istream &is, Matrix &self)
    {
        return is;
    }

}