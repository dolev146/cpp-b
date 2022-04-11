#include "Matrix.hpp"
/**
 * Demo file for the exercise on numbers with units
 *
 * @author Dolev Dublon
 * @since 2022-04
 *
 * @copyright all reserved to dolev dublon .inc
 * @warning read it in your own responcibility :)
 *
 *
 */

using namespace std;

namespace zich
{

    Matrix Matrix::operator+(Matrix const &matrix_param)
    {
        /*
         check for rows and columns first!
        */
        if (this->rows != matrix_param.rows || this->columns != matrix_param.columns)
        {
            throw runtime_error(" diffrent size ");
        }
        size_t new_size_of_vector = (rows * columns);
        vector<double> vector_to_insert;
        vector_to_insert.resize(new_size_of_vector);

        /*
        loop over and insert the values and return a new matrix
        */
        for (size_t i = 0; i < new_size_of_vector; i++)
        {
            vector_to_insert[i] = this->vec_of_mat[i] + matrix_param.vec_of_mat[i];
        }
        return Matrix(vector_to_insert, rows, columns);
    }

    Matrix &Matrix::operator+=(Matrix const &matrix_param)
    {
        /*
        now we will compare the the size first to see if operation is OK
        */
        compare_size(matrix_param);
        /*
        now we will add the matrix and insert it to this
        */
        *this = (*this) + matrix_param;
        return *this;
    }

    Matrix Matrix::operator-(Matrix const &matrix_param)
    {
        /*
        now we will compare the the size first to see if operation is OK
        */
        compare_size(matrix_param);
        /*
        now we will create a new matrix and will store the new values in it and return it
        */
        size_t new_size_of_vector = (this->rows * this->columns);
        vector<double> vec_to_store_info;
        vec_to_store_info.resize(new_size_of_vector);
        for (size_t i = 0; i < new_size_of_vector; i++)
        {
            vec_to_store_info[i] = this->vec_of_mat[i] - matrix_param.vec_of_mat[i];
        }
        return Matrix(vec_to_store_info, this->rows, this->columns);
    }

    Matrix operator*(const double matrix_param1, Matrix &matrix_param)
    {
        /*
            we are useing here a function that we already built
            Matrix Matrix::operator*(Matrix const &matrix_param)
            and returning the value
        */
        return matrix_param * matrix_param1;
    }

    Matrix &Matrix::operator--()
    {
        /*
        loop over the vector values and downgrade everything by 1
        then return this matrix :)
        */
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->columns; j++)
            {
                vec_of_mat[(i * this->columns + j)] -= 1;
            }
        }
        return *this;
    }

    Matrix &Matrix::operator-=(Matrix const &matrix_param)
    {
        /*
            now we will compare the the size first to see if operation is OK
        */
        compare_size(matrix_param);
        /*
        now we will subtract the matrix and insert it to this
        */
        *this = (*this) - matrix_param;
        return *this;
    }

    double Matrix::matrix_multipy_helper(const size_t row_param, Matrix const &matrix_param, const size_t columns_param)
    {
        /*
            lets remember how multiply works , we need to sum up the values of row cross column and
            insert it to the correct slot
            here we sum the values according to the rules of matrix multiplication :)
            and returning the values
        */
        double sum = 0;
        for (size_t i = 0; i < this->columns; i++)
        {
            sum += this->vec_of_mat[(this->columns * row_param + i)] * matrix_param.vec_of_mat[(matrix_param.columns * i + columns_param)];
        }
        return sum;
    }

    Matrix Matrix::operator*(Matrix const &matrix_param)
    {
        /*
        we only need to check for column size equals to rows of second mat
        due to the rulse of the multiplication
        */
        if (this->columns != matrix_param.rows)
        {
            throw runtime_error("diffrent size");
        }

        /*
            now we will just create a new matrix ,
            make the changes insert the new values and return the matrix :) simple
        */
        vector<double> n;
        n.resize(this->rows * matrix_param.columns);
        Matrix matrix_to_return(n, this->rows, matrix_param.columns);
        for (size_t i = 0; i < matrix_to_return.rows; i++)
        {
            for (size_t j = 0; j < matrix_to_return.columns; j++)
            {
                matrix_to_return.vec_of_mat[(i * matrix_to_return.columns + j)] = matrix_multipy_helper(i, matrix_param, j);
            }
        }
        return matrix_to_return;
    }

    Matrix Matrix::operator*(const double number_param)
    {
        /*
        here we simply need to for loop and multiply every value
        inside by the number param
        */
        Matrix matrix_to_return = *this;
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->columns; j++)
            {
                matrix_to_return.vec_of_mat[(this->columns) * i + j] *= number_param;
            }
        }
        return matrix_to_return;
    }

    Matrix &Matrix::operator*=(Matrix const &matrix_param)
    {
        /*
        here we will just use the function we already built to finish the job :)
        */
        *this = (*this * matrix_param);
        return *this;
    }

    Matrix &Matrix::operator*=(const double number_param)
    {
        /*
         here we will just use the function we already built to finish the job :)
        */
        *this = (*this * number_param);
        return *this;
    }

    double Matrix::get_values_sum() const
    {
        /*
        here we just for loop all the values and sum up
        to the variable sum
        then we return it
        */
        double sum = 0;
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->columns; j++)
            {
                sum += vec_of_mat[(i * (this->columns) + j)];
            }
        }
        return sum;
    }

    bool Matrix::operator>(Matrix const &matrix_param)
    {
        /*
        first we chack that we can make the comparision
        */
        compare_size(matrix_param);
        /*
        now we can use the comparison on the values that we sum :) using the function we wrote above
        */
        return (*this).get_values_sum() > matrix_param.get_values_sum();
    }

    bool Matrix::operator<(Matrix const &matrix_param)
    {
        /*
       first we chack that we can make the comparision
       */
        compare_size(matrix_param);
        /*
         now we can use the comparison on the values that we sum :) using the function we wrote above
        */
        return (*this).get_values_sum() < matrix_param.get_values_sum();
    }

    bool Matrix::operator!=(Matrix const &matrix_param)
    {
        /*
        first we chack that we can make the comparision
        */
        compare_size(matrix_param);
        /*
        lets just loop over the values and if a value is diffrent we can call it not equal
        */
        size_t size = (this->rows * this->columns);
        for (size_t i = 0; i < size; i++)
        {
            if (this->vec_of_mat[i] != matrix_param.vec_of_mat[i])
            {
                return true;
            }
        }
        return false;
    }

    bool Matrix::operator==(Matrix const &matrix_param)
    {
        /*
        first we chack that we can make the comparision
        */
        compare_size(matrix_param);
        /*
        now we can use the comparison on the values that we sum :) using the function we wrote above
        */
        return !((*this) != matrix_param);
    }

    bool Matrix::operator<=(Matrix const &matrix_param)
    {

        /*
        first we chack that we can make the comparision
        */
        compare_size(matrix_param);
        /*
       now we can use the comparison on the values that we sum :) using the function we wrote above
       */
        return (*this).get_values_sum() <= matrix_param.get_values_sum();
    }

    Matrix Matrix::operator--(const int number_param)
    {
        /*
        we will use the fucntion that we alerady built  and return the matrix with the finished values
        */
        Matrix matrix_to_return = *this;
        this->operator--();
        return matrix_to_return;
    }

    ostream &operator<<(ostream &COUT, Matrix const &matrix_param1)
    {
        /*
            we need to make this code work as specified from the demo

          Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size
          cout << a << endl;

           prints   [1 0 0]
                    [0 1 0]
                    [0 0 1]
        */

        // because of the test i had to add this for loop to print the last row accoring to the
        // rulse of the tests so i just changed the format because the last row i added a endl in the end
        size_t outer_index = 0;
        for (size_t i = 0; i < matrix_param1.rows - 1; i++)
        {
            // first thing we need to print open bracket [
            COUT << '[';
            for (size_t j = 0; j < matrix_param1.columns - 1; j++)
            {
                // first thing we need to print open bracket [
                COUT << matrix_param1.vec_of_mat[outer_index++] << " ";
            }
            COUT << matrix_param1.vec_of_mat[outer_index++] << "]" << '\n';
        }
        COUT << '[';
        for (size_t j = 0; j < matrix_param1.columns - 1; j++)
        {
            // now we need to add a space every value
            COUT << matrix_param1.vec_of_mat[outer_index++] << " ";
        }
        // end of every row we print closing bracket ]
        COUT << matrix_param1.vec_of_mat[outer_index++] << "]";

        return COUT;
    }

    std::string make_string(std::istream &ISTREAM)
    {
        /*
            make a string from i stream
        */
        char ch = 0;
        string s;
        while (ch != '\n')
        {
            ch = ISTREAM.get();
            s += ch;
        }
        s.pop_back();
        return s;
    }

    std::istream &operator>>(std::istream &isOUT, Matrix &mat)
    {
        vector<string> new_vector_to_string = string_to_vector(make_string(isOUT), ',');
        size_t row_size = new_vector_to_string.size();
        size_t columns_size = string_to_vector(new_vector_to_string[0], ' ').size();
        vector<double> new_vector_to_matrix;
        new_vector_to_matrix.resize(row_size * columns_size);
        size_t outer_index = 0;
        for (size_t i = 0; i < new_vector_to_string.size(); i++)
        {
            if (i > 0)
            {
                if (new_vector_to_string[i].at(0) != ' ')
                {
                    throw runtime_error("no space according to the test ");
                }
                new_vector_to_string[i].erase(0, 1);
            }
            vector<string> row_vector = string_to_vector(new_vector_to_string[i], ' ');
            if (row_vector.size() != columns_size)
            {
                throw runtime_error("rows not same size ");
            }
            if (row_vector[0].at(0) != '[' || row_vector[row_vector.size() - 1].at(1) != ']')
            {
                throw runtime_error("problem with [ ] ");
            }
            row_vector[0].erase(0, 1);
            new_vector_to_matrix[outer_index++] = stod(row_vector[0]);
            size_t j = 1;
            for (; j < row_vector.size() - 1; j++)
            {
                new_vector_to_matrix[outer_index++] = stod(row_vector[j]);
            }
            string &lastRow = row_vector[j];
            lastRow.pop_back();
            new_vector_to_matrix[outer_index++] = stod(lastRow);
        }
        mat = Matrix(new_vector_to_matrix, row_size, columns_size);
        return isOUT;
    }

    Matrix Matrix::operator++(const int flag)
    {
        /*
        we will use the fucntion that we alerady built  and return the matrix with the finished values
        */
        Matrix matrix_to_return = *this;
        this->operator++();
        return matrix_to_return;
    }

    bool Matrix::operator>=(Matrix const &matrix_param)
    {
        /*
        first we check for the good size
        */
        compare_size(matrix_param);
        /*
        now we will use functions we already build
        */
        return (*this).get_values_sum() >= matrix_param.get_values_sum();
    }

    Matrix operator-(Matrix &matrix_param1)
    {
        /*
        just change the sign of the values by using the * function that we already built
        */
        return matrix_param1 * -1;
    }

    Matrix operator+(Matrix &matrix_param1)
    {
        /*
        no change in the sign of the values
        */
        return matrix_param1;
    }

    bool operator==(Matrix const &matrix_param1, Matrix const &matrix_param)
    {
        /*
        here we will check for equal
        now we will check first the sizes
        */
        if (matrix_param1.rows != matrix_param.rows || matrix_param1.columns != matrix_param.columns)
        {
            throw invalid_argument(" not good columns and rows");
        }
        /*
    now we will compare values in the slots
        */
        for (size_t i = 0; i < matrix_param1.rows; i++)
        {
            for (size_t j = 0; j < matrix_param1.columns; j++)
            {
                if (matrix_param1.vec_of_mat[(i * matrix_param1.columns + j)] != matrix_param.vec_of_mat[(i * matrix_param1.columns + j)])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void Matrix::compare_size(Matrix const &matrix_param) const
    {
        /*
        compare size will comapre rows and cols
        */
        if (this->rows != matrix_param.rows || this->columns != matrix_param.columns)
        {
            throw runtime_error("diffrent size");
        }
    }

    vector<string> string_to_vector(const string &str, const char c)
    {
        /*
        helper function
        that helps us convert a string to vector so it is easy to resize
        */
        vector<string> res;
        res.resize(str.size());

        size_t realSize = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str.at(i) == c)
            {
                ++realSize;
            }
            else
            {
                res[realSize] += str.at(i);
            }
        }

        ++realSize;
        res.resize(realSize);
        return res;
    }

    Matrix &Matrix::operator++()
    {
        /*
        incease all values by 1
        by using for loop
        */
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                vec_of_mat[(i * columns + j)] += 1;
            }
        }
        return *this;
    }

    Matrix::Matrix(const vector<double> &vec_to_store_info, const int row_param, const int coloms_param)
    {
        /*
            constructor of the matrix , we set the values after we check validation :)
        */

        if (row_param <= 0 || coloms_param <= 0)
        {
            throw runtime_error(" negative input ");
        }

        if ((size_t)vec_to_store_info.size() != row_param * coloms_param)
        {
            throw runtime_error(" not good size vector");
        }

        this->vec_of_mat = vec_to_store_info;
        this->rows = (size_t)row_param;
        this->columns = (size_t)coloms_param;
    }
}
