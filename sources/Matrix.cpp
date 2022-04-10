#include "Matrix.hpp"
#include <sstream>
#include <string>

using namespace std;
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
            throw std::runtime_error("The size must match the size of the vector inseted");
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
            throw std::runtime_error("size problem");
        }
        std::vector<double> n;
        n.resize((unsigned int)(this->row * matrix.column));
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
        int minus_1 = 1;
        for (int i = 0; i < matrix.row; i++)
        {
            COUT << '[';
            for (int j = 0; j < matrix.column; j++)
            {
                COUT << matrix.vec[(unsigned int)(matrix.column * i + j)];
                if (j < matrix.column - minus_1)
                {
                    COUT << ' ';
                }
            }
            if (i < matrix.row - minus_1)
            {
                COUT << "]" << std::endl;
            }
            else
            {
                COUT << "]";
            }
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

    Matrix operator+(Matrix &matrix)
    {
        return matrix;
    }

    std::istream &operator>>(std::istream &is, Matrix &self)
    {
        string element;
        string matend;
        int columns = -2;
        int lines = 0;
        vector<double> matrix;
        while (!is.eof())
        {
            is >> element;
            matend += " " + element;
        }

        lines = (int)count(matend.begin(), matend.end(), '[');

        for (unsigned long i = 0; i < matend.size(); i++)
        {
            if (matend[i] == ' ')
            {
                columns++;
            }
            if (matend[i] == ']')
            {
                break;
            }
        }

        // matrix_input_exeption(&matend,lines,columns);

        int sum_spaces = lines * (columns + 2);
        int sum_psiks = lines - 1;
        if (lines != (int)count(matend.begin(), matend.end(), ']'))
        {
            throw std::out_of_range{"not in format"};
        }
        int sum_spaces_between = 0;
        for (unsigned long i = 0; i < matend.size(); i++)
        {
            if (matend[i] == ' ')
            {
                sum_spaces--;
                sum_spaces_between++;
            }
            if (matend[i] == ',')
            {
                sum_psiks--;
            }
            if (i != matend.size() - 1 && matend[i] == ']' && matend[i + 1] != ',')
            {
                throw std::out_of_range{"not in format"};
            }
            if (matend[i] == ']')
            {
                if (sum_spaces_between != (columns + 2))
                {
                    throw std::out_of_range{"not in format"};
                }
                sum_spaces_between = 0;
            }
        }
        if (sum_spaces != 0 || sum_psiks != 0)
        {
            throw std::out_of_range{"not in format"};
        }

        replace(matend.begin(), matend.end(), '[', ' ');
        replace(matend.begin(), matend.end(), ']', ' ');
        replace(matend.begin(), matend.end(), ',', ' ');

        string num_in_matrix;
        stringstream stream_matrix(matend);
        while (getline(stream_matrix, num_in_matrix, ' '))
        {
            if (num_in_matrix != "\0")
            {
                try
                {
                    double num_double = stod(num_in_matrix);
                    matrix.push_back(num_double);
                }
                catch (exception &ex)
                {
                    throw std::out_of_range{"not number"};
                }
            }
        }
        self.column = columns;
        self.row = lines;
        self.vec = matrix;
        return is;
    }

}